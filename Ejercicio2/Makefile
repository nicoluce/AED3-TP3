CC = g++
CFLAGS = -g -Wall -Werror -std=c++11
AUXDIR = ../Auxiliares

BINARIES = ej2.out

all: $(BINARIES)

$(BINARIES): main.cpp grafo.o grafo.h auxiliares.o $(AUXDIR)/auxiliares.h	
	$(CC) $(CFLAGS) main.cpp grafo.o auxiliares.o -o ej2.out

grafo.o: grafo.cpp
	$(CC) $(CFLAGS) -c $< -o $@

auxiliares.o: $(AUXDIR)/auxiliares.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f $(BINARIES)
