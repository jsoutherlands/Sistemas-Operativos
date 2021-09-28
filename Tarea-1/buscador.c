#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* archivo;
char bufferStart[50] = "Laberinto/";
char* i1, i2, i3;
char frase1[50], frase2[50], frase3[50], fraseAux[50];
int* i, j, k;
for (i = 1; i < 4; i++)
{
	for (j = 1; j < 4; j++)
	{
		for (k = 1; k < 4; k++)
		{
			asprintf(&i, "%d", i1);
			asprintf(&j, "%d", i2);
			asprintf(&k, "%d", i3);
			strcat(strcat(strcat(strcat(strcat(bufferStart, i1), "/"), i2), "/"), i3);
			if (archivo = fopen("frase.txt", "r"))
			{
				fscanf(archivo, "%s", fraseAux);
				if (fraseAux[0] == "1")
				{
					printf("Funciona\n");
				}
			}
		}	
	}
}
