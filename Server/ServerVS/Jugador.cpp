#include "Jugador.h"
#include <iostream>
#include <string>

using namespace std;
Jugador::Jugador() {};
/**
 * @brief Jugador::Jugador constructor del jugador, inicializa todos los datos
 * @param _posX dato de tipo float, corresponde a la posicion inicial en x del jugador
 * @param _posY datos de tipo float, corresponde a la psocion incial en y del jugador
*/
Jugador::Jugador(float _posX, float _posY)
{
    pos[0] = _posX;
    pos[1] = _posY;
    corazones = 5;
    is_safe = false;
    vive = true;
    atacable = false;

}
/**
 * @brief Jugador::setPos metodo encargado de establecer la poscion actual del jugador
 * @param _pos string que contiene las posciones nuevas del jugador en el siguiente formato (pos;x;y)
*/
void Jugador::setPos(string _pos) {
    pos[0] = stof(dividir(_pos, 1));
    pos[1] = stof(dividir(_pos, 2));
}
/**
 * @brief Jugador::setSafe metodo que establece si el jugador se encuentra en zona segura
 * @param estado dato de tipo booleano
*/
void Jugador::setSafe(bool estado) {
    is_safe = estado;
}
/**
 * @brief Jugador::isSafe metodo que devuelve el estado de seguridad del jugador
 * @return bool de seguridad 
*/
bool Jugador::isSafe() {
    return is_safe;
}
/**
 * @brief Jugador::aumentarCorazon metodo que incrementa el corazon en una vida. Si es igual a 5 no aumenta.
 * @return corazones totales
 */
int Jugador::aumentarCorazon() {
    if (corazones > 0 && corazones < 5) {
        corazones++;
    }
    return corazones;
}
/**
 * @brief Jugador::getPos obtiene un puntero con el array de las posiciones del jugador en "x" y "y"
 * @return puntero array float con las posciones del jugador 
*/
float* Jugador::getPos() {
    return &pos[0];
}
/**
 * @brief Jugador::setMuerte Metodo que reestablece las vidas del jugador al morir
*/
void Jugador::setMuerte() {
    corazones = 5;
}
/**
 * @brief Jugador::estaMuerto retorna si el jugador murio
 * @return bool de vida
*/
bool Jugador::estaMuerto() {
    return vive;
}
/**
 * @brief Jugador::ataqueSimple metodo que reduce un corazon por ataque
 * @return corazones restantes
*/
int Jugador::ataqueSimple() {
    if (!isSafe() && corazones > 0) {
        corazones--;

    }
    return corazones;
}
/**
* @brief Jugador::dividir metodo que toma un string y lo separa por cada punto y coma encontrado
* @param info string que se desea dividir
* @param i int que indica el numero de la palabra dividida que se desea que se retorne
* @return string con la palabra deseada
*/
string Jugador::dividir(string info, int i) {
    string datos[10];
    if (info != "") {
        int pos = 0;
        int i = 0;
        while (pos != -1) {
            pos = info.find(";");
            datos[i] = info.substr(0, pos);
            info = info.substr(pos + 1, info.length() - 1);
            i++;
        }
    }
    return datos[i];
}

