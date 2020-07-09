#pragma once
#include "Espectro.h"
#include "Jugador.h"

class Piso
{

public:

	int puntajeJugador;
	int muertes;
	Espectro espectros[3];
	
	Piso();

	Piso(bool);

	Piso(int puntTotal, int puntajePasado, int MuertesPasadas, Jugador *j);

	void updatePuntaje(int puntos);

	void updateMuertes();

	void EspectroMurio(int ID);

};

