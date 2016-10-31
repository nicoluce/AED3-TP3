// 	AED3 - TP3
//	Header Estructura

#ifndef __GRAFO_H__
#define __GRAFO_H__

// Representacion de grafo para algoritmo de Backtracking

#include <iostream>
#include <vector>
#include <iomanip>
#include "../Auxiliares/auxiliares.h"

using namespace std;

#define INF 99

// Un par de typedefs para la gilada

typedef double Distancia;
typedef pair<unsigned int, unsigned int> Posicion;
enum Tipo { Gimnasio, Pokeparada };

struct Solucion {
	Solucion() : distancia_recorrida(0), ids(vector<unsigned int>()), no_es_solucion(false)
	{}

	Distancia distancia_recorrida;
	vector<unsigned int> ids;
	bool no_es_solucion;
};

class Grafo {
public:
	Grafo(unsigned int cantidad_de_nodos = 0); // parametro opcional para hacer el .reserve() al vector<Nodos> _nodos

	unsigned int agregar_nodo(const Posicion& pos, const Tipo& tipo, unsigned int pociones = 0); // devuelve el id del nodo
	const double distancia(const Posicion& p1, const Posicion& p2); // funcion para calcular la distancia entre dos posiciones

	const void imprimir(); // imprimir el grafo, puede ser util

	Solucion tsp_backtracking(unsigned int capacidad_mochila); // devuelve la solucion como pide el enunciado, o un solo elemento (-1) si no hay solucion

// private:

	struct Nodo {
		Nodo(unsigned int id, Posicion pos, Tipo tipo, unsigned int pociones = 0, bool visitado = false) : 
			id(id), pos(pos), tipo(tipo), 
			pociones_necesarias(pociones), 
			visitado(visitado)
		{};

		unsigned int id;
		Posicion pos;
		Tipo tipo;
		unsigned int pociones_necesarias;
		bool visitado;
	};

	Solucion recursivo(unsigned int id_actual, unsigned int capacidad_mochila, unsigned int pociones_actuales, vector<bool>& visitados, vector<unsigned int>& camino_actual);
	bool haySolucion(vector<Nodo>& nodos, vector<bool>& visitados, unsigned int pociones_actuales, unsigned int capacidad_mochila);
	bool esSolucion(vector<Nodo>& nodos, vector<bool>& visitados);

	vector<Nodo> _nodos;
};

#endif 