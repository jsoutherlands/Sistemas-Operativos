#include "tablero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define NAME_SHMEM "/tablero1"

Tablero *crearTablero(){
	int fd;
	Tablero *newTablero;

	fd = shm_open(NAME_SHMEM,O_CREAT| O_RDWR,00600); //crea la memoria compartida
	ftruncate(fd,sizeof(Tablero)); //asigna el espacio a la memoria compartida
	newTablero= mmap(0, sizeof(Tablero), PROT_WRITE, MAP_SHARED, fd, 0);
	newTablero->len = 28;
	printf("len = %d\n", newTablero->len);
	//printf("Tablero len: %d\n", newTablero->len);

	for (int i = 0; i < 27; i++){
		newTablero->casillas[i].posicion = i+1;
		for (int j = 0; j < 3; j++){

			newTablero->casillas[i].jugadores[j] = 0;
		}
	}

	newTablero->casillas[0].dato = 100;
	newTablero->casillas[1].dato = 50;
	newTablero->casillas[2].dato = 50;
	newTablero->casillas[3].dato = -25;
	newTablero->casillas[4].dato = -2;
	newTablero->casillas[5].dato = 50;
	newTablero->casillas[6].dato = -25;
	newTablero->casillas[7].dato = -5;
	newTablero->casillas[8].dato = 75;
	newTablero->casillas[9].dato = -50;
	newTablero->casillas[10].dato = -50;
	newTablero->casillas[11].dato = 75;
	newTablero->casillas[12].dato = 75;
	newTablero->casillas[13].dato = -3;
	newTablero->casillas[14].dato = 0;
	newTablero->casillas[15].dato = 3;
	newTablero->casillas[16].dato = 50;
	newTablero->casillas[17].dato = -4;
	newTablero->casillas[18].dato = 50;
	newTablero->casillas[19].dato = -50;
	newTablero->casillas[20].dato = -25;
	newTablero->casillas[21].dato = -5;
	newTablero->casillas[22].dato = 75;
	newTablero->casillas[23].dato = 5;
	newTablero->casillas[24].dato = 75;
	newTablero->casillas[25].dato = -4;
	newTablero->casillas[26].dato = -25;
	newTablero->casillas[27].dato = -75;


	//A considerar: ver tail y head!!!

	for (int k = 0; k < 3; k++){
		newTablero->dinero[k] = 100;
		newTablero->casillas[0].jugadores[k] = 1;
	}
	return newTablero;
}

int getJugador(Tablero* tablero, int jugador){
	for (int i = 0; i < tablero->len; i++){
		if (tablero->casillas[i].jugadores[jugador] == 1){
			return i;
		}
	}
	return 0;
}

void moveToPos(Tablero* tablero, int dado, int jugador){
	int posicion = getJugador(tablero, jugador);
	int nuevaposicion = posicion + dado;
	if (nuevaposicion >= 27){
		nuevaposicion = nuevaposicion-27;
		tablero->dinero[jugador] += 100;
	}
	tablero->casillas[posicion].jugadores[jugador] = 0;
	tablero->casillas[nuevaposicion].jugadores[jugador] = 1;
};


