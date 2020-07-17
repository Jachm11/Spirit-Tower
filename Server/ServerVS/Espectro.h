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
	/// @param grid Una matriz del tama�o del juego con un 0 en la posici�n donde hay obst�culos y un 1 donde no hay
	/// @param tupla Una tupla con 2 n�meros enteros que representan la posici�n x,y del jugador
	/// @param pos Un string con la posici�n del jugador
	void attack(int grid[25][25], tuple<int, int> tupla, string pos);

	/// @brief Guarda las estad�siticas de los espectros generadas por un algoritmo gen�tico
	/// @param vel Velocidad normal del espectro
	/// @param rango Rango de visi�n del espectro
	/// @param velAtaque Velocidad de ataque del espectro
	void setStats(float vel, int rango, float velAtaque);
	
	/// @brief Funci�n que llama a diferentes m�todos para obtener la ruta desde el origen al destino especificado
	/// @param grid Matriz que representa al nivel
	/// @param srcRow N�mero de fila del origen
	/// @param srcCol N�mero de columna del origen
	/// @param destRow N�mero de fila del destino
	/// @param destCol N�mero de columna del destino
	/// @return Un vector de tuplas con la ruta que debe seguir
	vector<tuple<int, int>> getAttackRoute(int grid[25][25], int srcRow, int srcCol, int destRow, int destCol);
	
	/// @brief Posicion del jugador
	tuple<int, int> playerPos;
	/// @brief Posici�n siguiente a avanzar
	string nextPos;
	/// @brief Guarda la ruta de ataque
	string attackString;
	/// @brief Funci�n que a�ade una nueva posici�n a la ruta del backtracking conforme se mueve el espectro
	/// @param pos Posici�n a agregar
	void addBacktrackPos(string pos);
	/// @brief Funci�n que llama el servidor cuando solicitan la ruta de ataque
	/// @return Ruta de ataque con el formato necesario
	string getAttackResponse();
	/// @brief Funci�n que llama el servidor cuando solicitan la ruta default que sigue el espectro
	/// @return Ruta default con el formato necesario
	string getDefaultResponse();
	/// @brief Funci�n que llama el servidor cuando solicitan la ruta de backtracking
	/// @return Ruta de backtracking con el formato necesario
	string getBacktrackResponse();
	/// @brief Funci�n que llama el servidor cuando solicitan los stats del espectro
	/// @return Stats con el formato necesario
	string getStatsResponse();
	

private:
	/// @brief Vida del espectro
	int life;
	/// @brief Contador�para recorrer la ruta de ataque
	int posIndex;
	/// @brief Posici�n actual del espectro
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
	/// @brief Setter de la posici�n actual
	void setCurrentPos(string pos);

};

