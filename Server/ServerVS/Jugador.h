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
    bool getSafe(float _posX, float _posY);
    bool estaMuerto();
    string dividir(string info, int i);
    int ataqueSimple();
    int ataqueEspectro();

private:
    float pos[2];
    bool vive;
    bool is_safe;
    int corazones;
    bool atacable;
};
