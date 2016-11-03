// TP3 - Algoritmo y Estructuras de Datos III
// Ejercicio 4 - GRASP

#include <iostream>
#include <string>
#include <stdio.h>
#include <chrono>
#include <iomanip> // setprecision

#include "grafo.h"
#include "../Auxiliares/auxiliares.h"
#include "../Ejercicio3/camino.hpp"

using namespace std;

void parseo_entrada(Grafo& g, GrafoCompleto<NodoP>& gc, int n, int m){
	string buffer;
	vector<int>entrada_parseada;

	for(int i = 0; i < n; i++){
		getline(cin, buffer, '\n');
		entrada_parseada = split(buffer, ' ');
		g.agregar_gimnasio(pair<int, int>(entrada_parseada[0], entrada_parseada[1]), entrada_parseada[2]);
		NodoP aux(pair<int, int>(entrada_parseada[0], entrada_parseada[1]), Gimnasio, entrada_parseada[2]);
		gc.agregarNodo(aux);
	}

	for(int i = 0; i < m; i++){
		getline(cin, buffer, '\n');
		entrada_parseada = split(buffer, ' ');
		g.agregar_pokeparada(pair<int, int>(entrada_parseada[0], entrada_parseada[1]));
		NodoP aux(pair<int, int>(entrada_parseada[0], entrada_parseada[1]), Pokeparada, 0);
		gc.agregarNodo(aux);
	}
}

Solucion busquedaLocal(Solucion res, GrafoCompleto<NodoP>& gc, int capacidad_mochila, int opcion_busqueda){
	// armo el camino a partir de res:
	vector<NodoP> secuNodos;
	vector<int> secuIndex;
	for(unsigned int i = 0; i < res.ids.size(); ++i){
		secuNodos.push_back(gc.iesimoNodo(res.ids[i]-1)); // el -1 porque los ids empiezan desde 1
		secuIndex.push_back(res.ids[i]);
	}

	Camino<NodoP> camino(secuNodos, secuIndex);

	// itero hasta que no mejoro mas
	bool mejoraLaSolucion;
	do {
		mejoraLaSolucion = false;
		// calculo los vecinos
		vector< Camino<NodoP> > vecinos;
		switch(opcion_busqueda){
			case 0:
				vecinos_swap(camino, capacidad_mochila, vecinos);
				break;
			case 1:
				vecinos_otros(camino, vecinos);
				break;
		}

		// busco el minimo de todos los vecinos tal que, a su vez, sea menor a lo que ya tenia
		Distancia distMin = camino.distanciaTotal();
		int indexMin = -1;
		for(int i = 0; i < (int)vecinos.size(); ++i){
			if(vecinos[i].distanciaTotal() < distMin){
				indexMin = i;
				mejoraLaSolucion = true;
			}
		}
		
		// actualizo el camino con el minimo de los vecinos
		if(mejoraLaSolucion){
			camino = vecinos[indexMin];
		}

	} while(mejoraLaSolucion);

	Solucion s;
	s.distancia_recorrida = camino.distanciaTotal();
	for(int i = 0; i < camino.largo(); ++i){
		s.ids.push_back((unsigned int)camino.iesimoId(i));
	}
	return s;
}

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
	parseo_entrada(g, gc, cantidad_gimnasios, cantidad_paradas);
	
	for(int i = 0; i < repeticiones; ++i){

		cerr << "[Corriendo repeticion " << i+1 << ']' << endl;

		auto start = ya();
		Solucion s = g.tsp_goloso(opcion_greedy_primer_nodo, capacidad_mochila, opcion_greedy_cercanos);

		// si no hay solucion entonces no sigo
		if(s.ids.empty()){
			cout << -1 << endl;
			return 0;
		}

		for(int i = 0; i < cantidad_iteraciones; ++i){
			Solucion s_prima = g.tsp_goloso(opcion_greedy_primer_nodo, capacidad_mochila, opcion_greedy_cercanos);
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
