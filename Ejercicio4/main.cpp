// TP3 - Algoritmo y Estructuras de Datos III
// Ejercicio 4 - GRASP

#include <iostream>
#include <string>
#include <stdio.h>
#include <chrono>
#include <iomanip> // setprecision

#include "../Ejercicio3/busqueda_local.h"

using namespace std;

#define ya chrono::high_resolution_clock::now

// ./ej4.out <opcion_greedy_primer_nodo> <opcion_greedy_cercanos> <opcion_busqueda> <cantidad_iteraciones> [-m [repeticiones]]
int main(int argc, char const *argv[]){
	int repeticiones = 1;
	string medir;

	int opcion_greedy_primer_nodo = atoi(argv[1]);
	int opcion_greedy_cercanos = atoi(argv[2]);
	int opcion_busqueda = atoi(argv[3]);
	int cantidad_iteraciones = atoi(argv[4]);
	if(argc > 5) medir = argv[5];
	if(argc > 6) repeticiones = atoi(argv[6]);

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
		Solucion s = g.tsp_goloso_rnd(opcion_greedy_primer_nodo, capacidad_mochila, opcion_greedy_cercanos);

		// si no hay solucion entonces no sigo
		if(s.ids.empty()){
			cout << -1 << endl;
			return 0;
		}

		for(int i = 0; i < cantidad_iteraciones; ++i){
			Solucion s_prima = g.tsp_goloso_rnd(opcion_greedy_primer_nodo, capacidad_mochila, opcion_greedy_cercanos);
			s_prima = busquedaLocal(s_prima, gc, capacidad_mochila, opcion_busqueda);
			if(s_prima.distancia_recorrida < s.distancia_recorrida){
				s = s_prima;
			}
		}

		auto end = ya();

		// imprime el resultado
		cout << fixed << setprecision(2) << s.distancia_recorrida << ' ' <<  s.ids.size() - 1 << ' ';
		imprimir_vector(s.ids);

		if(medir  == "-m"){
			cout << "Grafo: " << cantidad_gimnasios << ' ' << cantidad_paradas << ' ' << capacidad_mochila << endl;
			cout << fixed << setprecision(0);
			cout << "Tiempo: " << chrono::duration_cast<chrono::duration<double, std::nano>>(end-start).count() << endl;
		}
	}

	return 0;
}
