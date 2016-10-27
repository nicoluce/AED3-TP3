// TP3 - Algoritmo y Estructuras de Datos III
// Algoritmo Exacto / Backtracking

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#include "grafo.h"
// #include "../Auxiliares/auxiliares.h"

using namespace std;


vector<int> split(const string &s, char delim) {
	vector<int> elems;
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(atoi(item.c_str()));
	}
	return elems;
}

void parseo_entrada(Grafo& g, int n, int m) {
	string buffer;
	vector<int>entrada_parseada;

	for (int i = 0; i < n; i++) {
		getline(cin, buffer, '\n');
		entrada_parseada = split(buffer, ' ');
		g.agregar_nodo(pair<int, int>(entrada_parseada[0], entrada_parseada[1]), Gimnasio, entrada_parseada[2]);
	}

	for (int i = 0; i < m; i++) {
		getline(cin, buffer, '\n');
		entrada_parseada = split(buffer, ' ');
		g.agregar_nodo(pair<int, int>(entrada_parseada[0], entrada_parseada[1]), Pokeparada);
	}
}

int main(int argc, char const *argv[]) {
	
	string primera_linea;
	getline(cin, primera_linea, '\n');

	vector<int>entrada_parseada (split(primera_linea, ' '));

	int cantidad_gimnasios = entrada_parseada[0];
	int cantidad_paradas = entrada_parseada[1];
	int capacidad_mochila = entrada_parseada[2];
	
	Grafo g(cantidad_gimnasios + cantidad_paradas);
	parseo_entrada(g, cantidad_gimnasios, cantidad_paradas);
	
	g.imprimir();

	return 0;
}
