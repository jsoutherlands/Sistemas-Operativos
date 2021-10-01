#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1 //Se utiliza para el asprintf.
#endif
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//Se inicializan las variables a utilizar en la creacion de los directorios en 'laberinto.c'.
	mkdir("Laberinto", 0777);
	const char* origen = "Laberinto/";
	char* num;
	char buffer0[100];
	char buffer1[100];
	char buffer2[100];
	char frase1[50] = "1, Los hurones del";
	char frase2[50] = "2, profesor de sistemas operativos son";
	char frase3[50] = "3, tiernos como tu carita bb 7u7"; //Frase creada por nosotros.
	int y=1;
	
	//Se crea el laberinto con llamada al sistema mkdir con permisos '0777' que permite leer, escribir y ejecutar.
	for (int i = 1; i < 4; i++)
	{
		asprintf(&num, "%d", i);
			
		strcat(strcpy(buffer0, origen), num);
	
		mkdir(buffer0, 0777);
		
		strcat(buffer0, "/");
		
		for (int i = 1; i < 4; i++){
			asprintf(&num, "%d", i);
			
			strcat(strcpy(buffer1, buffer0), num);
	
			mkdir(buffer1, 0777);
			
			strcat(buffer1, "/");
			
			for (int i = 1; i < 4; i++){
				asprintf(&num, "%d", i);
				
				strcat(strcpy(buffer2, buffer1), num);

				mkdir(buffer2, 0777);			
				
			}

		}
		
	}
	//Se inicializan variables para la insercion de los archivos 'frase.txt'.
	srand(time(NULL));
	char* dir1;
	char* dir2;
	char* dir3;
	for (int i = 0; i < 3; i++){
		
		//Se genera 3 numero aleatorios los cuales al concatenarse indicaran la ubicacion de la escritura de 'frase.txt'.
		int x1 = rand()%3;
		x1++;
		int x2 = rand()%3;
		x2++;
		int x3 = rand()%3;
		x3++;
		
		char bufferInput[50] = "Laberinto/";
		
		asprintf(&dir1, "%d", x1);
		asprintf(&dir2, "%d", x2);
		asprintf(&dir3, "%d", x3);
		
		//Se concatenan en forma de directorio la direccion del archivo 'frase.txt' a insertar.
		strcat(strcat(strcat(strcat(strcat(bufferInput, dir1), "/"), dir2), "/"), dir3);
		strcat(bufferInput, "/frase.txt");
		//Se indica donde se ha asignado por pantalla.
		printf("Asignado a %s\n", bufferInput);
		//Escritura.
		FILE* fp = fopen(bufferInput, "w");
		if (y == 1){
			fputs(frase1, fp);
			y++;
		}else if (y == 2){
			fputs(frase2, fp);
			y++;
		}else if (y == 3){
			fputs(frase3, fp);
			y++;
		}
		fclose(fp);
	}
	free(num);
	return 0;
}

