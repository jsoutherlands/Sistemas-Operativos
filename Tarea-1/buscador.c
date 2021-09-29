#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE* archivo;
	char bufferStart[50] = "Laberinto/";
	char* i1;
	char* i2;
	char* i3;
	char frase1[50], frase2[50], frase3[50], numerito[1], inutil[3], fraseFinal[75], auxiliar[25];
	for (int i = 1; i < 4; i++)
	{	
		asprintf(&i1, "%d", i);
		
		for (int j = 1; j < 4; j++)
		{
			asprintf(&i2, "%d", j);
		
			for (int k = 1; k < 4; k++)
			{
				
				asprintf(&i3, "%d", k);
				strcat(strcat(strcat(strcat(strcat(bufferStart, i1), "/"), i2), "/"), i3);
				strcat(bufferStart,"/frase.txt");
				printf("%s\n",bufferStart);

				if ((archivo = fopen(bufferStart, "r")) != NULL)
				{
					fscanf(archivo, "%c", numerito);
					fscanf(archivo, "%s", inutil);
					
					while(!feof(archivo)){
						fscanf(archivo, "%s", auxiliar);
						strcat(fraseFinal, auxiliar);
						strcat(fraseFinal, " ");

					}
					printf("aqui %s\n", numerito);
					if (strcmp(numerito,"1,")==0)
					{
						strcpy(frase1, fraseFinal);
						printf("Hola\n");
					}else if (strcmp(numerito,"2,")==0)
					{
						strcpy(frase2, fraseFinal);
					}else if (strcmp(numerito,"3,")==0)
					{
						strcpy(frase3, fraseFinal);
					}
					printf("%s\n", fraseFinal);
					fclose(archivo);
					strcpy(fraseFinal, "");
				}
				strcpy(bufferStart,"Laberinto/");
			}	
		
		}
	
	}
	printf("%s\n", frase1);
	strcat(strcat(strcat(fraseFinal, frase1), frase2), frase3);
	printf("%s\n", fraseFinal);
	return 0;
}
