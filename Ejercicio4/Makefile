CC = g++
CFLAGS = -g -Wall -Werror -std=c++11
AUXDIR = ../Auxiliares
EJ3DIR = ../Ejercicio3

BINARIES = ej4.out

all: $(BINARIES)

$(BINARIES): main.cpp grafo.o grafo.h auxiliares.o $(AUXDIR)/auxiliares.h $(EJ3DIR)/camino.hpp
	$(CC) $(CFLAGS) main.cpp grafo.o auxiliares.o -o $(BINARIES)

grafo.o: grafo.cpp
	$(CC) $(CFLAGS) -c $< -o $@

auxiliares.o: $(AUXDIR)/auxiliares.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f $(BINARIES)
