#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include "tablero.h"
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#define NAME_SHMEM "/tablero1"

/****************************************************
* 
* int dado
* 
*****************************************************
* 
* Return: numero
* 
*****************************************************
* 
* Descripción: Escoge un número al azar entre 1 y 6.
* 
****************************************************/

int dado(){
	int numero;
	srand(time(NULL));
	numero = (rand()% 6)+1;
	return numero;
}

int main(int argc, char const *argv[]){
	int fd, pid, user = 0, rondas = 1;
	int posicion0, posicion1, posicion2;
	int turnos[3];
	int turnoJail0 = 0;
	int turnoJail1 = 0;
	int turnoJail2 = 0;
	Tablero *tablero;
	tablero = crearTablero();
	fd = shm_open(NAME_SHMEM, O_RDWR, sizeof(*tablero));
	tablero = mmap(0, sizeof(*tablero), PROT_WRITE, MAP_SHARED, fd, 0);
	int pipe01[2], pipe10[2], pipe02[2], pipe20[2], pipe03[2], pipe30[2];
	pipe(pipe01);
	pipe(pipe02);
	pipe(pipe03);
	pipe(pipe10);
	pipe(pipe20);
	pipe(pipe30);


	turnos[0] = 0;
	turnos[1] = 0;
	turnos[2] = 0;

	printf("\n\nBienvenidas y bienvenidos al mejor juego del mundo: Monopoly SO\n\n");

	mostrarTablero(tablero);

	for(int i=0;i<3;i++){
		pid=fork();
		user=i;
		if(pid==0){ //proceso hijo!
			tablero->pids[i] = getpid();
			break;
		}
	}

	if (pid == 0){
		close(pipe01[1]);
		close(pipe10[0]);
		close(pipe02[1]);
		close(pipe20[0]);
		close(pipe03[1]);
		close(pipe30[0]);
	}else{
		close(pipe01[0]);
		close(pipe10[1]);
		close(pipe02[0]);
		close(pipe20[1]);
		close(pipe03[0]);
		close(pipe30[1]);
	}

	while(tablero->dinero[0] < 500 && tablero->dinero[1] < 500 && tablero->dinero[2] < 500){
		if (pid == 0){
			if (user == 0){
				char buffhijo0[1];
				while(read(pipe01[0], buffhijo0, sizeof(buffhijo0)) < 0){};
				sleep(1);
				char scan;
				scanf("%c",&scan);
				int dadito0 = dado();
				printf("Dado = %d\n", dadito0);
				moveToPos(tablero, dadito0, 0);
				int dato0 = tablero->casillas[getJugador(tablero, 0)].dato;
				if(dato0 == -2){
					write(pipe10[1], "a", 1);
				}else if(dato0 == -5){
					write(pipe10[1], "b", 1);
				}else if(dato0 == -3){
					write(pipe10[1], "c", 1);
				}else if(dato0 == 0){
					write(pipe10[1], "#", 1);
				}else if(dato0 == 5){
					write(pipe10[1], "d", 1);
				}else if(dato0 == -4){
					write(pipe10[1], "e", 1);
				}else if(dato0 == 3){
					write(pipe10[1], "f", 1);
				}else if(dato0 == 50){
					write(pipe10[1], "g", 1);
				}else if(dato0 == 75){
					write(pipe10[1], "h", 1);
				}else if(dato0 == -25){
					write(pipe10[1], "i", 1);
				}else if(dato0 == -50){
					write(pipe10[1], "j", 1);
				}else if(dato0 == -75){
					write(pipe10[1], "k", 1);
				}else if(dato0 == 100){
					write(pipe10[1], "l", 1);
				}
			}else if (user == 1){
				char buffhijo1[1];
				while(read(pipe02[0], buffhijo1, sizeof(buffhijo1)) < 0){};
				sleep(1);
				int dadito1 = dado();
				printf("Dado = %d\n", dadito1);
				moveToPos(tablero, dadito1, 1);
				int dato1 = tablero->casillas[getJugador(tablero, 1)].dato;
				if(dato1 == -2){
					write(pipe20[1], "a", 1);
				}else if(dato1 == -5){
					write(pipe20[1], "b", 1);
				}else if(dato1 == -3){
					write(pipe20[1], "c", 1);
				}else if(dato1 == 0){
					write(pipe20[1], "#", 1);
				}else if(dato1 == 5){
					write(pipe20[1], "d", 1);
				}else if(dato1 == -4){
					write(pipe20[1], "e", 1);
				}else if(dato1 == 3){
					write(pipe20[1], "f", 1);
				}else if(dato1 == 50){
					write(pipe20[1], "g", 1);
				}else if(dato1 == 75){
					write(pipe20[1], "h", 1);
				}else if(dato1 == -25){
					write(pipe20[1], "i", 1);
				}else if(dato1 == -50){
					write(pipe20[1], "j", 1);
				}else if(dato1 == -75){
					write(pipe20[1], "k", 1);
				}else if(dato1 == 100){
					write(pipe20[1], "l", 1);
				}
			}else if (user == 2){
				char buffhijo2[1];
				while(read(pipe03[0], buffhijo2, sizeof(buffhijo2)) < 0){};
				sleep(1);
				int dadito2 = dado();
				printf("Dado = %d\n", dadito2);
				moveToPos(tablero, dadito2, 2);
				int dato2 = tablero->casillas[getJugador(tablero, 2)].dato;
				if(dato2 == -2){
					write(pipe30[1], "a", 1);
				}else if(dato2 == -5){
					write(pipe30[1], "b", 1);
				}else if(dato2 == -3){
					write(pipe30[1], "c", 1);
				}else if(dato2 == 0){
					write(pipe30[1], "#", 1);
				}else if(dato2 == 5){
					write(pipe30[1], "d", 1);
				}else if(dato2 == -4){
					write(pipe30[1], "e", 1);
				}else if(dato2 == 3){
					write(pipe30[1], "f", 1);
				}else if(dato2 == 50){
					write(pipe30[1], "g", 1);
				}else if(dato2 == 75){
					write(pipe30[1], "h", 1);
				}else if(dato2 == -25){
					write(pipe30[1], "i", 1);
				}else if(dato2 == -50){
					write(pipe30[1], "j", 1);
				}else if(dato2 == -75){
					write(pipe30[1], "k", 1);
				}else if(dato2 == 100){
					write(pipe30[1], "l", 1);
				}
			}
		}else{ // PADRE
			if (turnos[0] == 0){
				char buff[1];
				printf("¡Es tu turno!\n");
				printf("Tu saldo actual es $%d\n", tablero->dinero[0]);
				printf("Presiona ENTER para lanzar los dados...\n");
				write(pipe01[1], "0", 1);
				while(read(pipe10[0], buff, sizeof(buff)) < 0){};
				posicion0 = getJugador(tablero, 0);
				if (strcmp(buff, "a") == 0){//-2 back 2
					moveToPos(tablero, -2, 0);
					tablero->dinero[0] += 50;
					printf("Has caído en la casilla BACK 2...\n");
					printf("Retrocedes 2 espacios...\n");
					printf("Has caído en +$50...\n");
					printf("Ganas $50...\n");
				}else if(strcmp(buff, "b") == 0){//-5
					printf("Entraste a la cárcel, pierdes un turno *guiño guiño*\n"); // JAIL
					turnoJail0 = rondas;
					turnos[0] = 1;
				}else if(strcmp(buff, "c") == 0){//-3
					moveToPos(tablero, -3, 0);
					printf("Has caído en la casilla BACK 3...\n");
					printf("Retrocedes 3 espacios...\n");
					printf("Has caído en -$50...\n");
					printf("Pierdes $50...\n");
					if(tablero->dinero[0] <50){
						tablero->dinero[0] = 0;	
					}else{
						tablero->dinero[0] -= 50;
					}
				}else if(strcmp(buff, "#") == 0){
					printf("Entraste a la libre, *booooorinnng!!!*\n"); // LIBRE
				}else if(strcmp(buff, "d") == 0){//5
					printf("Has caído en la casilla FORWARD 5...\n");
					printf("Avanzas 5 espacios...\n");
					printf("Has caído en START...\n");
					moveToPos(tablero, 5, 0);
				}else if(strcmp(buff, "e") == 0){ //-4
					moveToPos(tablero, -4, 0);
					printf("Has caído en la casilla BACK 4...\n");
					printf("Retrocedes 3 espacios...\n");
					if(tablero->casillas[posicion0].dato == -5){
						printf("Has caído en JAIL, pierdes un turno *guiño guiño*\n"); // JAIL
						turnoJail0 = rondas;
						turnos[0] = 1;
					}else{
						printf("Has caído en la casilla BACK 3...\n");
						printf("Retrocedes 3 espacios...\n");
						printf("Has caído en -$50...\n");
						printf("Pierdes $50...\n");
						moveToPos(tablero, -3, 0);
						if(tablero->dinero[0] <50){
							tablero->dinero[0] = 0;	
						}else{
							tablero->dinero[0] -= 50;
						}
					}
				}else if (strcmp(buff, "f") == 0){ // +3 forward 3
					printf("Has caído en la casilla FORWARD 3...\n");
					printf("Avanzas 3 espacios...\n");
					printf("Has caído en +$50...\n");
					printf("Ganas $50.\n");
					moveToPos(tablero, 3, 0);
					tablero->dinero[0] += 50;
					
				}else if(strcmp(buff, "g") == 0){
					tablero->dinero[0] += 50;
					printf("Has caído en la casilla +$50...\n");
					printf("Ganas $50...\n");
				}else if(strcmp(buff, "h") == 0){
					tablero->dinero[0] += 75;
					printf("Has caído en la casilla +$75...\n");
					printf("Ganas $75...\n");
				}else if(strcmp(buff, "i") == 0){
					printf("Has caído en la casilla -$25...\n");
					printf("Pierdes $25...\n");
					if(tablero->dinero[0] <25){
						tablero->dinero[0] = 0;
					}else{
						tablero->dinero[0] -= 25;
					}
					
				}else if(strcmp(buff, "j") == 0){
					printf("Has caído en la casilla -$50...\n");
					printf("Pierdes $50...\n");
					if(tablero->dinero[0] <50){
						tablero->dinero[0] = 0;	
					}else{
						tablero->dinero[0] -= 50;
					}
					
				}else if(strcmp(buff, "k") == 0){
					printf("Has caído en la casilla -$75...\n");
					printf("Pierdes $75...\n");
					if(tablero->dinero[0] < 75){
						tablero->dinero[0] = 0;
					}else{
						tablero->dinero[0] -= 75;
					}
				}else if(strcmp(buff, "l") == 0){ //START
					printf(" ");
				}
				printf("Tu nuevo saldo es $%d\n\n\n", tablero->dinero[0]);
				turnos[0] = 1;
				if(tablero->dinero[0] >=500){
					break;
				}
			}
			if (turnos[1] == 0){
				printf("¡Es el turno del Jugador 2!\n");
				sleep(1);
				printf("El saldo actual del Jugador 2 es $%d\n", tablero->dinero[1]);
				char buff[1];
				write(pipe02[1], "0", 1);
				while(read(pipe20[0], buff, sizeof(buff)) < 0){};
				posicion1 = getJugador(tablero, 1);
				if (strcmp(buff, "a") == 0){//-2 back 2
					moveToPos(tablero, -2, 1);
					tablero->dinero[1] += 50;
					printf("El jugador 2 ha caído en la casilla BACK 2...\n");
					printf("El jugador 2 retrocede 2 espacios...\n");
					printf("El jugador 2 ha caído en +$50...\n");
					printf("El jugador 2 gana $50...\n");
				}else if(strcmp(buff, "b") == 0){//-5
					printf("El jugador 2 ha caído en JAIL, pierde un turno *guiño guiño*\n"); // JAIL
					turnoJail1 = rondas;
					turnos[1] = 1;
				}else if(strcmp(buff, "c") == 0){//-3
					moveToPos(tablero, -3, 1);
					printf("El jugador 2 ha caído en la casilla BACK 3...\n");
					printf("El jugador 2 retrocede 3 espacios...\n");
					printf("El jugador 2 ha caído en -$50...\n");
					printf("El jugador 2 pierde $50...\n");
					if(tablero->dinero[1] <50){
						tablero->dinero[1] = 0;	
					}else{
						tablero->dinero[1] -= 50;
					}
				}else if(strcmp(buff, "#") == 0){
					printf("Entraste a la libre, *booooorinnng!!!*\n"); // LIBRE
				}else if(strcmp(buff, "d") == 0){//5
					printf("El jugador 2 ha caído en la casilla FORWARD 5...\n");
					printf("El jugador 2 avanza 5 espacios...\n");
					printf("El jugador 2 ha caído en START...\n");
					moveToPos(tablero, 5, 1);
				}else if(strcmp(buff, "e") == 0){ //-4
					moveToPos(tablero, -4, 1);
					printf("El jugador 2 ha caído en la casilla BACK 4...\n");
					printf("El jugador 2 retrocede 3 espacios...\n");
					if(tablero->casillas[posicion1].dato == -5){
						printf("El jugador 2 ha caído en JAIL, pierde un turno *guiño guiño*\n"); // JAIL
						turnoJail1 = rondas;
						turnos[1] = 1;
					}else{
						printf("El jugador 2 ha caído en la casilla BACK 3...\n");
						printf("El jugador 2 retrocede 3 espacios...\n");
						printf("El jugador 2 ha caído en -$50...\n");
						printf("El jugador 2 pierde $50...\n");
						moveToPos(tablero, -3, 1);
						if(tablero->dinero[1] <50){
							tablero->dinero[1] = 0;	
						}else{
							tablero->dinero[1] -= 50;
						}
					}
				}else if (strcmp(buff, "f") == 0){ // +3 forward 3
					printf("El jugador 2 ha caído en la casilla FORWARD 3...\n");
					printf("El jugador 2 avanza 3 espacios...\n");
					printf("El jugador 2 ha caído en +$50...\n");
					printf("El jugador 2 gana $50.\n");
					moveToPos(tablero, 3, 1);
					tablero->dinero[1] += 50;
					
				}else if(strcmp(buff, "g") == 0){
					tablero->dinero[1] += 50;
					printf("El jugador 2 ha caído en la casilla +$50...\n");
					printf("El jugador 2 gana $50...\n");
				}else if(strcmp(buff, "h") == 0){
					tablero->dinero[1] += 75;
					printf("El jugador 2 ha caído en la casilla +$75...\n");
					printf("El jugador 2 gana $75...\n");
				}else if(strcmp(buff, "i") == 0){
					printf("El jugador 2 ha caído en la casilla -$25...\n");
					printf("El jugador 2 pierde $25...\n");
					if(tablero->dinero[1] <25){
						tablero->dinero[1] = 0;
					}else{
						tablero->dinero[1] -= 25;
					}
					
				}else if(strcmp(buff, "j") == 0){
					printf("El jugador 2 ha caído en la casilla -$50...\n");
					printf("El jugador 2 pierde $50...\n");
					if(tablero->dinero[1] <50){
						tablero->dinero[1] = 0;	
					}else{
						tablero->dinero[1] -= 50;
					}
					
				}else if(strcmp(buff, "k") == 0){
					printf("El jugador 2 ha caído en la casilla -$75...\n");
					printf("El jugador 2 pierde $75...\n");
					if(tablero->dinero[1] < 75){
						tablero->dinero[1] = 0;
					}else{
						tablero->dinero[1] -= 75;
					}
				}else if(strcmp(buff, "l") == 0){ //START
					printf(" ");
				}
				printf("El nuevo saldo del Jugador 2 es $%d\n\n\n", tablero->dinero[1]);
				turnos[1] = 1;
				if(tablero->dinero[1] >=500){
					break;
				}
			}
			if (turnos[2] == 0){
				printf("¡Es el turno del Jugador 3!\n");
				sleep(1);
				printf("El saldo actual del Jugador 3 es $%d\n", tablero->dinero[2]);
				char buff[1];
				write(pipe03[1], "0", 1);
				while(read(pipe30[0], buff, sizeof(buff)) < 0){};
				posicion2 = getJugador(tablero, 2);
				if (strcmp(buff, "a") == 0){//-2 back 2
					moveToPos(tablero, -2, 2);
					tablero->dinero[2] += 50;
					printf("El jugador 3 ha caído en la casilla BACK 2...\n");
					printf("El jugador 3 retrocede 2 espacios...\n");
					printf("El jugador 3 ha caído en +$50...\n");
					printf("El jugador 3 gana $50...\n");
				}else if(strcmp(buff, "b") == 0){//-5
					printf("El jugador 3 ha caído en JAIL, pierde un turno *guiño guiño*\n"); // JAIL
					turnoJail2 = rondas;
					turnos[2] = 1;
				}else if(strcmp(buff, "c") == 0){//-3
					moveToPos(tablero, -3, 2);
					printf("El jugador 3 ha caído en la casilla BACK 3...\n");
					printf("El jugador 3 retrocede 3 espacios...\n");
					printf("El jugador 3 ha caído en -$50...\n");
					printf("El jugador 3 pierde $50...\n");
					if(tablero->dinero[2] <50){
						tablero->dinero[2] = 0;	
					}else{
						tablero->dinero[2] -= 50;
					}
				}else if(strcmp(buff, "#") == 0){
					printf("Entraste a la libre, *booooorinnng!!!*\n"); // LIBRE
				}else if(strcmp(buff, "d") == 0){//5
					printf("El jugador 3 ha caído en la casilla FORWARD 5...\n");
					printf("El jugador 3 avanza 5 espacios...\n");
					printf("El jugador 3 ha caído en START...\n");
					moveToPos(tablero, 5, 2);
				}else if(strcmp(buff, "e") == 0){ //-4
					moveToPos(tablero, -4, 2);
					printf("El jugador 3 ha caído en la casilla BACK 4...\n");
					printf("El jugador 3 retrocede 3 espacios...\n");
					if(tablero->casillas[posicion2].dato == -5){
						printf("El jugador 3 ha caído en JAIL, pierde un turno *guiño guiño*\n"); // JAIL
						turnoJail2 = rondas;
						turnos[2] = 1;
					}else{
						printf("El jugador 3 ha caído en la casilla BACK 3...\n");
						printf("El jugador 3 retrocede 3 espacios...\n");
						printf("El jugador 3 ha caído en -$50...\n");
						printf("El jugador 3 pierde $50...\n");
						moveToPos(tablero, -3, 2);
						if(tablero->dinero[2] <50){
							tablero->dinero[2] = 0;	
						}else{
							tablero->dinero[2] -= 50;
						}
					}
				}else if (strcmp(buff, "f") == 0){ // +3 forward 3
					printf("El jugador 3 ha caído en la casilla FORWARD 3...\n");
					printf("El jugador 3 avanza 3 espacios...\n");
					printf("El jugador 3 ha caído en +$50...\n");
					printf("El jugador 3 gana $50.\n");
					moveToPos(tablero, 3, 2);
					tablero->dinero[2] += 50;
					
				}else if(strcmp(buff, "g") == 0){
					tablero->dinero[2] += 50;
					printf("El jugador 3 ha caído en la casilla +$50...\n");
					printf("El jugador 3 gana $50...\n");
				}else if(strcmp(buff, "h") == 0){
					tablero->dinero[2] += 75;
					printf("El jugador 3 ha caído en la casilla +$75...\n");
					printf("El jugador 3 gana $75...\n");
				}else if(strcmp(buff, "i") == 0){
					printf("El jugador 3 ha caído en la casilla -$25...\n");
					printf("El jugador 3 pierde $25...\n");
					if(tablero->dinero[2] <25){
						tablero->dinero[2] = 0;
					}else{
						tablero->dinero[2] -= 25;
					}
					
				}else if(strcmp(buff, "j") == 0){
					printf("El jugador 3 ha caído en la casilla -$50...\n");
					printf("El jugador 3 pierde $50...\n");
					if(tablero->dinero[2] <50){
						tablero->dinero[2] = 0;	
					}else{
						tablero->dinero[2] -= 50;
					}
					
				}else if(strcmp(buff, "k") == 0){
					printf("El jugador 3 ha caído en la casilla -$75...\n");
					printf("El jugador 3 pierde $75...\n");
					if(tablero->dinero[2] < 75){
						tablero->dinero[2] = 0;
					}else{
						tablero->dinero[2] -= 75;
					}
				}else if(strcmp(buff, "l") == 0){ //START
					printf(" ");
				}
				printf("El nuevo saldo del Jugador 3 es $%d\n\n\n", tablero->dinero[2]);
				turnos[2] = 1;
				if(tablero->dinero[2] >=500){
					break;
				}
			}
			
			// Estos if se utilizan para identificar
			// cuándo se cumple la pérdida de turno
			// producto de caer en las casillas JAIL.
			if (turnoJail0 + 1 == rondas){
				turnos[0] = 0;
				turnoJail0 = 0;
			}else if (turnoJail0 != rondas){
				turnos[0] = 0;
			}
			if (turnoJail1 + 1 == rondas){
				turnos[1] = 0;
				turnoJail1 = 0;
			}else if (turnoJail1 != rondas){
				turnos[1] = 0;
			}
			if (turnoJail2 + 1 == rondas){
				turnos[2] = 0;
				turnoJail2 = 0;
			}else if (turnoJail2 != rondas){
				turnos[2] = 0;
			}

			rondas+=1;

			mostrarTablero(tablero);

			printf("----------------------\n");
			printf("RESULTADOS DE LA RONDA\n");
			printf("Tú: %d\n", tablero->dinero[0]);
			printf("Jugador 2: %d\n", tablero->dinero[1]);
			printf("Jugador 3: %d\n", tablero->dinero[2]);
			printf("----------------------\n");
			sleep(1);
			printf("\n¡¡¡¡¡¡NUEVA RONDA!!!!!!\n");
			sleep(1);
		}
	}
	int ganador;
	// Se le asigna la variable ganador al primer jugador
	// que logre $500 o más.
	if (tablero->dinero[0] >= 500){
		ganador = 1;
	}else if (tablero->dinero[1] >= 500){
		ganador = 2;
	}else if(tablero->dinero[2] >= 500){
		ganador = 3;
	}

	//If final, que indica el ganador del juego. Solo puede ingresar el padre.
	if(pid > 0){
		mostrarTablero(tablero);
		printf("\n¡El juego ha terminado!\n");
		printf("El ganador es... *redoble de tambores*\n");
		sleep(1);
		printf("\n¡¡ JUGADOR %d !!\n", ganador);
		for(int c = 0; c < 3; c++){
			kill(tablero->pids[c], SIGINT);
		}
		kill(getppid(), SIGINT);
	}
	return 0;
}
