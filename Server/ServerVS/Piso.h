#pragma once
#include "Espectro.h"
#include "Jugador.h"
#include "Genetic.h"

/**
 * @file Piso.h
 * @author Jose A. Chavarria
 * @brief Clase plantilla para los niveles
*/

/// @brief Clase que maneja los datos de cada piso del juego
class Piso
{

public:

	int puntajeDePiso;
	int puntajeJugador;
	int muertes;
	int cofresPlayer;
	std::vector <Espectro> espectros;
	
	//Constructores

	Piso();

	/// @brief Contructor del piso 1 
	/// @param E1 Ruta default del espectro 0
	/// @param E2 Ruta default del espectro 1
	/// @param E3 Ruta default del espectro 2
	/// @param puntajeMax Puntaje maximo del nivel
	/// @return Instancia de piso 1
	Piso(string E1, string E2, string E3, int puntajeMax);

	/// @brief Contructor del pisos 2, 3, 4 
	/// @param E1 Ruta default del espectro 0
	/// @param E2 Ruta default del espectro 1
	/// @param E3 Ruta default del espectro 2
	/// @param puntajePasado Puntaje que gano el jugador en el piso anterior
	/// @param MuertesPasadas Puntaje que gano el jugador en el piso anterior 
	/// @param j puntero al jugador en juego
	/// @param pastGen Espectros del piso anterior
	/// @param puntajeMax Puntaje maximo del nivel
	/// @return Instacia de piso 2, 3, o 4 
	Piso(string E1, string E2, string E3, int puntajePasado, int MuertesPasadas, Jugador j, std::vector <Espectro> pastGen, int puntajeMax, int cofres);

	/// @brief Constructor para piso final
	/// @param boss Valor vacio
	/// @return Instancia Piso 5
	Piso(int cofres);

	//Puntos
	
	/// @brief Actualiza los puntos de ganados piso
	/// @param puntos cantidad de puntos ganados
	void updatePuntaje(int puntos);

	//Jugador

	/// @brief Actualiza las muertes del jugador este piso
	void jugadorMuere();

	//Espectros
	
	/// @brief Actualiza las muertes del espectro del piso
	/// @param ID Id del espectro del piso
	void EspectroMurio(int ID);

	/// @brief Actualiza las deteciones del espectro del piso
	/// @param ID Id del espectro del piso
	void EspectroVio(int ID);

	/// @brief Actualiza los asesinatos del espectro del piso
	/// @param ID Id del espectro del piso
	void EspectroMato(int ID);

private:

	/// @brief Genera un stat aleatorio para los espectros del primer piso
	/// @return stat aleatorio para un espectro
	float getRandomStat(int i);

	/// @brief Llama a la funcion que ejecuta un ciclo del algoritmo genetico
	/// @param pastGen Generacion de espectros pasada
	/// @param puntajePasado Puntaje obtenido en el piso anterior
	/// @param muertesPasadas Muertes en el piso anterior
	/// @param j La instancia dejugador
	/// @return Retorna un vector con los nuevos stats para un espectro
	vector<float> getGeneticStat(std::vector <Espectro> pastGen, int puntajePasado, int muertesPasadas, Jugador j);

};

