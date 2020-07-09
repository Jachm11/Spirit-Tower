#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include "Espectro.h"



///
/// @brief Esta clase se encarga de ejecutar los procesos necesarios para el algoritmo genetico en los espectros
///
class Genetic
{

public:

	Genetic();


	/// @brief Esta funcion ejecuta un ciclo del algoritmo genetico y retorna valores para la siguente generacion de espectros
	/// @param Members Un vector de tipo espectros con la generacion de espectros de un piso 
	/// @param muertes Cantidad de veces que murio el jugador en el piso
	/// @param puntaje int de 0 a 100 que representa el porcetaje del puntaje total adquirido del piso
	/// @param vida int de 0 a 100 que representa el porcentaje de la vida restante del jugador
	/// @return Retorna un puntero a una lista con los 3 datos para un nuevo espectro
	float* getGenes(std::vector<Espectro> Members, int muertes, int puntaje, int vida);


private:

	int MutationRate;
	Population Popul;
	int totalDetections = 0;
	int totalHits = 0;
	int totalDefeats = 0;


	/// @brief Calcula el fitness relativo, a los otros miembros de la generacion, para un espectro.
	/// @param detections Cantidad de detecciones que realizo el espectro
	/// @param hits Cantidad de golpes que asesto el espectro
	/// @param defeats Cantidad de veces que el jugador derroto al espectro
	/// @return Retorna un int de 0 a 100 evaluando el fitness del espectro relativo a los otros espectros de la generacion
	int EnemyFitness(float detections, float hits, float defeats);


	/// @brief Calcula un numero de 0 40 basandose en el desempleño del jugador. Este numero indica que tan pronunciada seria la mutacion aleatoria de un espectro
	/// @param muertes Cantidad de veces que murio el jugador en el piso
	/// @param puntaje int de 0 a 100 que representa el porcetaje del puntaje total adquirido del piso
	/// @param vidas int de 0 a 100 que representa el porcentaje de la vida restante del jugador
	/// @return  Un numero de 0 a 40 que seria del porcentaje maximo en el que la mutacion toma efecto
	float maxToMutate(int muertes, int puntaje, int vidas);


};



