	
	+-------------------------------------------------------------------+
	|																	|
	|			Catalina Sierra Huerta - 201973557-8 - P201				|
	|			José Southerland Silva - 201973526-8 - P201				|
	|																	|
	+-------------------------------------------------------------------+
	|
	|	Archivos:
	|	- laberinto.c (Sección Laberinto)
	|	- buscador.c  (Sección Buscador)
	|
	+
	|
	|	Instrucciones de compilación:
	|
	|	1. Descargar archivo TAREA1_2019735578_2019735268.tar.gz
	|	y descomprimirlo.
	|	
	|	2. Abrir terminal, dirigirse a la carpeta descomprimida y
	|	ejecutar alguno de los siguientes comandos:
	|		- make: compila tanto laberinto.c como buscador.c
	|		- make run: ejecuta laberinto y luego buscador.
	|		- make clean: elimina los archivos generados por la
	|		  compilación y la ejecución.
	|
	|	NOTA: no hacer make run sin antes haber ejecutado el comando
	|		  make.
	|
	+-----------------------------------------------------------------+
	|
	|	OBSERVACIONES
	|
	|	* La función rand() utilizada para generar números aleatorios
	|	entre 1 y 3 podría caer en una sobreescritura de "frase.txt"
	|	producto de una repetición de los números aleatorios geneardos
	|	(esto es cosa de suerte).
	|
	|	* Se eliminó el espacio final de cada frase para no inducir
	|	error en la lectura del buscador.
