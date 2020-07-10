#include "Piso.h"


Piso::Piso(string E1, string E2, string E3, int puntajeMax) {

	puntajeJugador = 0;
	muertes = 0;
	espectros;
	puntajeDePiso = puntajeMax;


	for (int i = 0; i < 3; i++) {

		Espectro newEspectro;
		if (i == 0) {
			//newEspectro = Espectro(E1);
		}
		else if (i == 1) {
			///newEspectro = Espectro(E2);
		}
		else if (i == 2) {
			//newEspectro = Espectro(E3);
		}
		//newEspectro.setStats(getRandomStat(), getRandomStat(), getRandomStat());
		espectros.push_back(newEspectro);
	}

}

Piso::Piso(bool boss)
{

	puntajeJugador = 0;
	muertes = 0;
	espectros;
	puntajeDePiso;
}

Piso::Piso(string E1, string E2, string E3, int puntajePasado, int MuertesPasadas, Jugador j, std::vector <Espectro> pastGen, int puntajeMax)
{
	puntajeJugador = 0;
	muertes = 0;
	espectros;
	puntajeDePiso = puntajeMax;

	Espectro newEspectro;

	for (int i = 0; i < 3; i++) {

		if (i == 0) {
			//newEspectro = Espectro(E1);
		}
		else if (i == 1) {
			//newEspectro = Espectro(E2);
		}
		else if (i == 2) {
			//newEspectro = Espectro(E3);
		}
		float* stats = getGeneticStat(pastGen,puntajePasado,MuertesPasadas,j);
		//newEspectro.setStats( stats[0], stats[1], stats[2]);
		espectros.push_back(newEspectro);
	}

}

void Piso::updatePuntaje(int puntos)
{
	puntajeJugador += puntos;
}

void Piso::jugadorMuere()
{
	muertes++;
	puntajeJugador = 0;
	//Talvez hay que llamar a otro metodo de espectro
}

void Piso::EspectroMurio(int ID)
{
	espectros.at(ID).defeats++;
	//Talvez hay que llamar a otro metodo de espectro
}

float Piso::getRandomStat()
{

	float RStat = 1.5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.2 - 1.5)));
	std::cout << "Stat aleatorio de 1.5 a 2.2 es: " << RStat << std::endl;
	return RStat;
}

float* Piso::getGeneticStat(std::vector <Espectro> pastGen, int puntajePasado, int muertesPasadas, Jugador j)
{

	int vidaPorc = ((j.corazones) / 5) * 100;

	int puntajePorc = (puntajePasado / puntajeDePiso) * 100; 

	Genetic genetic;

	std::cout << "El % de vida con las que termino el jugar el piso es: " << vidaPorc << std::endl;

	return genetic.getGenes(pastGen, muertesPasadas, puntajePorc, vidaPorc);
}

