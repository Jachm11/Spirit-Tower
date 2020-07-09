#pragma once

#include "piso.h"


class Juego
{
public:

	Piso* pisos[5];

	int* puntajes[5];

	Jugador jugador;

	int pisoActual;

	int Matriz1[25][25];

	int Matriz2[25][25];

	int Matriz3[25][25];

	int Matriz4[25][25];

	int Matriz5[25][25];

	Juego();
	
	void generatePiso(int piso);

	void setPlayerPos(string pos);

	void playerHealed();

	void playerHit();

	void playerDied();

	void playerVisible();

	void playerInvisible();

	void chestOpened();

	void enemyKilled(int ID);

	string askEnemyRoute();

	string askEnemyStats();

private:

	int puntaje;

	void setMatrix();

	void setPuntajes();

};

