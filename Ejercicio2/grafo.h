// 	AED3 - TP3
//	Header Estructura

#ifndef __GRAFO_H__
#define __GRAFO_H__

// Representacion de grafo para algoritmo de Backtracking

#include <iostream>
#include <vector>

using namespace std;

typedef double Distancia;
typedef pair<unsigned int, unsigned int> Posicion;
enum Tipo { Gimnasio, Pokeparada };

class Grafo {
public:
	Grafo(unsigned int cantidad_gimnasios = 0, unsigned int cantidad_pokeparadas = 0);

	unsigned int agregar_pokeparada(const Posicion& pos); // devuelve el id del nodo
	unsigned int agregar_gimnasio(const Posicion& pos, unsigned int pociones); // devuelve el id del nodo

	const double distancia(const Posicion& p1, const Posicion& p2); // mide la distancia euclidea entre dos posiciones

	const void imprimir(); // imprime el grafo

	vector<int> tsp_goloso(unsigned int primer_nodo_id, unsigned int capacidad_mochila); // devuelve la solucion como pide el enunciado, o un solo elemento (-1) si no hay solucion

private:
	struct Nodo {
		// constructor de Nodo, toma todos los parametros que tiene y los asigna por copia. pociones y visitado tienen valores por default
		Nodo(unsigned int id, Posicion pos, Tipo tipo, bool visitado = false) : 
			id(id), pos(pos), tipo(tipo), 
			pociones_necesarias(pociones), 
			visitado(visitado)
		{};

		unsigned int id; // id del nodo
		Posicion pos; // posicion en el mapa
		Tipo tipo; // tipo: Gimnasio o Pokeparada
		bool visitado;
	};

	struct NodoGimnasio : public Nodo {
		NodoGimnasio(unsigned int id, Posicion pos, Tipo tipo, unsigned int pociones = 0, bool visitado = false) : 
			Nodo(id, pos, tipo, visitado), pociones_necesarias(pociones)
		{}

		bool operator<(const NodoGimnasio& otro) { // necesario para hacer el heap
			return (this->pociones_necesarias < otro.pociones_necesarias);	
		}

		unsigned int pociones_necesarias; // Solo para Gimnasios, pociones necesarias para ganar el gimnasio
	};

	void gimnasios_make_heap(); // la idea es que tsp_goloso() llame a esta funcion al principio (o podría directamente hacer él el make_heap())

	vector<Nodo> _pokeparadas; // vector de Pokeparadas
	vector<NodoGimnasio> _gimnasios; // se usaría como heap

};

#endif 