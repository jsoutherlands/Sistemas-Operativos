#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE* archivo;
	char bufferStart[50] = "Laberinto/";
	char * i1;
	char* i2;
	char * i3;
	char frase1[50], frase2[50], frase3[50], fraseAux[50];
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

				if (archivo = fopen("frase.txt", "r"))
				{
					fscanf(archivo, "%s", fraseAux);
					printf("Frase aux %s\n",fraseAux);
					printf("Frase aux[0]%d\n",fraseAux[0] );
					//if (fraseAux[0] == "1")
					//{
					//	printf("Funciona\n");
					//}
					fclose(archivo);
				}
				strcpy(bufferStart,"Laberinto/");
			}	
		
		}
	
	}
	return 0;
}
