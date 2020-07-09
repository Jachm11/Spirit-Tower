// ServerVS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "TCPListener.h"
#include "Juego.h"

using namespace std;

#define MAX_PLAYERS 4;


void Listener_MessageReceived(TCPListener* listener, int client, string msg);
Jugador j(5.2, 5.2);
//std::vector<Juego*> MisClientes = std::vector<Juego*>(4);

Juego *MisClientes[4];
int capacity = 0;
int cupos[] = { 0,0,0,0 };
int clientes[] = { -1,-1,-1,-1 };
bool full = false;

int main()
{
    TCPListener server("127.0.0.1", 54010, Listener_MessageReceived);

    if (server.Init()) {
        server.Run();
    }

}

int checkForSpace() {

    int space = -1;
    for (int i = 0; i < 4; i++) {
        if ( cupos[i] == 0) {
            space = i;
            cupos[i] = 1;
            return space;
        }
    }
    return space;
}

int setNewClient(int client) {

    int space = checkForSpace();
    clientes[space] = client;
    capacity++;
    Juego *juego = new Juego;
    MisClientes [space] = juego;
    if (capacity == 4) { full = true; };
    cout << "New client set" << endl;
    return space;
        
}

int idRecon(int client) {
    int id = -1;
    for (int i = 0; i < 4; i++) {
        if (client == clientes[i]) {
            id = i;
            return id;
        }
    }
    return id;

}

void cleanClient(int ID) {

    capacity--;
    clientes[ID] = 0;
    MisClientes[ID] = nullptr;
    cupos[ID] = 0;
    full = false;


}

//Esta funcion se va a encargar de manejar las respuestas del servidor.
void Listener_MessageReceived(TCPListener* listener, int client, string msg)
{
    

    string res;
    int ID;

    ID = idRecon(client);

    if (full) {
        if (ID == -1) {
            res = "El servidor esta lleno, intentelo mas tarde";
            listener->Send(client, res);
            return;
        }
    }
    else {
        if (ID == -1) {
            ID = setNewClient(client);
        }
    }

    Juego *juegoCliente;

    juegoCliente = MisClientes[ID];
    
    //int key = atoi(msg.c_str());

    // Cada bloque de else if sera una peticion distinta para el servidor. Estas funciones para definir res van a estar ligas a clases.

    //ahora cada llamada se hace juegoCliente->funcionQueQuiera();
    //Si hay que agregar una nueva se agrega en la clase juego. :D
    if (msg == "1") {
        res = "Salvete amicus!";
    }
    else if (msg == "2") {
        res = "Ualete!";
    }
    else if (msg == "AS") { //listo
        res = to_string(j.ataqueSimple());
        
    }
    else if (msg == "PI") { //lsito
        j.setSafe(true);
        res = "El personaje ahora es invisible!";
    }
    else if (msg == "PV") { //listo
        j.setSafe(false);
        res = "El personaje ahora es visible!";
    }
    else if (msg == "OPD") {
        res = "Un jarron ha sido destruido!";
    }
    else if (msg == "muerte") { //listo
        j.setMuerte();
        res = "El jugador ha muerto";
    }
    else if (msg == "OCO") { //lsito
        res = "Un cofre ha sido abierto!";
    }
    else if (msg == "P+1") { // listo
        int vida = j.aumentarCorazon();
        res = "El jugador ha ganado un corazon! Ahora tiene " + to_string(vida) + " corazones!";
    }
    else if (msg == "E1") {
        res = "Espectro derrotado!";
    }
    else if (msg == "E2") {
        res = "Espectro derrotado!";
    }
    else if (msg == "E3") {
        res = "Espectro derrotado!";
    }


    else if (msg == "Desconectado") {
        cleanClient(ID);
        res = "Espacio liberado";
    }

    else {
        //j.setPos(msg);  //lsito
        res = "19,15;19,14;19,13;19,12;19,11;19,10;19,9;19,8;19,7;20,6;20,5;21,4;21,3;19,15;19,14;19,13;19,12;19,11;19,10;19,9;19,8;19,7;20,6;20,5;21,4;21,3";
       
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
