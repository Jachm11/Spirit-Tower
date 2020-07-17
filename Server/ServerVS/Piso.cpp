#include "Piso.h"
#include <algorithm>


Piso::Piso(){}

Piso::Piso(string E1, string E2, string E3, int puntajeMax) {

	puntajeJugador = 0;
	muertes = 0;
	puntajeDePiso = puntajeMax;


	for (int i = 0; i < 3; i++) {

		if (i == 0) {
			Espectro newEspectro = Espectro (E1);
			newEspectro.setStats(getRandomStat(0), getRandomStat(1), getRandomStat(2));
			espectros.push_back(newEspectro);


		}
		else if (i == 1) {
			Espectro newEspectro = Espectro(E2);
			newEspectro.setStats(getRandomStat(0), getRandomStat(1), getRandomStat(2));
			espectros.push_back(newEspectro);
		}
		else if (i == 2) {
			Espectro newEspectro = Espectro(E3);
			newEspectro.setStats(getRandomStat(0), getRandomStat(1), getRandomStat(2));
			espectros.push_back(newEspectro);
		}
		
	}

}

Piso::Piso(int cofres)
{
	cofresPlayer = cofres;
	puntajeJugador = 0;
	muertes = 0;

}

Piso::Piso(string E1, string E2, string E3, int puntajePasado, int MuertesPasadas, Jugador j, std::vector <Espectro> pastGen, int puntajeMax, int cofres)
{
	puntajeJugador = 0;
	muertes = 0;
	espectros;
	puntajeDePiso = puntajeMax;
	cofresPlayer = cofres;

	for (int i = 0; i < 3; i++) {

		if (i == 0) {
			Espectro newEspectro = Espectro(E1);
			vector<float> stats = getGeneticStat(pastGen, puntajePasado, MuertesPasadas, j);
			newEspectro.setStats(stats[0], stats[2], stats[1]);
			espectros.push_back(newEspectro);
		}
		else if (i == 1) {
			Espectro newEspectro = Espectro(E2);
			vector<float> stats = getGeneticStat(pastGen, puntajePasado, MuertesPasadas, j);
			newEspectro.setStats(stats[0], stats[2], stats[1]);
			espectros.push_back(newEspectro);
		}
		else if (i == 2) {
			Espectro newEspectro = Espectro(E3);
			vector<float> stats = getGeneticStat(pastGen, puntajePasado, MuertesPasadas, j);
			newEspectro.setStats(stats[0], stats[2], stats[1]);
			espectros.push_back(newEspectro);
		}
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
}

void Piso::EspectroMurio(int ID)
{
	espectros[ID].defeats++;
}

void Piso::EspectroVio(int ID)
{
	espectros[ID].detections++;
}

void Piso::EspectroMato(int ID)
{
	espectros[ID].hits++;
}

float Piso::getRandomStat(int i)
{
	if (i == 0) {
		//velocidad
		float RStat = 2.3 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (3.3 - 2.5)));
		std::cout << "Stat aleatorio de velocidad de 3.3 a 2.5 es: " << RStat << std::endl;
		return RStat;
	}
	else if (i == 2) {
		//persecucion
		float RStat = 1.5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.2 - 1.5)));
		std::cout << "Stat aleatorio de persecusion  1.5 a 2.2 es: " << RStat << std::endl;
		return RStat;
	}
	else {
		//radio
		float RStat = 2.9 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (3.8 - 2.9)));
		std::cout << "Stat aleatorio de radio 3.8 a 2.9 es: " << RStat << std::endl;
		return RStat;
	}
}

std::vector<float> Piso::getGeneticStat(std::vector <Espectro> pastGen, int puntajePasado, int muertesPasadas, Jugador j)
{

	int vidaPorc = ((j.corazones) / 5) * 100;

	int puntajePorc = (puntajePasado / puntajeDePiso) * 100; 

	Genetic genetic = Genetic();

	std::cout << "El % de vida con las que termino el jugar el piso es: " << vidaPorc << std::endl;

	return genetic.getGenes(pastGen, muertesPasadas, puntajePorc, vidaPorc);
}

