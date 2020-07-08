#include "Genetic.h"


Genetic::Genetic() {

	MutationRate;
	Popul;
};

int Genetic::EnemyFitness(float detections, float hits, float defeats) {

	float det_rate = (detections / totalDetections) * 40.0;
	std::cout << det_rate << std::endl;
	int hit_rate = (hits / totalHits) * 45.0;
	std::cout << hit_rate << std::endl;
	int defeat_rate = 15 - (defeats / totalDefeats) * 15.0;
	std::cout << defeat_rate << std::endl;

	int total = det_rate + hit_rate + defeat_rate;
	std::cout << total << std::endl;

	return total;

}

float Genetic::maxToMutate(int muertes, int puntaje, int vidas) {

	float surv = (100 - (muertes * 10)) * 0.3;
	std::cout << surv << std::endl;

	float rng = (rand() % 100 + 1) * 0.1;
	std::cout << rng << std::endl;

	float total = surv + (puntaje * 0.3) + (vidas * 0.3) + rng;
	std::cout << total << std::endl;

	float MaxMutation = (total / 100) * 40;

	std::cout << MaxMutation << std::endl;

	return MaxMutation;

}

float* Genetic::getGenes(std::vector<Espectro> Members, int muertes, int puntaje, int vida) {

	int MutationRate = 10;
	srand(time(NULL));

	//create a population
	Popul.Members = Members;

	//Total de datos de espectros
	for (int i = 0; i < Popul.Members.size(); i++) {
		totalDetections += Popul.Members.at(i).detections;
		totalHits += Popul.Members.at(i).hits;
		totalDefeats += Popul.Members.at(i).defeats;
	}

	//Determinar fitness
	for (int i = 0; i < Popul.Members.size(); i++) {
		Popul.Members.at(i).Fitness = EnemyFitness(Popul.Members.at(i).detections, Popul.Members.at(i).hits, Popul.Members.at(i).defeats);
	}

	//now lets sort the population by fitness, from highest to lowest
	std::sort(Popul.Members.begin(), Popul.Members.end(), [](Espectro const& a, Espectro& b) {return a.Fitness > b.Fitness; });

	//select x amount of highest fitness members to pair from, lets use 2 parents in this case
	std::vector<Espectro> Parents{ Popul.Members.at(0), Popul.Members.at(1) };


	//lets do some gene permutation and mating
	float new_genes[3];
	float new_R_Speed;
	float new_P_Speed;
	float new_V_radio;

	// Probabilidad de que haya mutacion
	float mutation_strenght = maxToMutate(2, 50, 50);

	//Selecciona a un padre con un % de mutacion
	int TempSelection = rand() % Parents.size();
	new_R_Speed = Parents.at(TempSelection).R_Speed;
	if (rand() % 100 < MutationRate) {
		new_R_Speed += new_R_Speed * (mutation_strenght / 100);
	}
	new_genes[0] = new_R_Speed;

	//Selecciona a un padre con un % de mutacion
	TempSelection = rand() % Parents.size();
	new_P_Speed = Parents.at(TempSelection).P_Speed;
	if (rand() % 100 < MutationRate) {
		new_P_Speed += new_P_Speed * (mutation_strenght / 100);
	}
	new_genes[1] = new_P_Speed;

	//Selecciona a un padre con un % de mutacion
	TempSelection = rand() % Parents.size();
	new_V_radio = Parents.at(TempSelection).V_radio;
	if (rand() % 100 < MutationRate) {
		new_V_radio += new_V_radio * (mutation_strenght / 100);
	}
	new_genes[2] = new_V_radio;


	return new_genes;

}

