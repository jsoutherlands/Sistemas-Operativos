make: laberinto.o buscador.o
	gcc -Wall -g -o laberinto laberinto.o -lm; gcc -Wall -g -o buscador buscador.o -lm

run:
	./laberinto; ./buscador

laberinto.o: laberinto.c
	gcc -c -Wall laberinto.c

buscador.o: buscador.c
	gcc -c -Wall buscador.c
clean:
	rm -f laberinto buscador *.o -r Laberinto
