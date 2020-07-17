#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
using namespace std;

/// @brief Clase que controla a los espectros del juego
class Espectro
{
public:

	/// @brief Constructor de la clase
	/// @param Un string con la ruta defult que va a seguir el espectro creado
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

	/// @brief Guarda la ruta que debe seguir el objeto, utiliza el algoritmo A*
	/// @param grid Una matriz del tamaño del juego con un 0 en la posición donde hay obstáculos y un 1 donde no hay
	/// @param tupla Una tupla con 2 números enteros que representan la posición x,y del jugador
	/// @param pos Un string con la posición del jugador
	void attack(int grid[25][25], tuple<int, int> tupla, string pos);

	/// @brief Guarda las estadísiticas de los espectros generadas por un algoritmo genético
	/// @param vel Velocidad normal del espectro
	/// @param rango Rango de visión del espectro
	/// @param velAtaque Velocidad de ataque del espectro
	void setStats(float vel, int rango, float velAtaque);
	
	/// @brief Función que llama a diferentes métodos para obtener la ruta desde el origen al destino especificado
	/// @param grid Matriz que representa al nivel
	/// @param srcRow Número de fila del origen
	/// @param srcCol Número de columna del origen
	/// @param destRow Número de fila del destino
	/// @param destCol Número de columna del destino
	/// @return Un vector de tuplas con la ruta que debe seguir
	vector<tuple<int, int>> getAttackRoute(int grid[25][25], int srcRow, int srcCol, int destRow, int destCol);
	
	/// @brief Posicion del jugador
	tuple<int, int> playerPos;
	/// @brief Posición siguiente a avanzar
	string nextPos;
	/// @brief Guarda la ruta de ataque
	string attackString;
	/// @brief Función que añade una nueva posición a la ruta del backtracking conforme se mueve el espectro
	/// @param pos Posición a agregar
	void addBacktrackPos(string pos);
	/// @brief Función que llama el servidor cuando solicitan la ruta de ataque
	/// @return Ruta de ataque con el formato necesario
	string getAttackResponse();
	/// @brief Función que llama el servidor cuando solicitan la ruta default que sigue el espectro
	/// @return Ruta default con el formato necesario
	string getDefaultResponse();
	/// @brief Función que llama el servidor cuando solicitan la ruta de backtracking
	/// @return Ruta de backtracking con el formato necesario
	string getBacktrackResponse();
	/// @brief Función que llama el servidor cuando solicitan los stats del espectro
	/// @return Stats con el formato necesario
	string getStatsResponse();
	

private:
	/// @brief Vida del espectro
	int life;
	/// @brief Contador´para recorrer la ruta de ataque
	int posIndex;
	/// @brief Posición actual del espectro
	tuple<int, int> currentPos;
	/// @brief Un vector con la ruta default del espectro
	vector<tuple<int, int>> defaultRoute;
	/// @brief Un vector con la ruta de ataque del espectro
	vector<tuple<int, int>> attackRouteVec;
	/// @brief Guarda el string de la ruta de ataque para responder al servidor
	string attackResponse;
	/// @brief Guarda el string de la ruta default para responder al servidor
	string defaultResponse;
	/// @brief Guarda el string de la ruta de backtracking para responder al servidor
	string backtrackResponse;
	/// @brief Guarda el string de los stats para responder al servidor
	string statsResponse;
	/// @brief Setter de la posición actual
	void setCurrentPos(string pos);

};

