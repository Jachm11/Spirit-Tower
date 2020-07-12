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
	//Espectro espectros[3];
	//Espectro Carl;
	//Espectro David;
	//Espectro Loraine;
	std::vector <Espectro> espectros;
	
	Piso() {};

	Piso(string E1, string E2, string E3, int puntajeMax);

	Piso(bool boss);

	Piso(string E1, string E2, string E3, int puntajePasado, int MuertesPasadas, Jugador j, std::vector <Espectro> pastGen, int puntajeMax);

	void updatePuntaje(int puntos);

	void jugadorMuere();

	void EspectroMurio(int ID);
	void EspectroVio(int ID);
	void EspectroMato(int ID);

private:

	float getRandomStat();

	vector<float> getGeneticStat(std::vector <Espectro> pastGen, int puntajePasado, int muertesPasadas, Jugador j);

};

