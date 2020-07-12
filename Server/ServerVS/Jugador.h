#pragma once
#include<iostream>

using namespace std;

class Jugador
{
public:
    Jugador(float _posX, float _posY);
    void setPos(string _pos);
    int aumentarCorazon();
    float* getPos();
    void setSafe(bool estado);
    bool isSafe();
    void setMuerte();
    bool estaMuerto();
    string dividir(string info, int i);
    int ataqueSimple();
    int ataqueEspectro();
    Jugador();
    int corazones;
    bool is_safe;

private:
    float pos[2];
    bool vive;
    bool atacable;
};
