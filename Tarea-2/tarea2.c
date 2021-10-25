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
	int fd, pid, user = 0;
	char dato[3];
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
		if (user == 0) // jugador 1 UNO
		{
			
			while(read(pipe01[0], &dato, sizeof(dato)) < 0){};
			if (strcmp(dato, "0") == 0)
			{	
				printf("Tablero len %d\n", tablero->len);
				int dadito = dado();
				printf("Holasdfsdf %d\n", tablero->casillas[getJugador(tablero, 0)].dato);
				avanzar(tablero, dadito, 0);
				printf("Holasdeefsdf %d\n", tablero->casillas[getJugador(tablero, 0)].dato);
				strcpy(dato, "1");
				write(pipe10[0], &dato, sizeof(dato));
				
				//strcpy(dato, tablero->casillas[getJugador(tablero, 1)].dato);
			}
		}
		printf("Hola %d\n", getpid());
	}else{
		close(pipe01[0]);
		close(pipe10[1]);
		close(pipe02[0]);
		close(pipe20[1]);
		close(pipe03[0]);
		close(pipe30[1]);

		for (int i = 0; i <= 3; i++){
			if (i == 3){
				i = 0;
			}else if (i == 0){
				strcpy(dato, "0");
				write(pipe01[1], &dato, sizeof(dato));
				while(read(pipe10[0], &dato, sizeof(dato)) < 0){};
				printf("%s\n", dato);
			}
		}

		/*while(tablero->dinero[0] < 500 || tablero->dinero[1] < 500 || tablero->dinero[2] < 500){
			while(read(pipe10[0], &dato, sizeof(dato)) < 0){};
			write();
		}*/
		
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
