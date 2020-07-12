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
class TCPListener {

public:

 
    /// @brief Constructor de la clase
    /// @param ipAddress IP al que escuchar
    /// @param port Puerto al que conectarse
    /// @param handler Manejador de mensajes
    /// @return TCPListener instance
    TCPListener(std::string ipAddress, int port, MessageRecievedHandler handler);

    ~TCPListener();

    /// @brief Send a message to the specifed client
    /// @param clientSocket Numero de cliente
    /// @param msg Mesaje a enviar
    void Send(int clientSocket, std::string msg); //Mayuscula para evitar conflicto con winsock

 
    /// @brief Initialize winsock
    /// @return True si fue exitoso
    bool Init();

    /// @brief The main processing loop
    void Run();


    /// @brief Cleanup winsock
    void cleanup();


private:

    std::string m_ipAddress;
    int m_port;
    MessageRecievedHandler MessageReceived;

    /// @brief Create a socket
    /// @return  El socket creado
    SOCKET CreateSocket();


};

