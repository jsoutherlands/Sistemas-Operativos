#include "tablero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define NAME_SHMEM "/tablero1"

/****************************************************
* 
* char mostrarPosicion
*
*****************************************************
* 
* Parámetros:
* Tablero*	tablero
* int 		casilla
* int 		jugador
* 
*****************************************************
* 
* Descripción: Retorna el número del jugador cuando
* lo encuentra en la casilla señalada (como char).
* Si el jugador no está, se retorna un espacio en
* blanco.
* 
****************************************************/
char mostrarPosicion(Tablero* tablero, int casilla, int jugador){
	if(tablero->casillas[casilla].jugadores[jugador] == 1){
		return jugador + 49;
	}else{
		return 32;
	}
}


/****************************************************
* 
* void mostrarTablero
*
*****************************************************
* 
* Parámetros:
* Tablero*	tablero
* 
*****************************************************
* 
* Descripción: Muestra por pantalla todo el tablero,
* incluyendo las posiciones de los jugadores.
* 
****************************************************/
void mostrarTablero(Tablero* tablero){
	printf("+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+\n");
	printf("|           |           |           |           |           |           |           |           |\n");
	printf("|    JAIL   |    +75    |    -50    |    -50    |    +75    |    +75    |  BACK 3   |    FREE   |\n");
	printf("|           |           |           |           |           |           |           |           |\n");
	printf("|  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |\n", mostrarPosicion(tablero, 7, 0), mostrarPosicion(tablero, 7, 1), mostrarPosicion(tablero, 7, 2), mostrarPosicion(tablero, 8, 0), mostrarPosicion(tablero, 8, 1), mostrarPosicion(tablero, 8, 2), mostrarPosicion(tablero, 9, 0), mostrarPosicion(tablero, 9, 1), mostrarPosicion(tablero, 9, 2), mostrarPosicion(tablero, 10, 0), mostrarPosicion(tablero, 10, 1), mostrarPosicion(tablero, 10, 2), mostrarPosicion(tablero, 11, 0), mostrarPosicion(tablero, 11, 1), mostrarPosicion(tablero, 11, 2), mostrarPosicion(tablero, 12, 0), mostrarPosicion(tablero, 12, 1), mostrarPosicion(tablero, 12, 2), mostrarPosicion(tablero, 13, 0), mostrarPosicion(tablero, 13, 1), mostrarPosicion(tablero, 13, 2), mostrarPosicion(tablero, 14, 0), mostrarPosicion(tablero, 14, 1), mostrarPosicion(tablero, 14, 2));
	printf("|           |           |           |           |           |           |           |           |\n");
	printf("+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+\n");
	printf("|           |                                                                       |           |\n");
	printf("|    -25    |                                                                       | FORWARD 3 |\n");
	printf("|           |                                                                       |           |\n");
	printf("|  %c  %c  %c  |                                                                       |  %c  %c  %c  |\n", mostrarPosicion(tablero, 6, 0), mostrarPosicion(tablero, 6, 1), mostrarPosicion(tablero, 6, 2), mostrarPosicion(tablero, 15, 0), mostrarPosicion(tablero, 15, 1), mostrarPosicion(tablero, 15, 2));
	printf("|           |                                                                       |           |\n");
	printf("+-----------+                                                                       +-----------+\n");
	printf("|           |                                                                       |           |\n");
	printf("|    +50    |                                                                       |    +50    |\n");
	printf("|           |                                                                       |           |\n");
	printf("|  %c  %c  %c  |                                                                       |  %c  %c  %c  |\n", mostrarPosicion(tablero, 5, 0), mostrarPosicion(tablero, 5, 1), mostrarPosicion(tablero, 5, 2), mostrarPosicion(tablero, 16, 0), mostrarPosicion(tablero, 16, 1), mostrarPosicion(tablero, 16, 2));
	printf("|           |                                                                       |           |\n");
	printf("+-----------+                                                                       +-----------+\n");
	printf("|           |                                                                       |           |\n");
	printf("|  BACK 2   |                                                                       |   BACK 4  |\n");
	printf("|           |                                                                       |           |\n");
	printf("|  %c  %c  %c  |                                                                       |  %c  %c  %c  |\n", mostrarPosicion(tablero, 4, 0), mostrarPosicion(tablero, 4, 1), mostrarPosicion(tablero, 4, 2), mostrarPosicion(tablero, 17, 0), mostrarPosicion(tablero, 17, 1), mostrarPosicion(tablero, 17, 2));
	printf("|           |                          +-----------------+                          |           |\n");
	printf("+-----------+                          | M O N O P O L Y |                          +-----------+\n");
	printf("|           |                          +-----------------+                          |           |\n");
	printf("|    -25    |                                                                       |    +50    |\n");
	printf("|           |                                                                       |           |\n");
	printf("|  %c  %c  %c  |                                                                       |  %c  %c  %c  |\n", mostrarPosicion(tablero, 3, 0), mostrarPosicion(tablero, 3, 1), mostrarPosicion(tablero, 3, 2), mostrarPosicion(tablero, 18, 0), mostrarPosicion(tablero, 18, 1), mostrarPosicion(tablero, 18, 2));
	printf("|           |                                                                       |           |\n");
	printf("+-----------+                                                                       +-----------+\n");
	printf("|           |                                                                       |           |\n");
	printf("|    +50    |                                                                       |    -50    |\n");
	printf("|           |                                                                       |           |\n");
	printf("|  %c  %c  %c  |                                                                       |  %c  %c  %c  |\n", mostrarPosicion(tablero, 2, 0), mostrarPosicion(tablero, 2, 1), mostrarPosicion(tablero, 2, 2), mostrarPosicion(tablero, 19, 0), mostrarPosicion(tablero, 19, 1), mostrarPosicion(tablero, 19, 2));
	printf("|           |                                                                       |           |\n");
	printf("+-----------+                                                                       +-----------+\n");
	printf("|           |                                                                       |           |\n");
	printf("|    +50    |                                                                       |    -25    |\n");
	printf("|           |                                                                       |           |\n");
	printf("|  %c  %c  %c  |                                                                       |  %c  %c  %c  |\n", mostrarPosicion(tablero, 1, 0), mostrarPosicion(tablero, 1, 1), mostrarPosicion(tablero, 1, 2), mostrarPosicion(tablero, 20, 0), mostrarPosicion(tablero, 20, 1), mostrarPosicion(tablero, 20, 2));
	printf("|           |                                                                       |           |\n");
	printf("+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+\n");
	printf("|           |           |           |           |           |           |           |           |\n");
	printf("|   START   |    -75    |    -25    |  BACK 4   |    +75    | FORWARD 5 |    +75    |    JAIL   |\n");
	printf("|           |           |           |           |           |           |           |           |\n");
	printf("|  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |  %c  %c  %c  |\n", mostrarPosicion(tablero, 0, 0), mostrarPosicion(tablero, 0, 1), mostrarPosicion(tablero, 0, 2), mostrarPosicion(tablero, 27, 0), mostrarPosicion(tablero, 27, 1), mostrarPosicion(tablero, 27, 2), mostrarPosicion(tablero, 26, 0), mostrarPosicion(tablero, 26, 1), mostrarPosicion(tablero, 26, 2), mostrarPosicion(tablero, 25, 0), mostrarPosicion(tablero, 25, 1), mostrarPosicion(tablero, 25, 2), mostrarPosicion(tablero, 24, 0), mostrarPosicion(tablero, 24, 1), mostrarPosicion(tablero, 24, 2), mostrarPosicion(tablero, 23, 0), mostrarPosicion(tablero, 23, 1), mostrarPosicion(tablero, 23, 2), mostrarPosicion(tablero, 22, 0), mostrarPosicion(tablero, 22, 1), mostrarPosicion(tablero, 22, 2), mostrarPosicion(tablero, 21, 0), mostrarPosicion(tablero, 21, 1), mostrarPosicion(tablero, 21, 2));
	printf("|           |           |           |           |           |           |           |           |\n");
	printf("+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+\n");
}

/****************************************************
* 
* Tablero *crearTablero
* 
*****************************************************
* 
* Return: Tablero
* 
*****************************************************
* 
* Descripción: Se crea e inicializa el tablero
* de Monopoly. Se crea y asigna memoria compartida,
* la cual será utilizada por todos los procesos. 
* Además, se asigna la posición inicial de todos
* los jugadores (en START) y la repartición inicial
* de dinero ($100).
* 
****************************************************/


Tablero *crearTablero(){
	int fd;
	Tablero *newTablero;

	fd = shm_open(NAME_SHMEM,O_CREAT| O_RDWR,00600); //crea la memoria compartida
	ftruncate(fd,sizeof(Tablero)); //asigna el espacio a la memoria compartida
	newTablero= mmap(0, sizeof(Tablero), PROT_WRITE, MAP_SHARED, fd, 0);
	newTablero->len = 28;
	for (int i = 0; i < 28; i++){
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

	for (int k = 0; k < 3; k++){
		newTablero->dinero[k] = 100;
		newTablero->casillas[0].jugadores[k] = 1;
	}
	return newTablero;
}

/***********************
* 
* int getJugador
* 
************************
* 
* Parámetros:
* Tablero* 	tablero
* int 		jugador (número de jugador).
* 
************************
* 
* Return: i (posición del jugador en el tablero).
* 
************************
* 
* Descripción: Se busca casilla por casilla
* la posición del jugador buscado.
* 
************************/

int getJugador(Tablero* tablero, int jugador){
	for (int i = 0; i < tablero->len; i++){
		if (tablero->casillas[i].jugadores[jugador] == 1){
			return i;
		}
	}
	return 0;
}

/***********************
* 
* void moveToPos
* 
************************
* 
* Parámetros:
* Tablero* 	tablero
* int 		dado (cantidad de casillas (+ o -) a mover).
* int 		jugador (número de jugador).
* 
************************
* 
* Descripción: Mueve la posición del jugador a la casilla
* correspondiente, de acuerdo al número indicado en la variable
* dado. Cuando el jugador da la vuelta al tablero, se le adicionan $100
* a su dinero, y se reinicia la posición a 0 o más, según sea necesario.
* 
************************/

void moveToPos(Tablero* tablero, int dado, int jugador){
	int posicion = getJugador(tablero, jugador);
	int nuevaposicion = posicion + dado;
	if (nuevaposicion > 27){
		nuevaposicion = nuevaposicion-28;
		tablero->dinero[jugador] += 100;
		printf("Has pasado por START. Ganas +$100\n");
	}
	tablero->casillas[posicion].jugadores[jugador] = 0;
	tablero->casillas[nuevaposicion].jugadores[jugador] = 1;
};

