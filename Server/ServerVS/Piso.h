#pragma once
#include "Espectro.h"
#include "Jugador.h"
#include "Genetic.h"

class Piso
{

public:

	int puntajeDePiso;
	int puntajeJugador;
	int muertes;
	std::vector <Espectro> espectros;
	
	//Constructores

	Piso();
	Piso(string E1, string E2, string E3, int puntajeMax);
	Piso(string E1, string E2, string E3, int puntajePasado, int MuertesPasadas, Jugador j, std::vector <Espectro> pastGen, int puntajeMax);
	Piso(bool boss);

	//Puntos

	void updatePuntaje(int puntos);

	//Jugador

	void jugadorMuere();

	//Espectros

	void EspectroMurio(int ID);
	void EspectroVio(int ID);
	void EspectroMato(int ID);

private:

	float getRandomStat();

	vector<float> getGeneticStat(std::vector <Espectro> pastGen, int puntajePasado, int muertesPasadas, Jugador j);

};

