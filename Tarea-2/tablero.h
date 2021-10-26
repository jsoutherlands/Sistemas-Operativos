#ifndef _TABLERO_H
#define _TABLERO_H

typedef struct _nodo{
	int posicion;
	int dato;
	int jugadores[3];
} tipoNodo;

typedef struct tablero{
	tipoNodo casillas[27];
	int dinero[3];
	int len;
} Tablero;

Tablero *crearTablero();
int getJugador(Tablero* tablero, int jugador);
void moveToPos(Tablero* tablero, int dado, int jugador);
char datoChar(Tablero* tablero, int posicion);

#endif
