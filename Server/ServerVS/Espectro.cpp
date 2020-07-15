#include "Espectro.h"

Espectro::Espectro(string defRoute)
{

	posIndex = 0;
	defaultResponse = defRoute;
	currentPos = make_tuple(0,0);
	attackRouteVec;

	//Fitness
	detections = 0; 
	hits = 0;
	defeats = 0;
	Fitness;

}

void Espectro::attack(int grid[25][25], tuple<int, int> playerPos, string pos)
{
	setCurrentPos(pos);
	attackRouteVec = getAttackRoute(grid, get<0>(currentPos), get<1>(currentPos), 24-get<1>(playerPos), get<0>(playerPos));

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
	else { route = "0"; }
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



