#include "Juego.h"


Juego::Juego() {

	jugador = Jugador (5.2, 5.2);

	puntaje;

	pisoActual = 0;

	setMatrix();

	setPuntajes();
	
}

void Juego::generatePiso(int piso) {

	if (piso == 1) {

		Piso uno = Piso();
		pisos[0] = &uno;
		pisoActual++;

	}
	else if(piso != 5)
	{

		Piso *pisoAnterior = pisos[pisoActual];
		Piso new_piso = Piso(*puntajes[pisoActual],pisoAnterior->puntajeJugador,pisoAnterior->muertes,&jugador);
		pisos[piso - 1] = &new_piso;
		pisoActual++;
	}
	else {
		Piso boss =Piso(true);
		pisos[4] = &boss;
		pisoActual++;
	}

}


void Juego:: setPlayerPos(string pos) {
	jugador.setPos(pos);
}

void Juego:: playerHealed() {
	int vida = jugador.aumentarCorazon();
	//res = "El jugador ha ganado un corazon! Ahora tiene " + to_string(vida) + " corazones!";

}

void Juego:: playerHit() {
	jugador.ataqueSimple();
}

void Juego:: playerDied() {
	jugador.setMuerte();
	pisos[pisoActual]->updateMuertes();
}

void Juego:: playerVisible() {
	jugador.setSafe(false);
}

void Juego:: playerInvisible() {
	jugador.setSafe(true);

}

void Juego:: chestOpened() {
	puntaje += 10;
	pisos[pisoActual]->updatePuntaje(10);
}

void Juego:: enemyKilled(int ID) {
	if (ID == 1) {
		pisos[pisoActual]->EspectroMurio(ID);
	}
	else if (ID == 2) {
		pisos[pisoActual]->EspectroMurio(ID);
	}
	else if (ID == 3) {
		pisos[pisoActual]->EspectroMurio(ID);
	}
}

string Juego:: askEnemyRoute() {
	return "kkqlo";

}

string Juego:: askEnemyStats() {
	return "kkqlo";
}

void Juego::setMatrix() {


}
void Juego::setPuntajes() {


}