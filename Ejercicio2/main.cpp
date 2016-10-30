// TP3 - Algoritmo y Estructuras de Datos III
// Algoritmo Exacto / Backtracking

#include <iostream>
#include <string>
#include <stdio.h>

#include "grafo.h"
#include "../Auxiliares/auxiliares.h"

using namespace std;

void parseo_entrada(Grafo& g, int n, int m) {
	string buffer;
	vector<int>entrada_parseada;

	for (int i = 0; i < n; i++) {
		getline(cin, buffer, '\n');
		entrada_parseada = split(buffer, ' ');
		g.agregar_gimnasio(pair<int, int>(entrada_parseada[0], entrada_parseada[1]), entrada_parseada[2]);
	}

	for (int i = 0; i < m; i++) {
		getline(cin, buffer, '\n');
		entrada_parseada = split(buffer, ' ');
		g.agregar_pokeparada(pair<int, int>(entrada_parseada[0], entrada_parseada[1]));
	}
}

int main(int argc, char const *argv[]) {
	
	string primera_linea;
	getline(cin, primera_linea, '\n');

	vector<int>entrada_parseada (split(primera_linea, ' '));

	int cantidad_gimnasios = entrada_parseada[0];
	int cantidad_paradas = entrada_parseada[1];
	int capacidad_mochila = entrada_parseada[2];

	// cout << capacidad_mochila << endl;
	
	Grafo g(cantidad_gimnasios, cantidad_paradas);
	parseo_entrada(g, cantidad_gimnasios, cantidad_paradas);

	cout<< "hola"<< endl;
	//for (int i = 0; i < cantidad_paradas; i++) {
			
		Solucion res = g.tsp_goloso(2, capacidad_mochila);

		if (res.ids.empty()) cout << -1 << endl;
		else {
			cout << res.distancia_recorrida << ' ' <<  res.ids.size() - 1 << ' ';
			imprimir_vector(res.ids);
		}
	//}


	//g.imprimir();

	return 0;
}
