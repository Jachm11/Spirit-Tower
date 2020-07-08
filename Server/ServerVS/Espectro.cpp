#include "Espectro.h"

Espectro::Espectro()
{
	speed;
	range;
	life;
	attacking=false;
	backtracking=false;
	playerPos;
	defaultRoute;
	attackRoute;
	backtrackRoute;
	nextPos;
	posIndex = 0;
	defaultRouteVec();
	
	//Cosas que metio Jose :3

	//fitness
	detections = 0; 
	hits = 0;
	defeats = 0;
	Fitness;

	//stats
	R_Speed;
	P_Speed;
	V_radio;
}
void Espectro::move()
{
	if (posIndex == defaultRoute.size())
	{
		reverse(defaultRoute.begin(), defaultRoute.end());
		posIndex = 0;
	}
	if (attackRoute.empty()) 
	{
		backtracking = true;
		attacking = false;
	}
	if (backtrackRoute.empty()) 
	{
		backtracking = false;
	}
	if (!attacking)
	{
		if(backtracking)
		{
			currentPos = backtrackRoute.top();
			backtrackRoute.pop();
		}
		else 
		{
			currentPos = defaultRoute[posIndex];
			posIndex++;
		}
	}
	else
	{
		currentPos = attackRoute.front();
		backtrackRoute.push(attackRoute.front());
		attackRoute.pop();
	}
	cout << "---" << "("<<get<0>(currentPos) <<","<< get<1>(currentPos)<<")";

}
void Espectro::attack(int grid[20][20],tuple<int, int> playerPos)
{
	attacking = true;
	backtracking = false;
	backtrackRoute.push(currentPos);
	vector<tuple<int, int>> attack = getAttackRoute(grid, get<0>(currentPos), get<1>(currentPos), get<0>(playerPos), get<1>(playerPos));
	for (int i = 0; i < attack.size(); i++)
	{
		attackRoute.push(attack[i]);
	}
	

}
void Espectro::stop()
{
	attacking = false;
	backtracking = true;

}
void Espectro::gotHurt()
{

}

void Espectro::paralize()
{
	
}
void Espectro::defaultRouteVec() 
{
	defaultRoute.push_back(make_tuple(12, 18));
	defaultRoute.push_back(make_tuple(11, 18));
	defaultRoute.push_back(make_tuple(10, 18));
	defaultRoute.push_back(make_tuple(10, 17));
	defaultRoute.push_back(make_tuple(10, 16));
	defaultRoute.push_back(make_tuple(10, 15));
	defaultRoute.push_back(make_tuple(10, 14));
	defaultRoute.push_back(make_tuple(10, 13));
	defaultRoute.push_back(make_tuple(11, 13));
	defaultRoute.push_back(make_tuple(12, 13));
	defaultRoute.push_back(make_tuple(13, 13));
	defaultRoute.push_back(make_tuple(14, 13));
	defaultRoute.push_back(make_tuple(15, 13));
	defaultRoute.push_back(make_tuple(16, 13));
	defaultRoute.push_back(make_tuple(17, 13));
}
void Espectro::printDefaultRoute()
{
	
	for (int i = 0; i < defaultRoute.size(); i++)
	{

		cout << get<0>(defaultRoute[i]) << get<1>(defaultRoute[i]) << " ->";

	}
}