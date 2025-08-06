all: fila

fila: main.o fila.o
	gcc -o fila main.o fila.o

main.o: main.c fila.h
	gcc -c main.c

fila.o: fila.c fila.h
	gcc -c fila.c

clean:
	rm -f *.o fila