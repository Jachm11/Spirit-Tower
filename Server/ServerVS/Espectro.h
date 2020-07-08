#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
using namespace std;

//Estructura para el algoritmo genetico
struct Population {
	std::vector<Espectro> Members = std::vector<Espectro>(3);
};

class Espectro
{
public:
	int speed;
	int range;
	int life;
	bool attacking;
	bool backtracking;

	//fitness
	int detections;
	int hits;
	int defeats;
	int Fitness;

	//stats
	int R_Speed;
	int P_Speed;
	int V_radio;
	
	int posIndex;
	tuple<int, int> playerPos;
	tuple<int, int> currentPos;
	vector<tuple<int, int>> defaultRoute;
	queue<tuple<int, int>> attackRoute;
	stack<tuple<int, int>> backtrackRoute;
	string nextPos;

	Espectro();
	void move();
	void attack(int grid[20][20],tuple<int, int>);
	void gotHurt();
	void stop();
	void paralize();
	vector<tuple<int, int>> getAttackRoute(int grid[20][20], int srcRow, int srcCol, int destRow, int destCol);
	void defaultRouteVec();
	void printDefaultRoute();
};
