// ServerVS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "TCPListener.h"

using namespace std;

void Listener_MessageReceived(TCPListener* listener, int client, string msg);

int main()
{

    TCPListener server("127.0.0.1", 54010, Listener_MessageReceived);

    if (server.Init()) {
        server.Run();
    }

}

//Esta funcion se va a encargar de manejar las respuestas del servidor.
void Listener_MessageReceived(TCPListener* listener, int client, string msg)
{
    int key = atoi(msg.c_str());

    string res;


    // Cada bloque de else if sera una peticion distinta para el servidor. Estas funciones para definir res van a estar ligas a clases.
    if (key == 1) {
        res = "Salvete amicus!";
    }
    else if (key == 2) {
        res = "Ualete!";
    }
    else if (msg == "algo") {
        //res = funcionX();
        res = "Asi no funca";
    }
    else {
        res = msg;
    }
    cout << "Respondiendo: " << res << endl;
    listener->Send(client, res);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
