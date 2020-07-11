#include "Juego.h"


Juego::Juego() {

	jugador = Jugador (5.2, 5.2);

	puntaje; // se actualiza solo hasta que se pase de nivel

	puntajes;

	rutas;

	pisoActual = 0;

	setMatrix();

	setPuntajes();

	setRutas();

	muertes = 0;

	
}

void Juego::generatePiso(int piso) {

	if (piso == 1) {

		Piso uno = Piso(rutas.at(0), rutas.at(1), rutas.at(2), *puntajes[0]);
		pisos[0] = &uno;
		pisoActual++;

	}
	else if(piso == 2)
	{

		Piso *pisoAnterior = pisos[pisoActual-1];
		std::vector <Espectro> espectros = pisoAnterior->espectros;
		Piso new_piso = Piso(rutas.at(3), rutas.at(4), rutas.at(5),
			pisoAnterior->puntajeJugador,pisoAnterior->muertes,jugador,espectros ,*puntajes[pisoActual]);
		pisos[piso - 1] = &new_piso;
		pisoActual++;
		puntaje += pisoAnterior->puntajeJugador;
	}

	else if (piso == 3)
	{

		Piso* pisoAnterior = pisos[pisoActual - 1];
		std::vector <Espectro> espectros = pisoAnterior->espectros;
		Piso new_piso = Piso(rutas.at(6), rutas.at(7), rutas.at(8),
			pisoAnterior->puntajeJugador, pisoAnterior->muertes, jugador, espectros, *puntajes[pisoActual]); 
		pisos[piso - 1] = &new_piso;
		pisoActual++;
	}

	else if (piso == 4)
	{

		Piso* pisoAnterior = pisos[pisoActual - 1];
		std::vector <Espectro> espectros = pisoAnterior->espectros;
		Piso new_piso = Piso(rutas.at(9), rutas.at(10), rutas.at(11),
			pisoAnterior->puntajeJugador, pisoAnterior->muertes, jugador, espectros, *puntajes[pisoActual]); 
		pisos[piso - 1] = &new_piso;
		pisoActual++;
	}
	else {

		Piso boss = Piso(true);
		pisos[4] = &boss;
		pisoActual++;
	}

}

void Juego:: setPlayerPos(string pos) {
	jugador.setPos(pos);
}

int Juego:: playerHealed() {
	 return jugador.aumentarCorazon();

}

int Juego:: playerHit() {
	return jugador.ataqueSimple();
}

void Juego:: playerDied() {
	jugador.setMuerte();
	//muertes++;
	//pisos[pisoActual]->jugadorMuere();


}

void Juego:: playerVisible() {
	jugador.setSafe(false);
}

void Juego:: playerInvisible() {
	jugador.setSafe(true);

}

void Juego:: chestOpened() {
	pisos[pisoActual]->updatePuntaje(10);
}

void Juego:: enemyKilled(int ID) {
		pisos[pisoActual]->EspectroMurio(ID);
}

void Juego:: askEnemyRoute(int ID) {


	float* pos = jugador.getPos();


	if (pisoActual == 0) {
		pisos[pisoActual]->espectros.at(ID - 1).attack(Matriz1,make_tuple(24 - (int)pos[1], (int)pos[0]));
	}
	else if (pisoActual == 1) {
		pisos[pisoActual]->espectros.at(ID - 1).attack(Matriz2, make_tuple(24 - (int)pos[1], (int)pos[0]));
	}
	else if (pisoActual == 2) {
		pisos[pisoActual]->espectros.at(ID - 1).attack(Matriz3, make_tuple(24 - (int)pos[1], (int)pos[0]));
	}
	else if (pisoActual == 3) {
		pisos[pisoActual]->espectros.at(ID - 1).attack(Matriz4, make_tuple(24 - (int)pos[1], (int)pos[0]));
	}
}

void Juego::enemyStop(int ID)
{
		pisos[pisoActual]->espectros.at(ID - 1).stop();
}

string Juego:: askEnemyStats() {

	//string thisStats = pisos[pisoActual]->espectros.at(ID - 1).statsToSend;
	//return thisStats;
	return "kkqlo";
}

void Juego::setMatrix() {

	//Matriz1 = algo;
	//Matriz2 = algo;
	//Matriz3 = algo;
	//Matriz4 = algo;
	//Matriz5 = algo;

}
void Juego::setPuntajes() {

	//puntajes[0] = algo;
	//puntajes[1] = algo;
	//puntajes[2] = algo;
	//puntajes[3] = algo;
	//puntajes[4] = algo;
}

void Juego::setRutas()
{
	//Piso 1
	rutas.push_back("algo");
	rutas.push_back("algo");
	rutas.push_back("algo");
	//Piso 2
	rutas.push_back("algo");
	rutas.push_back("algo");
	rutas.push_back("algo");
	//Piso 3
	rutas.push_back("algo");
	rutas.push_back("algo");
	rutas.push_back("algo");
	//Piso 4
	rutas.push_back("algo");
	rutas.push_back("algo");
	rutas.push_back("algo");
}
