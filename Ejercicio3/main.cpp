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

	string primera_linea;
	getline(cin, primera_linea, '\n');

	vector<int> entrada_parseada(split(primera_linea, ' '));

	int cantidad_gimnasios = entrada_parseada[0];
	int cantidad_paradas = entrada_parseada[1];
	int capacidad_mochila = entrada_parseada[2];

	// if(EXP){
	// 	printf("opcion_greedy, opcion_busqueda, cant_gim, cant_gim_mismo_costo, cant_poke, cap_mochila, tiempo_armado_grafo, tiempo_greedy, distancia_camino_greedy, tiempo_busqueda, distancia_camino, cant_mejoras, tiempo_swap, vecinos_prom\n");
	// }
	
	// medimos cuanto tardamos en armar los grafos
	auto start = ya();
	Grafo g(cantidad_gimnasios, cantidad_paradas);
	GrafoCompleto<NodoP> gc; // no lo pude unificar de forma facil al otro
	parseo_entrada_busqueda_local(g, gc, cantidad_gimnasios, cantidad_paradas);
	auto end = ya();
	double tiempo_armado_grafo = chrono::duration_cast<chrono::duration<double, std::nano>>(end-start).count();

	int cant_gim_mismo_costo = 0;
	int costo_maximo = 0;
	for(int i = 0; i < cantidad_gimnasios; ++i){
		if(costo_maximo < gc.iesimoNodo(i).pociones) costo_maximo = gc.iesimoNodo(i).pociones;
	}
	vector<unsigned int> gim_con_x_pociones(costo_maximo+1, 0);
	for(int i = 0; i < cantidad_gimnasios; ++i){
		gim_con_x_pociones[gc.iesimoNodo(i).pociones]++;
	}
	for(unsigned int i = 0; i < gim_con_x_pociones.size(); ++i){
		if(gim_con_x_pociones[i]>1) cant_gim_mismo_costo++;
	}
	
	for(int i = 0; i < repeticiones; ++i){

		if(verbose) fprintf(stderr, "[Corriendo repeticion %i]\n", i+1);

		EXP_STR = ""+to_string(opcion_greedy)+","+to_string(opcion_busqueda)+","+to_string(cantidad_gimnasios)+","+to_string(cant_gim_mismo_costo)+","
			+to_string(cantidad_paradas)+","+to_string(capacidad_mochila)+","+to_string(tiempo_armado_grafo)+",";
		EXP_STR_AUX = "";

		start = ya();
		Solucion res = g.tsp_goloso(opcion_greedy, capacidad_mochila);
		end = ya();
		double tiempo_greedy = chrono::duration_cast<chrono::duration<double, std::nano>>(end-start).count();

		// imprime el resultado para experimentar
		if(verbose){
			cerr << "Resultado goloso:" << endl;
			cerr << fixed << setprecision(2) << res.distancia_recorrida << ' ' <<  res.ids.size() - 1 << ' ';
			for(unsigned int i = 0; i < res.ids.size(); ++i){
				cerr << res.ids[i] << " ";
			}
			cerr << endl;
		}

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

		// imprime el resultado para experimentar
		if(verbose){
			cerr << "Resultado con busqueda local:" << endl;
			cerr << fixed << setprecision(2) << res.distancia_recorrida << ' ' <<  res.ids.size() - 1 << ' ';
			for(unsigned int i = 0; i < res.ids.size(); ++i){
				cerr << res.ids[i] << " ";
			}
			cerr << endl;
		}

		if(EXP){
			printf("%s\n", EXP_STR.c_str());
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
