#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
using namespace std;



class Espectro
{
public:
	//constructor
	Espectro(string defRoute);
	Espectro();
	//fitness
	int detections;
	int hits;
	int defeats;
	int Fitness;

	//stats
	int R_Speed;
	int P_Speed;
	int V_radio;

	
	string move();
	void attack(int grid[25][25], tuple<int, int>);
	void gotHurt();
	void stop();
	void paralize();
	void paralizeStop();
	void setStats(float vel, int rango, float velAtaque);
	vector<tuple<int, int>> getAttackRoute(int grid[25][25], int srcRow, int srcCol, int destRow, int destCol);

	//tuple<int, int> playerPos;
	//string nextPos;
	//string attackString;
	//tuple<int, int> tupleFromString(string pos);
	//void defaultRouteVec(string defRoute);
	//string getDefaultRoute();
	//string getAttackRoute();
	//void setCurrentPos(string pos);
	
private:
	float speed;
	int range;
	float chaseSpeed;
	int life;
	bool attacking;
	bool backtracking;
	bool paralized;
	int posIndex;
	tuple<int, int> currentPos;
	vector<tuple<int, int>> defaultRoute;
	queue<tuple<int, int>> attackRoute;
	stack<tuple<int, int>> backtrackRoute;
	vector<tuple<int, int>> attackRouteVec;

};

struct Population {
	std::vector<Espectro> Members = std::vector<Espectro>(3);
};
