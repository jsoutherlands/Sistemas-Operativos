#include <stdio.h>

FILE* archivo;
char bufferStart[50] = "Laberinto/";
char* i1, i2, i3;
for (int i = 1; i < 4; i++)
{
	for (int j = 1; j < 4; i++)
	{
		for (int k = 1; k < 4; i++)
		{
			asprintf(&i, "%d", i1);
			asprintf(&j, "%d", i2);
			asprintf(&k, "%d", i3);
			strcat(strcat(strcat(strcat(strcat(bufferStart, i1), "/"), i2), "/"), i3);
		}	
	}
}
