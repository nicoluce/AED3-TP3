CC = g++
CFLAGS = -g -Wall -Werror -std=c++11
AUXDIR = ../Auxiliares
EJ2DIR = ../Ejercicio2

BINARIES = ej3.out

all: $(BINARIES)

$(BINARIES): main.cpp grafo.o $(EJ2DIR)/grafo.h auxiliares.o $(AUXDIR)/auxiliares.h camino.hpp
	$(CC) $(CFLAGS) main.cpp grafo.o auxiliares.o -o $(BINARIES)

grafo.o: $(EJ2DIR)/grafo.cpp
	$(CC) $(CFLAGS) -c $< -o $@

auxiliares.o: $(AUXDIR)/auxiliares.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f $(BINARIES)
