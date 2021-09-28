#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE* archivo;
	char bufferStart[50] = "Laberinto/";
	char * i1;
	char* i2;
	char * i3;
	char frase1[50], frase2[50], frase3[50], numerito[1], inutil[3], fraseFinal[75], auxiliar[25];
	int  i =1, j=1, k=1;
	for (int m = 1; m < 4; m++)
	{	
		asprintf(&i1, "%d", m);
		
		for (int n = 1; n < 4; n++)
		{
			asprintf(&i2, "%d", n);
		
			for (int o = 1; o < 4; o++)
			{
				
				asprintf(&i3, "%d", o);
				strcat(strcat(strcat(strcat(strcat(bufferStart, i1), "/"), i2), "/"), i3);
				strcat(bufferStart,"/frase.txt");
				printf("%s\n",bufferStart);

				if (archivo = fopen(bufferStart, "r"))
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
	free (archivo);
	return 0;
}
