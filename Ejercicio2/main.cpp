// TP3 - Algoritmo y Estructuras de Datos III
// Algoritmo Exacto / Backtracking

#include <iostream>
#include <string>
#include <stdio.h>
#include <chrono>

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

#define ya chrono::high_resolution_clock::now

int main(int argc, char const *argv[]) {
	int repeticiones = 1;
	string medir = "";

	// int opcion = atoi(argv[1]);
	int opcion = 1;
	if (argc > 1) medir = argv[1];
	if (argc > 2) repeticiones = atoi(argv[2]);

	string primera_linea;
	getline(cin, primera_linea, '\n');

	vector<int>entrada_parseada (split(primera_linea, ' '));

	int cantidad_gimnasios = entrada_parseada[0];
	int cantidad_paradas = entrada_parseada[1];
	int capacidad_mochila = entrada_parseada[2];

	// cout << capacidad_mochila << endl;
	
	Grafo g(cantidad_gimnasios, cantidad_paradas);
	parseo_entrada(g, cantidad_gimnasios, cantidad_paradas);
	
	for (int i = 0; i < repeticiones; ++i) {
		cerr << "[Corriendo repeticion " << i+1 << ']' << endl;
		auto start = ya();
		Solucion res = g.tsp_goloso(opcion, capacidad_mochila);
		auto end = ya();

		if (medir  == "-m") {
			// cout << '[';
			// for (unsigned int i = 0; i < res.ids.size(); i++) {
			// 	cout << '(' << get<0>(g._nodos[res.ids[i]-1].pos) << ", " << get<1>(g._nodos[res.ids[i]-1].pos) << "), ";
			// }
			// cout << ']' << endl;

			cout << fixed << setprecision(0);
			cout << res.ids.size() << ',' << res.distancia_recorrida << ',';
			cout << cantidad_gimnasios << ',' << capacidad_mochila << ',' << cantidad_paradas + cantidad_gimnasios << ',';
			cout << cantidad_paradas << ',';
			cout << chrono::duration_cast<chrono::duration<double, std::nano>>(end-start).count() << endl;

		} else {
			if (res.distancia_recorrida == -1) cout << -1 << endl;
			else {
				cout << fixed << setprecision(2);
				cout << res.distancia_recorrida << ' ' <<  res.ids.size() - 1 << ' ';
				imprimir_vector(res.ids);
			}
		}
	}
	return 0;
}
