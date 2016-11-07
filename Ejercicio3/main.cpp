// TP3 - Algoritmo y Estructuras de Datos III
// Ejercicio 3 - Algoritmo busqueda local

#include <iostream>
#include <string>
#include <stdio.h>
#include <chrono>

#include "busqueda_local.h"

string EXP_STR = "";
bool EXP = false;
#define ya chrono::high_resolution_clock::now

using namespace std;

void read_options(int argc, char const *argv[], int& g, int& b, int& r, bool& e, bool& v);

// ./ej3.out [-g opcion_greedy] [-b opcion_busqueda] [-r repeticiones] [-e](para experimentar) [-v](dice por cual repeticion va)
int main(int argc, char const *argv[]){
	int opcion_greedy = 0;
	int opcion_busqueda = 0;
	int repeticiones = 1;
	bool verbose = false;

	read_options(argc, argv, opcion_greedy, opcion_busqueda, repeticiones, EXP, verbose);

	cerr << " " << opcion_greedy << " " << opcion_busqueda << " " << repeticiones << " " << EXP << " " << endl;

	string primera_linea;
	getline(cin, primera_linea, '\n');

	vector<int> entrada_parseada(split(primera_linea, ' '));

	int cantidad_gimnasios = entrada_parseada[0];
	int cantidad_paradas = entrada_parseada[1];
	int capacidad_mochila = entrada_parseada[2];

	if(EXP){
		printf("opcion_greedy, opcion_busqueda, cant_gim, cant_poke, cap_mochila, tiempo_armado_grafo, tiempo_greedy, distancia_camino_greedy, tiempo_busqueda, distancia_camino, cant_mejoras, vecinos_totales, tiempo_swap\n");
	}
	
	// medimos cuanto tardamos en armar los grafos
	auto start = ya();
	Grafo g(cantidad_gimnasios, cantidad_paradas);
	GrafoCompleto<NodoP> gc; // no lo pude unificar de forma facil al otro
	parseo_entrada_busqueda_local(g, gc, cantidad_gimnasios, cantidad_paradas);
	auto end = ya();
	double tiempo_armado_grafo = chrono::duration_cast<chrono::duration<double, std::nano>>(end-start).count();
	
	for(int i = 0; i < repeticiones; ++i){

		if(verbose) fprintf(stderr, "[Corriendo repeticion %i]\n", i+1);

		EXP_STR = ""+to_string(opcion_greedy)+","+to_string(opcion_busqueda)+","+to_string(cantidad_gimnasios)+","
			+to_string(cantidad_paradas)+","+to_string(capacidad_mochila)+","+to_string(tiempo_armado_grafo)+",";
		EXP_STR_AUX = "";

		start = ya();
		Solucion res = g.tsp_goloso(opcion_greedy, capacidad_mochila);
		end = ya();
		double tiempo_greedy = chrono::duration_cast<chrono::duration<double, std::nano>>(end-start).count();

		EXP_STR += to_string(tiempo_greedy)+","+to_string(res.distancia_recorrida)+",";

		// si no hay solucion entonces no sigo
		if(res.ids.empty()){
			cout << -1 << endl;
			return 0;
		}

		start = ya();
		res = busquedaLocal(res, gc, capacidad_mochila, opcion_busqueda);
		end = ya();
		double tiempo_busqueda = chrono::duration_cast<chrono::duration<double, std::nano>>(end-start).count();

		EXP_STR += to_string(tiempo_busqueda)+","+to_string(res.distancia_recorrida)+","+EXP_STR_AUX;

		if(EXP){
			EXP_STR += "\n";
			printf(EXP_STR.c_str());
		} else {
			// imprime el resultado
			cout << fixed << setprecision(2) << res.distancia_recorrida << ' ' <<  res.ids.size() - 1 << ' ';
			imprimir_vector(res.ids);
		}
	}
	return 0;
}

void read_options(int argc, char const *argv[], int& g, int& b, int& r, bool& e, bool& v){
	for(int i = 1; i < argc; ++i){
		string param = argv[i];
		if(param == "-g" && i+1 < argc) g = atoi(argv[i+1]);
		if(param == "-b" && i+1 < argc) b = atoi(argv[i+1]);
		if(param == "-r" && i+1 < argc) r = atoi(argv[i+1]);
		if(param == "-e") EXP = true;
		if(param == "-v") v = true;
	}
}
