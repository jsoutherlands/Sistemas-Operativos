#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include "tablero.h"
#include <time.h>
#include <string.h>
#include <math.h>

#define NAME_SHMEM "/tablero1"

int dado(){
	int numero;
	srand(time(NULL));
	numero = (rand()% 6)+1;
	return numero;
}

int main(int argc, char const *argv[]){
	int fd, pid, user = 0, dato;
	int posicion0, posicion1, posicion2;
	char dado0[1];
	char dado1[1];
	char dado2[1];
	int turnos[3];
	Tablero *tablero;
	tablero = crearTablero();
	fd = shm_open(NAME_SHMEM, O_RDWR, sizeof(*tablero));
	tablero = mmap(0, sizeof(*tablero), PROT_WRITE, MAP_SHARED, fd, 0);
	
	//printf("%d\n", getJugador(tablero, 0));

	int pipe01[2], pipe10[2], pipe02[2], pipe20[2], pipe03[2], pipe30[2];
	pipe(pipe01);
	pipe(pipe02);
	pipe(pipe03);
	pipe(pipe10);
	pipe(pipe20);
	pipe(pipe30);



	for(int i=0;i<3;i++){
		pid=fork();
		//printf("%d\n", pid);
		user=i;
		if(pid==0){ //proceso hijo!
			printf("Soy el proceso %d (usuario %d) y mi padre es %d\n", getpid(), user, getppid());
			break;
		}

	}

	//Cerramos al padre
	if (pid == 0){ //cerramos el 1 para que el padre lea. // cerramos los 0 para que el hijo escriba.
		close(pipe01[1]);
		close(pipe10[0]);
		close(pipe02[1]);
		close(pipe20[0]);
		close(pipe03[1]);
		close(pipe30[0]);
		//while(1){
			if (user == 0){ // jugador 1 UNO
				char buffhijo0[10];
				printf("Soy el hijo\n");
				write(pipe10[1], "0", 1);
				printf("Antes de leer\n");
				while(read(pipe01[0], buffhijo0, sizeof(buffhijo0)) < 0){};
				printf("Este es el proceso ANTES DE LEÍDO %d", getpid());
				printf("Leído\n");
				int dadito = dado();
				printf("Dado = %d\n", dadito);
				moveToPos(tablero, dadito, 0);
				int dato = tablero->casillas[getJugador(tablero, 0)].dato;
				printf("Este es el proceso %d", getpid());
				if(dato == -2){
					write(pipe10[1], "a", 1);
				}else if(dato == -5){
					write(pipe10[1], "b", 1);
				}else if(dato == -3){
					write(pipe10[1], "c", 1);
				}else if(dato == 0){
					write(pipe10[1], "#", 1);
				}else if(dato == 5){
					write(pipe10[1], "d", 1);
				}else if(dato == -4){
					write(pipe10[1], "e", 1);
				}else if(dato == 3){
					write(pipe10[1], "f", 1);
				}else if(dato == 50){
					write(pipe10[1], "g", 1);
				}else if(dato == 75){
					write(pipe10[1], "h", 1);
				}else if(dato == -25){
					write(pipe10[1], "i", 1);
				}else if(dato == -50){
					write(pipe10[1], "j", 1);
				}else if(dato == -75){
					write(pipe10[1], "k", 1);
				}else if(dato == 100){
					write(pipe10[1], "l", 1);
				}
			}else if (user == 1){ // jugador 1 UNO
				char buffhijo1[10];
				printf("Soy el hijo\n");
				write(pipe20[1], "0", 1);
				printf("Antes de leer\n");
				while(read(pipe02[0], buffhijo1, sizeof(buffhijo1)) < 0){};
				printf("Este es el proceso ANTES DE LEÍDO %d", getpid());
				printf("Leído\n");
				int dadito = dado();
				printf("Dado = %d\n", dadito);
				moveToPos(tablero, dadito, 0);
				int dato = tablero->casillas[getJugador(tablero, 1)].dato;
				printf("Este es el proceso %d", getpid());
				if(dato == -2){
					write(pipe20[1], "a", 1);
				}else if(dato == -5){
					write(pipe20[1], "b", 1);
				}else if(dato == -3){
					write(pipe20[1], "c", 1);
				}else if(dato == 0){
					write(pipe20[1], "#", 1);
				}else if(dato == 5){
					write(pipe20[1], "d", 1);
				}else if(dato == -4){
					write(pipe20[1], "e", 1);
				}else if(dato == 3){
					write(pipe20[1], "f", 1);
				}else if(dato == 50){
					write(pipe20[1], "g", 1);
				}else if(dato == 75){
					write(pipe20[1], "h", 1);
				}else if(dato == -25){
					write(pipe20[1], "i", 1);
				}else if(dato == -50){
					write(pipe20[1], "j", 1);
				}else if(dato == -75){
					write(pipe20[1], "k", 1);
				}else if(dato == 100){
					write(pipe20[1], "l", 1);
				}
			}else if (user == 2){ // jugador 1 UNO
				char buffhijo2[10];
				printf("Soy el hijo\n");
				write(pipe30[1], "0", 1);
				printf("Antes de leer\n");
				while(read(pipe03[0], buffhijo2, sizeof(buffhijo2)) < 0){};
				printf("Este es el proceso ANTES DE LEÍDO %d", getpid());
				printf("Leído\n");
				int dadito = dado();
				printf("Dado = %d\n", dadito);
				moveToPos(tablero, dadito, 0);
				int dato = tablero->casillas[getJugador(tablero, 2)].dato;
				printf("Este es el proceso %d", getpid());
				if(dato == -2){
					write(pipe30[1], "a", 1);
				}else if(dato == -5){
					write(pipe30[1], "b", 1);
				}else if(dato == -3){
					write(pipe30[1], "c", 1);
				}else if(dato == 0){
					write(pipe30[1], "#", 1);
				}else if(dato == 5){
					write(pipe30[1], "d", 1);
				}else if(dato == -4){
					write(pipe30[1], "e", 1);
				}else if(dato == 3){
					write(pipe30[1], "f", 1);
				}else if(dato == 50){
					write(pipe30[1], "g", 1);
				}else if(dato == 75){
					write(pipe30[1], "h", 1);
				}else if(dato == -25){
					write(pipe30[1], "i", 1);
				}else if(dato == -50){
					write(pipe30[1], "j", 1);
				}else if(dato == -75){
					write(pipe30[1], "k", 1);
				}else if(dato == 100){
					write(pipe30[1], "l", 1);
				}
			}
		//}
	}else{
		close(pipe01[0]);
		close(pipe10[1]);
		close(pipe02[0]);
		close(pipe20[1]);
		close(pipe03[0]);
		close(pipe30[1]);
		turnos[0] = 0;

		while(tablero->dinero[0] < 500 || tablero->dinero[1] < 500 || tablero->dinero[2] < 500){
			if (turnos[0] == 0){
				char buff[10];
				printf("Soy el padre\n");
				while(read(pipe10[0], buff, sizeof(buff)) < 0){};
				write(pipe01[1], "0", 1);
				while(read(pipe10[0], buff, sizeof(buff)) < 0){};
				printf("EL BUFF ES: %s", buff);
				printf("El valor de la celda es: %s", buff);
				printf("Hol terminea\n");

				//moveToPos(tablero, buff, 0);
				posicion0 = getJugador(tablero, 0);
				dato = tablero->casillas[posicion0].dato;
				if (strcmp(buff, "a") == 0){//-2
					moveToPos(tablero, -2, 0);
					tablero->dinero[0] += 50;
				}else if(strcmp(buff, "b") == 0){//-5
					continue; // JAIL
				}else if(strcmp(buff, "c") == 0){//-3
					moveToPos(tablero, -3, 0);
					if(tablero->dinero[0] <50){
							tablero->dinero[0] = 0;	
					}else{
						tablero->dinero[0] -= 50;
					}
				}else if(strcmp(buff, "#") == 0){
					continue;
					//decir que caýó en libre
				}else if(strcmp(buff, "d") == 0){//5
					moveToPos(tablero, 5, 0);
				}else if(strcmp(buff, "e") == 0){ //-4
					moveToPos(tablero, -4, 0);
					if(tablero->casillas[getJugador(tablero, 0)].dato == -5){
						continue; //JAIL CAMBIAR
					}else{
						moveToPos(tablero, -3, 0);
						if(tablero->dinero[0] <50){
							tablero->dinero[0] = 0;	
						}else{
							tablero->dinero[0] -= 50;
						}
					}
				}else if (strcmp(buff, "f") == 0){
					moveToPos(tablero, 3, 0);
					tablero->dinero[0] += 50;
				}else if(strcmp(buff, "g") == 0){
					tablero->dinero[0] += 50;
				}else if(strcmp(buff, "h") == 0){
					tablero->dinero[0] += 75;
				}else if(strcmp(buff, "i") == 0){
					if(tablero->dinero[0] <25){
						tablero->dinero[0] = 0;
					}else{
						tablero->dinero[0] -= 25;
					}
					
				}else if(strcmp(buff, "j") == 0){
					if(tablero->dinero[0] <50){
						tablero->dinero[0] = 0;	
					}else{
						tablero->dinero[0] -= 50;
					}
					
				}else if(strcmp(buff, "k") == 0){
					if(tablero->dinero[0] < 75){
						tablero->dinero[0] = 0;
					}else{
						tablero->dinero[0] -= 75;
					}
				}else if(strcmp(buff, "l") == 0){ //START
					continue;
				}else{
					printf("No pude entrar puta la wea\n");
				}
				printf("Lo logré señores\n");
				turnos[0] == 1;
				write(pipe01[1], "1", 1);
			}else if (turnos[1] == 0){
				char buff[10];
				printf("Soy el padre del jugador 1\n");
				while(read(pipe20[0], buff, sizeof(buff)) < 0){};
				write(pipe02[1], "0", 1);
				while(read(pipe20[0], buff, sizeof(buff)) < 0){};
				printf("EL BUFF ES: %s", buff);
				printf("El valor de la celda es: %s", buff);
				printf("Hol terminea\n");

				//moveToPos(tablero, buff, 0);
				posicion1 = getJugador(tablero, 1);
				dato = tablero->casillas[posicion1].dato;
				if (strcmp(buff, "a") == 0){//-2
					moveToPos(tablero, -2, 1);
					tablero->dinero[1] += 50;
				}else if(strcmp(buff, "b") == 0){//-5
					continue; // JAIL
				}else if(strcmp(buff, "c") == 0){//-3
					moveToPos(tablero, -3, 1);
					if(tablero->dinero[1] <50){
							tablero->dinero[1] = 0;	
					}else{
						tablero->dinero[1] -= 50;
					}
				}else if(strcmp(buff, "#") == 0){
					continue;
					//decir que caýó en libre
				}else if(strcmp(buff, "d") == 0){//5
					moveToPos(tablero, 5, 1);
				}else if(strcmp(buff, "e") == 0){ //-4
					moveToPos(tablero, -4, 1);
					if(tablero->casillas[getJugador(tablero, 1)].dato == -5){
						continue; //JAIL CAMBIAR
					}else{
						moveToPos(tablero, -3, 1);
						if(tablero->dinero[1] <50){
							tablero->dinero[1] = 0;	
						}else{
							tablero->dinero[1] -= 50;
						}
					}
				}else if (strcmp(buff, "f") == 0){
					moveToPos(tablero, 3, 1);
					tablero->dinero[1] += 50;
				}else if(strcmp(buff, "g") == 0){
					tablero->dinero[1] += 50;
				}else if(strcmp(buff, "h") == 0){
					tablero->dinero[1] += 75;
				}else if(strcmp(buff, "i") == 0){
					if(tablero->dinero[1] <25){
						tablero->dinero[1] = 0;
					}else{
						tablero->dinero[1] -= 25;
					}
					
				}else if(strcmp(buff, "j") == 0){
					if(tablero->dinero[1] <50){
						tablero->dinero[1] = 0;	
					}else{
						tablero->dinero[1] -= 50;
					}
					
				}else if(strcmp(buff, "k") == 0){
					if(tablero->dinero[1] < 75){
						tablero->dinero[1] = 0;
					}else{
						tablero->dinero[1] -= 75;
					}
				}else if(strcmp(buff, "l") == 0){ //START
					continue;
				}else{
					printf("No pude entrar puta la wea\n");
				}
				printf("Lo logré señores\n");
				turnos[1] == 1;
				write(pipe02[1], "1", 1);
			}else if (turnos[2] == 0){
				char buff[10];
				printf("Soy el padre del jugador 2\n");
				while(read(pipe30[0], buff, sizeof(buff)) < 0){};
				write(pipe03[1], "0", 1);
				while(read(pipe30[0], buff, sizeof(buff)) < 0){};
				printf("EL BUFF ES: %s", buff);
				printf("El valor de la celda es: %s", buff);
				printf("Hol terminea\n");

				//moveToPos(tablero, buff, 0);
				posicion2 = getJugador(tablero, 2);
				dato = tablero->casillas[posicion2].dato;
				if (strcmp(buff, "a") == 0){//-2
					moveToPos(tablero, -2, 2);
					tablero->dinero[2] += 50;
				}else if(strcmp(buff, "b") == 0){//-5
					continue; // JAIL
				}else if(strcmp(buff, "c") == 0){//-3
					moveToPos(tablero, -3, 2);
					if(tablero->dinero[2] <50){
							tablero->dinero[2] = 0;	
					}else{
						tablero->dinero[2] -= 50;
					}
				}else if(strcmp(buff, "#") == 0){
					continue;
					//decir que caýó en libre
				}else if(strcmp(buff, "d") == 0){//5
					moveToPos(tablero, 5, 2);
				}else if(strcmp(buff, "e") == 0){ //-4
					moveToPos(tablero, -4, 2);
					if(tablero->casillas[getJugador(tablero, 2)].dato == -5){
						continue; //JAIL CAMBIAR
					}else{
						moveToPos(tablero, -3, 2);
						if(tablero->dinero[2] <50){
							tablero->dinero[2] = 0;	
						}else{
							tablero->dinero[2] -= 50;
						}
					}
				}else if (strcmp(buff, "f") == 0){
					moveToPos(tablero, 3, 2);
					tablero->dinero[2] += 50;
				}else if(strcmp(buff, "g") == 0){
					tablero->dinero[2] += 50;
				}else if(strcmp(buff, "h") == 0){
					tablero->dinero[2] += 75;
				}else if(strcmp(buff, "i") == 0){
					if(tablero->dinero[2] <25){
						tablero->dinero[2] = 0;
					}else{
						tablero->dinero[2] -= 25;
					}
					
				}else if(strcmp(buff, "j") == 0){
					if(tablero->dinero[2] <50){
						tablero->dinero[2] = 0;	
					}else{
						tablero->dinero[2] -= 50;
					}
					
				}else if(strcmp(buff, "k") == 0){
					if(tablero->dinero[2] < 75){
						tablero->dinero[2] = 0;
					}else{
						tablero->dinero[2] -= 75;
					}
				}else if(strcmp(buff, "l") == 0){ //START
					continue;
				}else{
					printf("No pude entrar puta la wea\n");
				}
				printf("Lo logré señores\n");
				turnos[2] == 1;
				write(pipe03[1], "1", 1);
			}
			turnos[0] = 0;
			turnos[1] = 0;
			turnos[2] = 0;
		}
		
	}
}
/*
	for (int i = 0; i < 3; i++){
		if (user == 1){
			while((read(pipe01[0],&dato,sizeof(dato)))<0){};
			if (strcmp(dato, "100") == 0){
				int dadito = dado();
				avanzar(tablero, dadito, user);
				
			}else if (strcmp(dato, "50") == 0){
				/* code *//*
			}
		}else if (user == 2){
			/* code *//*
		}
	}

	while(1);

	return 0;
}

/*
typedef struct _nodo{
	int posicion;
	int dato;
	struct _nodo *prev;
	struct _nodo *next;
} tipoNodo;

typedef struct tablero{
	tipoNodo *head;
	tipoNodo *tail;
	tipoNodo *jugador;
	// VER QUE VOLA CON LOS JUGADORES
	int len;
} Tablero;

Tablero *createTablero(){
	Tablero *newTablero=(Tablero *)malloc(sizeof(Tablero)); //pide memoria para la lista
	newTablero->head=NULL;
	newTablero->tail=NULL;
	newTablero->jugador=NULL;
	newTablero->len=0;
	return newTablero;
}

tipoNodo *crearNodo(){
	tipoNodo *newtipoNodo=(tipoNodo *)malloc(sizeof(tipoNodo)); //memoria para la casilla del tablero
	newtipoNodo->next=NULL;
	newtipoNodo->prev=NULL;
	return newtipoNodo;
}

void insertEmpty(Tablero *pTablero){
	tipoNodo *newtipoNodo=crearNodo();
	pTablero->head=newtipoNodo;
	pTablero->tail=newtipoNodo;
	pTablero->jugador=newtipoNodo;
	pTablero->len++;
	newtipoNodo->posicion=1;
}



void insertar(Tablero *pTablero, tipoNodo *aux, int dato, int posicion){
	tipoNodo *newNodo=crearNodo();
	aux->next=newNodo;
	newNodo->dato = dato;
	newNodo->prev=aux;
	newNodo->posicion=posicion;
	pTablero->tail=newNodo;
	pTablero->len++;
}


void deleteAll(Tablero *pTablero){
    tipoNodo *aux=pTablero->head;
    tipoNodo *delete;
    while(pTablero->len!=0){
        delete=aux;
        aux=aux->next;
        free(delete);
        pTablero->len--;
    }
    free(pTablero);
}

tipoNodo *getPos(Tablero *pTablero, int posicion){
	tipoNodo* aux = pTablero->head;
	while(aux->posicion != posicion){
		aux = aux->next;
	}
	return aux;
	};

void showBoard(Tablero *pTablero){
	int i;
	tipoNodo *aux=pTablero->head;
	aux = aux->next;

	for (i = 0; i < 7; i++)
	{
		aux = aux->next;
	}

	for (i = 7; i < 15; i++)
	{
		printf("[ %d ]", aux->dato);
		aux=aux->next;
	}
	printf("\n");
}


int main(){

	Tablero *tablero;
	tablero = createTablero();
	fillBoard(tablero);
	printf("Hola\n");
	int fd = shm_open(NAME_SHMEM, O_RDWR, sizeof(*tablero));

	printf("Hola2\n");
	tablero = mmap(0, sizeof(*tablero), PROT_WRITE, MAP_SHARED, fd, 0);
	printf("Hola3\n");
	//showBoard(tablero);
	//deleteAll(tablero);
	return 0;
}

*/


// 0 -> que le toca al proceso hijo //no se puede usar

// 1 -> free
// 2 -> +25
// 3 -> +50
// 4 -> +75
// 5 -> +100
// 6 -> -25
// 7 -> -50
// 8 -> +75
