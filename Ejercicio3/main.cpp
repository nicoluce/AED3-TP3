// TP3 - Algoritmo y Estructuras de Datos III
// Ejercicio 3 - Algoritmo busqueda local

#include <iostream>
#include <string>
#include <stdio.h>
#include <chrono>

#include "busqueda_local.h"

using namespace std;

#define ya chrono::high_resolution_clock::now

// ./ej3.out <opcion_greedy> <opcion_busqueda> [-m [repeticiones]]
int main(int argc, char const *argv[]){
	int repeticiones = 1;
	string medir;

	int opcion_greedy = atoi(argv[1]);
	int opcion_busqueda = atoi(argv[2]);
	if(argc > 3) medir = argv[3];
	if(argc > 4) repeticiones = atoi(argv[4]);

	string primera_linea;
	getline(cin, primera_linea, '\n');

	vector<int> entrada_parseada(split(primera_linea, ' '));

	int cantidad_gimnasios = entrada_parseada[0];
	int cantidad_paradas = entrada_parseada[1];
	int capacidad_mochila = entrada_parseada[2];
	
	Grafo g(cantidad_gimnasios, cantidad_paradas);
	GrafoCompleto<NodoP> gc; // no lo pude unificar de forma facil al otro
	parseo_entrada_busqueda_local(g, gc, cantidad_gimnasios, cantidad_paradas);
	
	for(int i = 0; i < repeticiones; ++i){

		cerr << "[Corriendo repeticion " << i+1 << ']' << endl;

		auto start = ya();
		Solucion res = g.tsp_goloso(opcion_greedy, capacidad_mochila);

		// si no hay solucion entonces no sigo
		if(res.ids.empty()){
			cout << -1 << endl;
			return 0;
		}

		res = busquedaLocal(res, gc, capacidad_mochila, opcion_busqueda);
		auto end = ya();

		// imprime el resultado
		cout << fixed << setprecision(2) << res.distancia_recorrida << ' ' <<  res.ids.size() - 1 << ' ';
		imprimir_vector(res.ids);


		if(medir  == "-m"){
			cout << "Grafo: " << cantidad_gimnasios << ' ' << cantidad_paradas << ' ' << capacidad_mochila << endl;
			cout << fixed << setprecision(0);
			cout << "Tiempo: " << chrono::duration_cast<chrono::duration<double, std::nano>>(end-start).count() << endl;
		}
	}
	return 0;
}
