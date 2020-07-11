#include "Espectro.h"


Espectro::Espectro() {}

Espectro::Espectro(string defRoute)
{
	paralized = false;
	attacking = false;
	backtracking = false;
	posIndex = 0;
	defaultResponse = defRoute;
	//defaultRouteVec(defRoute);

	
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
string Espectro::move()
{
	if (!paralized) {
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

			attacking = false;

		}
		if (!attacking)
		{
			if (backtracking)
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
	}
	//cout << "---" << "(" << get<0>(currentPos) << "," << get<1>(currentPos) << ")";

	return to_string(get<0>(currentPos)) + ',' + to_string(get<1>(currentPos));



}
void Espectro::attack(int grid[25][25], tuple<int, int> playerPos, string pos)
{
	
	setCurrentPos(pos);
	attacking = true;
	backtracking = false;
	backtrackRoute.push(currentPos);
	attackRouteVec = getAttackRoute(grid, get<0>(currentPos), get<1>(currentPos), 24-get<1>(playerPos), get<0>(playerPos));
	if (!attackRouteVec.empty()) 
	{
		for (int i = 0; i < attackRouteVec.size(); i++)
		{
			attackRoute.push(attackRouteVec[i]);

		}
	}

}
void Espectro::setCurrentPos(string pos) 
{
	int x = stoi(pos.substr(0,pos.find(',')));
	int y = 24-stoi(pos.substr(pos.find(',') + 1));
	currentPos = make_tuple(y,x);
}
void Espectro::addBacktrackPos(string pos)
{
	backtrackResponse = backtrackResponse + pos + ";";
}
void Espectro::setStats(float vel, int rango, float velAtaque)
{
	string stats;
	speed = vel;
	range = rango;
	chaseSpeed = velAtaque;
	stats = to_string((int)speed) + ";" + to_string((int)range) + ";" + to_string((int)chaseSpeed);
	statsResponse = stats;
}
string Espectro::getAttackResponse()
{
	string route;
	if (!attackRouteVec.empty())
	{
		route = to_string(get<1>(attackRouteVec[0])) + "," + to_string(24 - get<0>(attackRouteVec[0])) + ";";
		for (int i = 1; i < attackRouteVec.size(); i++)
		{

			route = route + to_string(get<1>(attackRouteVec[i])) + "," + to_string(24 - get<0>(attackRouteVec[i])) + ";";

		}
		route.pop_back();
		attackResponse = route;
	}
	else { route = "NO"; }
	return route;
}
string Espectro::getDefaultResponse()
{
	return defaultResponse;
}
string Espectro::getBacktrackResponse()
{
	backtrackResponse.pop_back();
	return backtrackResponse;
}
string Espectro::getStatsResponse()
{
	return statsResponse;
}


void Espectro::stop()
{
	attacking = false;
	backtracking = true;

}
void Espectro::gotHurt()
{

}

void Espectro::paralizeStop()
{

	paralized = false;
}
void Espectro::paralize()
{
	paralized = true;
}


	



//FUNCIONES DE OTRA LOGICA
//void Espectro::defaultRouteVec(string defRoute)
//{
//	string temp=defRoute;
//	while (!temp.empty()) 
//	{
//		defaultRoute.push_back(tupleFromString(temp.substr(0, temp.find(";"))));
//		temp = temp.substr(temp.find(";")+1);
//	}
//}
//tuple<int, int> Espectro::tupleFromString(string pos)
//{
//	int x = stoi(pos.substr(0, pos.find(',')));
//	int y = stoi(pos.substr(pos.find(',') + 1));
//	return make_tuple(x, y);
//}

//string Espectro::getDefaultRoute()
//{
//	string route = to_string(get<0>(defaultRoute[0]))+","+to_string(get<1>(defaultRoute[0])) + ";";
//	for (int i = 1; i < defaultRoute.size(); i++)
//	{
//		
//		route = route + to_string(get<0>(defaultRoute[i]))+"," + to_string(get<1>(defaultRoute[i]))+";";
//		//cout << get<0>(defaultRoute[i]) << get<1>(defaultRoute[i]) << " ->";
//
//	}
//	route.pop_back();
//	
//	return route;
//}
//string Espectro::getAttackRoute()
//{
//	
//	string route = to_string(get<0>(attackRouteVec[0])) + "," + to_string(get<1>(attackRouteVec[0])) + ";";
//	for (int i = 1; i < attackRouteVec.size(); i++)
//	{
//
//		route = route + to_string(get<0>(attackRouteVec[i])) + "," + to_string(get<1>(attackRouteVec[i])) + ";";
//		//cout << get<0>(attackRouteVec[i]) << get<1>(attackRouteVec[i]) << " ->";
//
//	}
//	route.pop_back();
//	attackString = route;
//	return route;

//}

//}

