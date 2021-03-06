#include "Jugador.h"
#include <iostream>
#include <string>

using namespace std;
Jugador::Jugador() {};
Jugador::Jugador(float _posX, float _posY)
{
    pos[0] = _posX;
    pos[1] = _posY;
    corazones = 5;
    is_safe = false;
    vive = true;
    atacable = false;

}
void Jugador::setPos(string _pos) {
    pos[0] = stof(dividir(_pos, 1));
    pos[1] = stof(dividir(_pos, 2));
}
void Jugador::setSafe(bool estado) {
    is_safe = estado;
}
bool Jugador::isSafe() {
    return is_safe;
}
int Jugador::aumentarCorazon() {
    if (corazones > 0 && corazones < 5) {
        corazones++;
    }
    return corazones;
}
float* Jugador::getPos() {
    return &pos[0];
}
void Jugador::setMuerte() {
    corazones = 5;
}
bool Jugador::estaMuerto() {
    return vive;
}
int Jugador::ataqueSimple() {
    if (!isSafe() && corazones > 0) {
        corazones--;

    }
    return corazones;
}
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

