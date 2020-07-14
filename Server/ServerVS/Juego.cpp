#include "Juego.h"

Juego::Juego() {


	jugador = Jugador (5.2, 5.2);

	puntaje; // se actualiza solo hasta que se pase de nivel
	puntajes;
	rutas;

	pisoActual = -1;
	muertes = 0;
	cofres = 0;

	setPuntajes(puntajes);
	setRutas();

}


//     ____________________
//____/Funciones de partida

void Juego::generatePiso(int piso) {

	if (piso == 1) {

		piso1  = Piso(rutas.at(0), rutas.at(1), rutas.at(2), puntajes[0]);
		pisoActual++;
	}

	else if(piso == 2)
	{
		piso2 = Piso(rutas.at(3), rutas.at(4), rutas.at(5),
			piso1.puntajeJugador,piso1.muertes,jugador,piso1.espectros ,puntajes[1]);
		pisoActual++;
		puntaje += piso1.puntajeJugador;
	}

	else if (piso == 3)
	{

		piso3 = Piso(rutas.at(6), rutas.at(7), rutas.at(8),
			piso2.puntajeJugador, piso2.muertes, jugador, piso2.espectros, puntajes[2]);
		pisoActual++;
		puntaje += piso2.puntajeJugador;
		pisoActual++;
	}

	else if (piso == 4)
	{

		piso4 = Piso(rutas.at(9), rutas.at(10), rutas.at(11),
			piso3.puntajeJugador, piso3.muertes, jugador, piso3.espectros, puntajes[3]);
		pisoActual++;
		puntaje += piso3.puntajeJugador;
		pisoActual++;
	}
	else {

		piso5 = Piso(true);
		puntaje += piso4.puntajeJugador;
		pisoActual++;
	}

}

void Juego::pointsEarned(int puntos) {

	if (pisoActual == 0) {
		piso1.updatePuntaje(puntos);
	}
	else if (pisoActual == 1) {
		piso2.updatePuntaje(puntos);
	}
	else if (pisoActual == 2) {
		piso3.updatePuntaje(puntos);
	}
	else if (pisoActual == 3) {
		piso4.updatePuntaje(puntos);
	}

}

void Juego::chestOpened()
{
	cofres++;
}

string Juego::endGame()
{
	//puntaje = 54;
	//cofres = 10;
	//muertes = 89;
	puntaje += piso5.puntajeJugador;
	string estadisticas = "Puntaje obtenido: " + to_string(puntaje) + "\n Cofres abiertos: " + to_string(cofres) + " de 12 \n Muertes totales: " + to_string(muertes);
	std::cout << "Puntaje total obtenido: "<<puntaje << " de XXXX"<<endl;
	std::cout << "Cofres encontrados: " <<cofres << " de 12" <<endl;
	std::cout << "Muertes totales: "<<muertes <<endl;
	return estadisticas;

}

//     ____________________
//____/Funciones de jugador

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
	muertes++;

	if (pisoActual == 0) {
		piso1.jugadorMuere();
	}
	else if (pisoActual == 1) {
		piso2.jugadorMuere();
	}
	else if (pisoActual == 2) {
		piso3.jugadorMuere();
	}
	else if (pisoActual == 3) {
		piso4.jugadorMuere();
	}
	
}

void Juego:: playerVisible() {
	jugador.setSafe(false);
}

void Juego:: playerInvisible() {
	jugador.setSafe(true);

}

string Juego::playerState()
{
	return to_string((int)jugador.is_safe);
}


//        _____________________
//_______/Funciones del enemigo

string Juego::defaultResponse(int ID)
{
	
	if (pisoActual == 0) {
		return piso1.espectros[ID].getDefaultResponse();
	}
	else if (pisoActual == 1) {
		return piso2.espectros[ID].getDefaultResponse();;
	}
	else if (pisoActual == 2) {
		return piso3.espectros[ID].getDefaultResponse();
	}
	else if (pisoActual == 3) {
		return piso4.espectros[ID].getDefaultResponse();
	}
	
}

string Juego::statsResponse(int ID)
{

	if (pisoActual == 0) {
		return piso1.espectros[ID].getStatsResponse();
	}
	else if (pisoActual == 1) {
		return piso2.espectros[ID].getStatsResponse();
	}
	else if (pisoActual == 2) {
		return piso3.espectros[ID].getStatsResponse();
	}
	else if (pisoActual == 3) {
		return piso4.espectros[ID].getStatsResponse();
	}

}

string Juego::attackResponse(int ID, string pos) 
{
	float* jp =jugador.getPos();

	piso1.espectros[ID].attack(Matriz1, make_tuple((int)jp[0], (int)jp[1]), pos);
	return piso1.espectros[ID].getAttackResponse();

	if (pisoActual == 0) {
		piso1.espectros[ID].attack(Matriz1, make_tuple((int)jp[0], (int)jp[1]), pos);
		return piso1.espectros[ID].getAttackResponse();
	}
	else if (pisoActual == 1) {
		piso2.espectros[ID].attack(Matriz1, make_tuple((int)jp[0], (int)jp[1]), pos);
		return piso2.espectros[ID].getAttackResponse();
	}
	else if (pisoActual == 2) {
		piso3.espectros[ID].attack(Matriz1, make_tuple((int)jp[0], (int)jp[1]), pos);
		return piso3.espectros[ID].getAttackResponse();
	}
	else if (pisoActual == 3) {
		piso4.espectros[ID].attack(Matriz1, make_tuple((int)jp[0], (int)jp[1]), pos);
		return piso4.espectros[ID].getAttackResponse();
	}

}

string Juego::backtrackResponse(int ID)
{

	if (pisoActual == 0) {
		return piso1.espectros[ID].getBacktrackResponse();
	}
	else if (pisoActual == 1) {
		return piso2.espectros[ID].getBacktrackResponse();
	}
	else if (pisoActual == 2) {
		return piso3.espectros[ID].getBacktrackResponse();
	}
	else if (pisoActual == 3) {
		return piso4.espectros[ID].getBacktrackResponse();
	}

}

void Juego::backtrackPos(int ID, string pos)
{
	
	if (pisoActual == 0) {
		return piso1.espectros[ID].addBacktrackPos(pos);
	}
	else if (pisoActual == 1) {
		return piso2.espectros[ID].addBacktrackPos(pos);
	}
	else if (pisoActual == 2) {
		return piso3.espectros[ID].addBacktrackPos(pos);
	}
	else if (pisoActual == 3) {
		return piso4.espectros[ID].addBacktrackPos(pos);
	}
}

void Juego:: enemyDied(int ID) {
	if (pisoActual == 0) {
		piso1.EspectroMurio(ID);
	}
	else if (pisoActual == 1) {
		piso2.EspectroMurio(ID);
	}
	else if (pisoActual == 2) {
		piso3.EspectroMurio(ID);
	}
	else if (pisoActual == 3) {
		piso4.EspectroMurio(ID);
	}
}

void Juego::enemyDetected(int ID) {
	if (pisoActual == 0) {
		piso1.EspectroVio(ID);
	}
	else if (pisoActual == 1) {
		piso2.EspectroVio(ID);
	}
	else if (pisoActual == 2) {
		piso3.EspectroVio(ID);
	}
	else if (pisoActual == 3) {
		piso4.EspectroVio(ID);
	}
}

void Juego::enemyKilled(int ID) {
	if (pisoActual == 0) {
		piso1.EspectroMato(ID);
	}
	else if (pisoActual == 1) {
		piso2.EspectroMato(ID);
	}
	else if (pisoActual == 2) {
		piso3.EspectroMato(ID);
	}
	else if (pisoActual == 3) {
		piso4.EspectroMato(ID);
	}
}

//    _____________
//___/Set constants
void Juego::setPuntajes(int arr[5]) {

	arr[0] = 100;
	arr[1] = 200;
	arr[2] = 300;
	arr[3] = 300;
	arr[4] = 300;
}

void Juego::setRutas()
{
	//Piso 1
	rutas.push_back("2,4;22,4;22,5;2,5");
	rutas.push_back("1,12;10,12;10,21;1,21");
	rutas.push_back("24,21;15,21;15,12;24,12");
	//Piso 2
	rutas.push_back("2,2;22,2;22,3;2,3");
	rutas.push_back("22,20;22,10");
	rutas.push_back("1,11;1,10;5,10;5,11");
	//Piso 3
	rutas.push_back("12,2;20,2;20,8;20,2");
	rutas.push_back("13,8;18,8");
	rutas.push_back("16,19;16,16;18,16;18,19");
	//Piso 4
	rutas.push_back("algo");
	rutas.push_back("algo");
	rutas.push_back("algo");
}

