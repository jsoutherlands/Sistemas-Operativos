make: tablero.o tarea2.o
	gcc -Wall -g -o tarea2 tarea2.o tablero.o -lm -lrt

run:
	./tarea2

tablero.o: tablero.c
	gcc -c -Wall tablero.c

tarea2.o: tarea2.c
	gcc -c -Wall tarea2.c
clean:
	rm -f tarea2 *.o