#include "Genetic.h"


Genetic::Genetic() {

	MutationRate;
	Popul;
};

int Genetic::EnemyFitness(float detections, float hits, float defeats) {

	float det_rate = (detections / totalDetections) * 40.0;
	std::cout<<"Detection rate: " << det_rate << std::endl;
	int hit_rate = (hits / totalHits) * 45.0;
	std::cout << "Hit rate: " << hit_rate << std::endl;
	int defeat_rate = 15 - (defeats / totalDefeats) * 15.0;
	std::cout << "Defeat rate" << defeat_rate << std::endl;

	int total = det_rate + hit_rate + defeat_rate;
	std::cout << "Fitness: " << total << std::endl;

	return total;

}

float Genetic::maxToMutate(int muertes, int puntaje, int vidas) {

	float surv = (100 - (muertes * 10)) * 0.3;
	std::cout << "Survival: " << surv << std::endl;

	float rng = (rand() % 100 + 1) * 0.1;
	std::cout << "Rng: " << rng << std::endl;

	float total = surv + (puntaje * 0.3) + (vidas * 0.3) + rng;
	std::cout << "Toltal: " << total << std::endl;

	float MaxMutation = (total / 100) * 40;

	std::cout << "Maxima mutacion: " << MaxMutation << std::endl;

	return MaxMutation;

}

std::vector <float> Genetic::getGenes(std::vector<Espectro> Members, int muertes, int puntaje, int vida) {

	srand(time(NULL));
	
	int MutationRate = 30;

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
	std::vector<float> new_genes;
	float new_R_Speed;
	float new_P_Speed;
	float new_V_radio;

	// Probabilidad de que haya mutacion
	float mutation_strenght = maxToMutate(2, 50, 50);

	//Selecciona a un padre con un % de mutacion
	int TempSelection = rand() % Parents.size();
	new_R_Speed = Parents.at(TempSelection).speed;
	if (rand() % 100 < MutationRate) {
		new_R_Speed += new_R_Speed * (mutation_strenght / 100);
		cout << "Se produjo una mutacion de velocidad! "<< endl;
	}
	cout<< "Genetic Speed: "<< new_R_Speed << endl;
	new_genes.push_back(new_R_Speed);

	//Selecciona a un padre con un % de mutacion
	TempSelection = rand() % Parents.size();
	new_P_Speed = Parents.at(TempSelection).chaseSpeed;
	if (rand() % 100 < MutationRate) {
		new_P_Speed += new_P_Speed * (mutation_strenght / 100);
		cout << "Se produjo una mutacion de persecucion! " << endl;
	}
	cout << "Genetic Chase Speed: " << new_P_Speed << endl;
	new_genes.push_back(new_P_Speed);

	//Selecciona a un padre con un % de mutacion
	TempSelection = rand() % Parents.size();
	new_V_radio = Parents.at(TempSelection).range;
	if (rand() % 100 < MutationRate) {
		new_V_radio += new_V_radio * (mutation_strenght / 100);
		cout << "Se produjo una mutacion de vision! " << endl;
	}
	cout << "Genetic Range: " << new_V_radio << endl;
	new_genes.push_back(new_V_radio);


	return new_genes;

}

