#ifndef _GNU_SOURCE	
#define _GNU_SOURCE 1 	//Se utiliza para el asprintf.
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	//se abre inicializan todas las variables a utilizar en buscador.c
	FILE* archivo;
	char bufferStart[50] = "Laberinto/";
	char* i1;
	char* i2;
	char* i3;
	char frase1[50], frase2[50], frase3[50], numerito[1], inutil[3], fraseFinal[75], auxiliar[25];
	//Esta anidacion de FOR se utiliza para iterar sobre las carpetas.
	for (int i = 1; i < 4; i++)
	{	//Se transforma el numero i del FOR en string.
		asprintf(&i1, "%d", i);
		
		for (int j = 1; j < 4; j++)
		{	//Se transforma el numero j del FOR en string.
			asprintf(&i2, "%d", j);
		
			for (int k = 1; k < 4; k++)
			{
				//Se transforma el numero k del FOR en string.
				asprintf(&i3, "%d", k);
				//Se concatena toda la direccion del directorio a buscar.
				strcat(strcat(strcat(strcat(strcat(bufferStart, i1), "/"), i2), "/"), i3);
				strcat(bufferStart,"/frase.txt");
				
				//Se busca si el archivo 'frase.txt' existe dentro de la carpeta.
				if ((archivo = fopen(bufferStart, "r")) != NULL)
				{	
					//Se separa el numero inicial del resto de la frase del archivo 'frase.txt'.
					fscanf(archivo, "%c", numerito);
					//Se separa la ',' del resto de la frase del archivo 'frase.txt'.
					fscanf(archivo, "%s", inutil);
					
					//Se concatenan los string restantes de la frase del archivo 'frase.txt'.
					while(!feof(archivo)){
						fscanf(archivo, "%s", auxiliar);
						strcat(fraseFinal, auxiliar);
						strcat(fraseFinal, " ");

					}
					//Comparacion entre el numero de cada frase con su posicion en el orden de la frase original
					// y si coincide se aNade a un variable la cual sera mostrada en pantalla por orden ascendente (1,2,3).
					if (strcmp(numerito,"1,")==0)
					{
						strcpy(frase1, fraseFinal);
						
					}else if (strcmp(numerito,"2,")==0)
					{
						strcpy(frase2, fraseFinal);
					}else if (strcmp(numerito,"3,")==0)
					{
						strcpy(frase3, fraseFinal);
					}
					fclose(archivo);
					strcpy(fraseFinal, "");
				}
				strcpy(bufferStart,"Laberinto/");
			}	
		
		}
	
	}
	
	strcat(strcat(strcat(fraseFinal, frase1), frase2), frase3);
	printf("%s\n", fraseFinal);
	return 0;
}
