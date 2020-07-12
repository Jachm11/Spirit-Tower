#include "TCPListener.h"
#include <iostream>

TCPListener::TCPListener(std::string ipAddress, int port, MessageRecievedHandler handler)
    : m_ipAddress(ipAddress), m_port(port), MessageReceived(handler) //Inicializar las variables
{

}


TCPListener::~TCPListener() {
    cleanup();
}

//Send a message to the specifed client
void TCPListener::Send(int clientSocket, std::string msg) {
    send(clientSocket, msg.c_str(), msg.size() + 1, 0);

}

//Initialize winsock
bool TCPListener::Init() {
    WSAData data;
    WORD ver = MAKEWORD(2, 2);

    int wsInit = WSAStartup(ver, &data);

    return wsInit == 0;
}

//The main processing loop
void TCPListener::Run() {

    char buf[MAX_BUFFER_SIZE];

        //Create a listening socket
        SOCKET listening = CreateSocket();
        if (listening == INVALID_SOCKET) {
            std::cout << "Error al inicializar el servidor :(" << std::endl;
        }
        else {

            std::cout << "Server Iniciado correctamente en puerto: " << m_port << std::endl;

            fd_set master;

            FD_ZERO(&master);

            FD_SET(listening,  &master);

            do {
                fd_set copy = master;

                int socketCount = select(0, &copy, nullptr, nullptr, nullptr);

                for (int i = 0; i < socketCount; i++) {
                    SOCKET sock = copy.fd_array[i];
                    if (sock == listening) {
                        //accept a new connection
                        SOCKET client = accept(listening, nullptr, nullptr);
                        //Add de new connection to the masted fd
                        FD_SET(client,  &master);

                        std::cout << "Nuevo cliente " << client << ", se ha conectado al servidor!" << std::endl;

                        std::string wlc = "Bievenido al servidor!";

                        //send(client, wlc.c_str(), wlc.size() + 1, 0);
                    }
                    else {
                        int bytesIn = recv(sock, buf, MAX_BUFFER_SIZE, 0);
                        if (bytesIn <= 0) {
                            std::cout << "Cliente " << sock << ", se ha desconectado al servidor!" << std::endl;
                            MessageReceived(this, sock, "Desconectado");
                            closesocket(sock);
                            FD_CLR(sock,  &master);

                            

                        }
                        else {
                            if (MessageReceived != NULL) {
                                std::cout << "Cliente " << sock << ", dice: " << std::string(buf, 0, bytesIn) << std::endl;
                                MessageReceived(this, sock, std::string(buf, 0, bytesIn));
                            }

                        }

                    }
                }

            } while (true);
        }
}

//Cleanup
void TCPListener::cleanup() {
    WSACleanup();
}

//Create a socket
SOCKET TCPListener::CreateSocket() {
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening != INVALID_SOCKET) {
        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(m_port);
        inet_pton(AF_INET, m_ipAddress.c_str(), &hint.sin_addr);

        int bindOk = bind(listening, (sockaddr*)&hint, sizeof(hint));
        if (bindOk != SOCKET_ERROR)
        {
            int listenOk = listen(listening, SOMAXCONN);
            if (listenOk == SOCKET_ERROR) {
                return -1;
            }
        }
        else {
            return -1;
        }
    }
    return listening;
}
