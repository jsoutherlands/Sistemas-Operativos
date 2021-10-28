make: tablero.o monopoly.o
	gcc -Wall -g -o monopoly monopoly.o tablero.o -lm -lrt

run:
	./monopoly

tablero.o: tablero.c
	gcc -c -Wall tablero.c

monopoly.o: monopoly.c
	gcc -c -Wall monopoly.c
clean:
	rm -f monopoly *.o
