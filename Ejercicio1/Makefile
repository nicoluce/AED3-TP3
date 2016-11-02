CC = g++
CFLAGS = -g -Wall -Werror -std=c++11 -O3
AUXDIR = ../Auxiliares

BINARIES = ejercicio1

all: $(BINARIES)

ejercicio1: main.cpp grafo.o grafo.h auxiliares.o $(AUXDIR)/auxiliares.h	
	$(CC) $(CFLAGS) main.cpp grafo.o auxiliares.o -o ej1.out

grafo.o: grafo.cpp
	$(CC) $(CFLAGS) -c $< -o $@

auxiliares.o: $(AUXDIR)/auxiliares.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f $(BINARIES)
