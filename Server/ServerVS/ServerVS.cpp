#include <iostream>
#include <string>
#include "TCPListener.h"
#include "Juego.h"
using namespace std;

void Listener_MessageReceived(TCPListener* listener, int client, string msg);

Juego *MisClientes[4];
int capacity = 0;
int cupos[] = { 0,0,0,0 };
int clientes[] = { -1,-1,-1,-1 };
bool full = false;

int main()
{
    srand(time(NULL));
    TCPListener server("127.0.0.1", 54010, Listener_MessageReceived);

    if (server.Init()) {
        server.Run();
    }

}

//     ______________________
//____/Funciones de servidor


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
    Juego *juego = new Juego();
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

    Juego* juegoCliente;

    juegoCliente = MisClientes[ID];

    //        ________________
    //_______/Server API

    //_________________________
    // Generacion de pisos
    if (msg == "1") {
        juegoCliente->generatePiso(1);
        res = "Generando piso 1";
    }
    else if (msg == "2") {
        juegoCliente->generatePiso(2);
        res = "Generando piso 2";
    }
    else if (msg == "3") {
        juegoCliente->generatePiso(3);
        res = "Generando piso 3";
    }
    else if (msg == "4") {
        juegoCliente->generatePiso(4);
        res = "Generando piso 4";
    }

    else if (msg == "5") {
        juegoCliente->generatePiso(5);
        res = "Generando piso final!";
    }

    //_________________________
    // Llamadas de jugador
    else if (msg == "AS") {
        res = to_string(juegoCliente->playerHit());
        
    }
    else if (msg.substr(0, 3) == "pos") {
        juegoCliente->setPlayerPos(msg);
        res = "Posicion actualizada";
    }
    else if (msg == "PI") {
        juegoCliente->playerInvisible();
        res = "El personaje ahora es invisible!";
    }
    else if (msg == "PV") { 
        juegoCliente->playerVisible();
        res = "El personaje ahora es visible!";
    }
    else if (msg == "muerte") {
        juegoCliente->playerDied();
        res = "El jugador ha muerto";
    }
    else if (msg == "P+1") {
        int vida = juegoCliente->playerHealed();
        res = "El jugador ha ganado un corazon! Ahora tiene " + to_string(vida) + " corazones!";
    }
    else if (msg == "safe") {
        res = juegoCliente->playerState();

    }

    //_________________________
    //LLamadas de objetos
    else if (msg == "OPD") {
        res = "Un jarron ha sido destruido!";
    }
    
    else if (msg == "OCO") {
        juegoCliente->chestOpened();
        res = "Un cofre ha sido abierto!";
    }
    else if (msg[0] == 'L') {
        int pointCode = atoi(&(msg[1]));
        int points = pointCode * 10;
        juegoCliente->pointsEarned(points);
        res = "Se han obtendo "+to_string(points)+"puntos!";
    }
    else if (msg == "MOB") {
        res = "Un enemigo simple ha sido derrotado!";
    }

    //________________________
    //Lamadas de enemigo

    else if (msg[0] == 'E') {

        int ID = atoi(&(msg[1]));
        if (msg[2] == 'D')
        {
            //getDefaultResponse
            res = juegoCliente->defaultResponse(ID);
            
        }
        else if (msg[2] == 'S')
        {
            //getStatsResponse
            res = juegoCliente->statsResponse(ID);
        }
        else if(msg[2] == 'A')
        {
            //getAttackResponse
            res = juegoCliente->attackResponse(ID, msg.substr(3));

        }
        else if (msg[2] == 'B')
        {
            //getBacktrackResponse
            res = juegoCliente->backtrackResponse(ID);
        }
        else if (msg[2] == 'M')
        {
            //Enemy was killed
            juegoCliente->enemyDied(ID);
            res = "Enemigo derrotado!";
        }
        else if (msg[2] == 'V')
        {
            //Enemy spoted the player
            juegoCliente->enemyDetected(ID);
            res = "El jugador a sido detectado!";
        }
        else if (msg[2] == 'K')
        {
            //Enemy killed the player
            juegoCliente->enemyKilled(ID);
            res = "El jugador a sido asesinado por un espectro!";
        }
        else
        {
            //addBacktrackPos
            juegoCliente->backtrackPos(ID,msg.substr(2));
            res = "Espectro " + to_string(ID) + " en movimiento";
        }
    }

    //______
    //Otros
    else if (msg == "Desconectado") {
        cleanClient(ID);
        res = "Espacio liberado";
    }
        
    else {
        res = "res";
    }

    cout << "Respondiendo: " << res << endl;
    listener->Send(client, res);
}