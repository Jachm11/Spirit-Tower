#include "Piso.h"
#include <algorithm>


Piso::Piso(string E1, string E2, string E3, int puntajeMax) {

	puntajeJugador = 0;
	muertes = 0;
	//Carl;
	//David;
	//Loraine;
	puntajeDePiso = puntajeMax;


	for (int i = 0; i < 3; i++) {

		if (i == 0) {
			cout << "Ruta 0 en piso:" << E1 << endl;
			Espectro newEspectro = Espectro (E1);
			newEspectro.setStats(getRandomStat(), getRandomStat(), getRandomStat());
			espectros.push_back(newEspectro);
			//Carl = newEspectro;
			//espectros[0] = newEspectro;

		}
		else if (i == 1) {
			Espectro newEspectro = Espectro(E2);
			newEspectro.setStats(getRandomStat(), getRandomStat(), getRandomStat());
			espectros.push_back(newEspectro);
			//David = newEspectro;
			//espectros[1] = newEspectro;
		}
		else if (i == 2) {
			Espectro newEspectro = Espectro(E3);
			newEspectro.setStats(getRandomStat(), getRandomStat(), getRandomStat());
			espectros.push_back(newEspectro);
			//Loraine = newEspectro;
			//espectros[2] = newEspectro;
		}
		
	}

}

Piso::Piso(bool boss)
{

	puntajeJugador = 0;
	muertes = 0;
	//espectros;
	puntajeDePiso;
}

Piso::Piso(string E1, string E2, string E3, int puntajePasado, int MuertesPasadas, Jugador j, std::vector <Espectro> pastGen, int puntajeMax)
{
	puntajeJugador = 0;
	muertes = 0;
	espectros;
	puntajeDePiso = puntajeMax;

	//Espectro newEspectro;

	//vector<float> stats0 = getGeneticStat(pastGen, puntajePasado, MuertesPasadas, j);
	//vector<float> stats1 = getGeneticStat(pastGen, puntajePasado, MuertesPasadas, j);
	//vector<float> stats2 = getGeneticStat(pastGen, puntajePasado, MuertesPasadas, j);

	for (int i = 0; i < 3; i++) {


		if (i == 0) {
			//newEspectro = Espectro(E1);
			Espectro newEspectro = Espectro(E1);
			vector<float> stats = getGeneticStat(pastGen, puntajePasado, MuertesPasadas, j);
			newEspectro.setStats(stats[0], stats[1], stats[2]);
			espectros.push_back(newEspectro);
		}
		else if (i == 1) {
			Espectro newEspectro = Espectro(E2);
			vector<float> stats = getGeneticStat(pastGen, puntajePasado, MuertesPasadas, j);
			newEspectro.setStats(stats[0], stats[1], stats[2]);
			espectros.push_back(newEspectro);
		}
		else if (i == 2) {
			Espectro newEspectro = Espectro(E3);
			vector<float> stats = getGeneticStat(pastGen, puntajePasado, MuertesPasadas, j);
			newEspectro.setStats(stats[0], stats[1], stats[2]);
			espectros.push_back(newEspectro);
		}
		//float* stats = getGeneticStat(pastGen,puntajePasado,MuertesPasadas,j);  //IMPORTANTWE
		//newEspectro.setStats( stats[0], stats[1], stats[2]);
		//espectros.push_back(newEspectro);
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
	//espectros.at(ID).defeats++;
	espectros[ID].defeats++;
	//Talvez hay que llamar a otro metodo de espectro
}

void Piso::EspectroVio(int ID)
{
	espectros[ID].detections++;
}

void Piso::EspectroMato(int ID)
{
	espectros[ID].hits++;
}


float Piso::getRandomStat()
{

	float RStat = 1.5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.2 - 1.5)));
	std::cout << "Stat aleatorio de 1.5 a 2.2 es: " << RStat << std::endl;
	return RStat;
}

std::vector<float> Piso::getGeneticStat(std::vector <Espectro> pastGen, int puntajePasado, int muertesPasadas, Jugador j)
{

	int vidaPorc = ((j.corazones) / 5) * 100;

	int puntajePorc = (puntajePasado / puntajeDePiso) * 100; 

	Genetic genetic = Genetic();

	std::cout << "El % de vida con las que termino el jugar el piso es: " << vidaPorc << std::endl;

	return genetic.getGenes(pastGen, muertesPasadas, puntajePorc, vidaPorc);
}

