CC = g++
CFLAGS = -g -Wall -Werror -std=c++11
AUXDIR = ../Auxiliares
EJ3DIR = ../Ejercicio3
EJ2DIR = ../Ejercicio2

BINARIES = ej4.out

all: $(BINARIES)

$(BINARIES): main.cpp grafo.o busqueda_local.o auxiliares.o
	$(CC) $(CFLAGS) main.cpp grafo.o busqueda_local.o auxiliares.o -o $(BINARIES)

grafo.o: $(EJ2DIR)/grafo.cpp $(EJ2DIR)/grafo.h
	$(CC) $(CFLAGS) -c $< -o $@

auxiliares.o: $(AUXDIR)/auxiliares.cpp $(AUXDIR)/auxiliares.h
	$(CC) $(CFLAGS) -c $< -o $@

busqueda_local.o: $(EJ3DIR)/busqueda_local.cpp $(EJ3DIR)/busqueda_local.h $(EJ3DIR)/camino.hpp 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f $(BINARIES)