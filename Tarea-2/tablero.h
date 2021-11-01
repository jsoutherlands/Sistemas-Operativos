#ifndef _TABLERO_H
#define _TABLERO_H

//Struct de "casilla" de tablero.
typedef struct _nodo{
	int posicion;
	int dato;
	int jugadores[3];
} tipoNodo;

//Struct de tablero.
typedef struct tablero{
	tipoNodo casillas[28];
	int dinero[3];
	int pids[3];
	int len;
} Tablero;

char mostrarPosicion(Tablero* tablero, int casilla, int jugador);
void mostrarTablero(Tablero* tablero);
Tablero *crearTablero();
int getJugador(Tablero* tablero, int jugador);
void moveToPos(Tablero* tablero, int dado, int jugador);

#endif
