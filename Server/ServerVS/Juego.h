#pragma once

#include "piso.h"


class Juego
{
public:

	Piso* pisos[5];

	int* puntajes[5];

	Jugador jugador;

	std::vector<string> rutas;

	int pisoActual;

	int Matriz1[25][25];

	int Matriz2[25][25];

	int Matriz3[25][25];

	int Matriz4[25][25];

	int Matriz5[25][25];

	Juego();
	
	void generatePiso(int piso);

	void setPlayerPos(string pos);

	int playerHealed();

	int playerHit();

	void playerDied();

	void playerVisible();

	void playerInvisible();

	void chestOpened();

	void enemyKilled(int ID);

	void askEnemyRoute(int ID);

	void enemyStop(int ID);

	string askEnemyStats();

	//Funciones del enemigo
	string defaultResponse(int ID);
	string statsResponse(int ID);
	string attackResponse(int ID, string pos);
	string backtrackResponse(int ID);
	void backtrackPos(int ID, string pos);

	
	
	
	

private:

	int puntaje;

	int muertes;

	void setMatrix();

	void setPuntajes();

	void setRutas();


};

