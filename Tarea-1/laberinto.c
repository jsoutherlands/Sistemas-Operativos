#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifndef MAX
#define MAX 100
#endif

int main(){
	mkdir("Laberinto", 0777);
	const char* origen = "Laberinto/";
	char* num;
	srand(time(NULL));
	char buffer0[MAX];
	char buffer1[MAX];
	char buffer2[MAX];
	char frase1[50] = "1, Los hurones del ";
	char frase2[50] = "2, profesor de sistemas operativos son ";
	char frase3[50] = "3, tiernos como tu carita bb 7u7";
	int count=0, y=1;
	for (int i = 1; i < 4; i++)
	{
		if (asprintf(&num, "%d", i) == -1){
			perror("asprintf");
		}
		else{
			strcat(strcpy(buffer0, origen), num);
		}
		mkdir(buffer0, 0777);
		strcat(buffer0, "/");
		for (int i = 1; i < 4; i++){
			if (asprintf(&num, "%d", i) == -1){
			perror("asprintf");
			}
			else{
				strcat(strcpy(buffer1, buffer0), num);
			}
			mkdir(buffer1, 0777);
			strcat(buffer1, "/");
			
			for (int i = 1; i < 4; i++){
				if (asprintf(&num, "%d", i) == -1){
					perror("asprintf");
				}
				else{
					strcat(strcpy(buffer2, buffer1), num);
					count++;

				}
				mkdir(buffer2, 0777);			
				
			}

		}
		
	}
	char* dir1;
	char* dir2;
	char* dir3;
	for (int i = 0; i < 3; i++){
		int x1 = rand()%9;
		int x2 = rand()%9;
		int x3 = rand()%9;
		char bufferInput[50] = "Laberinto/";
		asprintf(&dir1, "%d", x1);
		asprintf(&dir2, "%d", x2);
		asprintf(&dir3, "%d", x3);
		strcat(strcat(strcat(strcat(strcat(bufferInput, dir1), "/"), dir2), "/"), dir3);
		strcat(bufferInput, "/frase.txt");
		printf("Asignado a %s\n", bufferInput);
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

// 0777 significa permisos de lectura y escritura y ejecución!!
// VER LA WEA DE RANDOM DE ACUERDO A 3 NUMEROS A PARTIR DEL INICIO DEL LABERINTO (CREAR DIRECTORIO RANDOM).
