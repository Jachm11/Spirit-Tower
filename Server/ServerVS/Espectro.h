#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
using namespace std;

class Espectro
{
public:
	int speed;
	int range;
	int life;
	bool attacking;
	bool backtracking;
	
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
