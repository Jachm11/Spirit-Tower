#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include "Espectro.h"


class Genetic
{

public:

	Genetic();

	float* getGenes(std::vector<Espectro> Members, int muertes, int puntaje, int vida);


private:

	int MutationRate;
	Population Popul;
	int totalDetections = 0;
	int totalHits = 0;
	int totalDefeats = 0;


	int EnemyFitness(float detections, float hits, float defeats);

	float maxToMutate(int muertes, int puntaje, int vidas);


};



