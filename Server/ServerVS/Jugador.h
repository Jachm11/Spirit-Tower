#pragma once
#include<iostream>

using namespace std;
/**
 * @file Jugador.h
 * @author Sebastian Moya
 * @brief Clase plantilla para el jugador
*/

/// @brief Clase que controla los datos del jugador
class Jugador
{
public:
    /**
     * @brief Jugador::Jugador constructor del jugador, inicializa todos los datos
     * @param _posX dato de tipo float, corresponde a la posicion inicial en x del jugador
     * @param _posY datos de tipo float, corresponde a la psocion incial en y del jugador
    */
    Jugador(float _posX, float _posY);
    /**
     * @brief Jugador::setPos metodo encargado de establecer la poscion actual del jugador
     * @param _pos string que contiene las posciones nuevas del jugador en el siguiente formato (pos;x;y)
    */
    void setPos(string _pos);
    /**
     * @brief Jugador::aumentarCorazon metodo que incrementa el corazon en una vida. Si es igual a 5 no aumenta.
     * @return corazones totales
    */
    int aumentarCorazon();
    /**
     * @brief Jugador::getPos obtiene un puntero con el array de las posiciones del jugador en "x" y "y"
     * @return puntero array float con las posciones del jugador
    */
    float* getPos();
    /**
     * @brief Jugador::setSafe metodo que establece si el jugador se encuentra en zona segura
     * @param estado dato de tipo booleano
    */
    void setSafe(bool estado);
    /**
     * @brief Jugador::isSafe metodo que devuelve el estado de seguridad del jugador
     * @return bool de seguridad
    */
    bool isSafe();
    /**
     * @brief Jugador::setMuerte Metodo que reestablece las vidas del jugador al morir
    */
    void setMuerte();
    /**
     * @brief Jugador::estaMuerto retorna si el jugador murio
     * @return bool de vida
    */
    bool estaMuerto();
    /**
     * @brief Jugador::dividir metodo que toma un string y lo separa por cada punto y coma encontrado
     * @param info string que se desea dividir
     * @param i int que indica el numero de la palabra dividida que se desea que se retorne
     * @return string con la palabra deseada
    */
    string dividir(string info, int i);
    /**
     * @brief Jugador::ataqueSimple metodo que reduce un corazon por ataque
     * @return corazones restantes
    */
    int ataqueSimple();
    Jugador();
    int corazones;
    bool is_safe;

private:
    float pos[2];
    bool vive;
    bool atacable;
};
