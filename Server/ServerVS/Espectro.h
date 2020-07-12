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

	//constructores

	Espectro(string defRoute);
	Espectro() { currentPos = make_tuple(0, 0); };


	//Fitness
	int detections;
	int hits;
	int defeats;
	int Fitness;

	//Stats
	float speed;
	int range;
	float chaseSpeed;

	void attack(int grid[25][25], tuple<int, int>, string pos);


	void setStats(float vel, int rango, float velAtaque);
	
	vector<tuple<int, int>> getAttackRoute(int grid[25][25], int srcRow, int srcCol, int destRow, int destCol);

	tuple<int, int> playerPos;
	string nextPos;
	string attackString;
	void addBacktrackPos(string pos); 
	string getAttackResponse();
	string getDefaultResponse();
	string getBacktrackResponse();
	string getStatsResponse();
	

private:
	int life;
	int posIndex;
	
	tuple<int, int> currentPos;
	vector<tuple<int, int>> defaultRoute;
	vector<tuple<int, int>> attackRouteVec;
	string attackResponse;
	string defaultResponse;
	string backtrackResponse;
	string statsResponse;

	void setCurrentPos(string pos);

};

