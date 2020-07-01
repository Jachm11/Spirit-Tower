#pragma once
#include <ws2tcpip.h>
#include <winsock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

#define MAX_BUFFER_SIZE (49152)

class TCPListener;

typedef void (*MessageRecievedHandler)(TCPListener* listener, int socketId, std::string msg);

///
/// @brief Clase que inicializa un servidor con Windows socket TCP.
///
///
///
class TCPListener {

public:

    TCPListener(std::string ipAddress, int port, MessageRecievedHandler handler);

    ~TCPListener();

    //Send a message to the specifed client
    void Send(int clientSocket, std::string msg); //Mayuscula para evitar conflicto con winsock

    //Initialize winsock
    bool Init();

    //The main processing loop
    void Run();

    //Cleanup
    void cleanup();

    //Recieve Loop
    //Send back message
    //Cleanup

private:

    //Create a socket
    SOCKET CreateSocket();

    //Wait for connection
    //SOCKET waitForConnection(SOCKET listening);

    std::string m_ipAddress;
    int m_port;
    MessageRecievedHandler MessageReceived;


};

