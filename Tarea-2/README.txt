
	+-------------------------------------------------------------------+
	|																	|
	|			Catalina Sierra Huerta - 201973557-8 - P201				|
	|			José Southerland Silva - 201973526-8 - P201				|
	|																	|
	+-------------------------------------------------------------------+
	|																	|
	|	Archivos:														|
	|	- monopoly.c  monopoly.o, 	monopoly							|
	|	- tablero.c  tablero.o,		funciones del tablero				|
	|	- tablero.h	 				archivo header de tablero.c			|
	+-------------------------------------------------------------------+
	|																	|
	|	Instrucciones de compilación:									|
	|																	|
	|	1. Descargar archivo TAREA2_2019735578_2019735268.tar.gz		|
	|	y descomprimirlo.												|
	|																	|
	|	2. Abrir terminal, dirigirse a la carpeta descomprimida y		|
	|	ejecutar alguno de los siguientes comandos:						|
	|		- make: compila tanto monopoly.c como tablero.c				|
	|		- make run: ejecuta monopoly					 			|
	|		- make clean: elimina los archivos generados por la 		|
	|		  compilación y la ejecución.								|
	|																	|
	|	NOTA: no hacer make run sin antes haber ejecutado el comando 	|
	|		  make.														|
	|																	|
	+-------------------------------------------------------------------+
	|																	|
	|	OBSERVACIONES:													|
	|																	|
	|	1. EL orden de jugadores es fijo, es decir, jugará siempre		|
	|	   el jugador 1, luego el jugador 2 y por último el jugador 3,	|
	|	   siendo siempre el jugador 1 el usuario(es decir tù, que		|
	|	   estás leyendo esto) y los otros dos la CPU.					|
	|																	|
	|																	|
	|	2. Formato de paso de información en pipes entre hijos y padre:	|
	|																	|
	|		*	a = BACK 2 												|
	|		*	b = JAIL												|
	|		* 	c = BACK 3 												|
	|		*	# =	FREE 												|
	|		* 	d = FORWARD 5 											|
	|		* 	e = BACK 4												|
	|		*	f = FORWARD 3 											|
	|		*	g = +50 												|
	|		*	h = +75													|
	|		*	i =	-25													|
	|		*	j = -50													|
	|		*	k = -75													|
	|		* 	l = START +100											|
	|																	|
	+-------------------------------------------------------------------+