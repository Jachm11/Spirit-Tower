#include "Jugador.h"
#include <iostream>
#include <string>

using namespace std;
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
    pos[0] = stof(dividir(_pos, 0));
    pos[1] = stof(dividir(_pos, 1));
}
bool Jugador::getSafe(float _posX, float _posY) {
    cout << _posY << endl;
    if (_posX == 0 && _posY == 0) {
        is_safe = true;
        atacable = false;
    }
    else {
        is_safe = false;
        atacable = true;
    }
    return is_safe;
}
int Jugador::aumentarCorazon() {
    corazones++;
    return corazones;
}
float* Jugador::getPos() {
    return &pos[0];
}
bool Jugador::estaMuerto() {
    if (corazones == 0) {
        vive = false;

    }
    return vive;
}
int Jugador::ataqueSimple() {
    if (!getSafe(pos[0], pos[1])) {
        corazones--;

    }
    return corazones;
}
int Jugador::ataqueEspectro() {
    if (!getSafe(pos[0], pos[1])) {
        vive = false;
        return corazones = 0;
    }
    return corazones;
}
// funcion que me divide un string por elementos fijo en c++ y retorna un arreglo con las plabras separadas
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

