// 	AED3 - TP3
//	Header Estructura

#ifndef __GRAFO_H__
#define __GRAFO_H__

// Representacion de grafo para algoritmo de Backtracking

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include "../Auxiliares/auxiliares.h"

using namespace std;

typedef double Distancia;
typedef pair<unsigned int, unsigned int> Posicion;
enum Tipo { Gimnasio, Pokeparada };

struct Solucion {
	Solucion() : distancia_recorrida(0), ids(vector<unsigned int>())
	{}

	Distancia distancia_recorrida;
	vector<unsigned int> ids;
};

class Grafo {
public:
	Grafo(unsigned int cantidad_gimnasios = 0, unsigned int cantidad_pokeparadas = 0);

	unsigned int agregar_pokeparada(const Posicion& pos); // devuelve el id del nodo
	unsigned int agregar_gimnasio(const Posicion& pos, unsigned int pociones); // devuelve el id del nodo

	const Distancia distancia(const Posicion& p1, const Posicion& p2); // mide la distancia euclidea entre dos posiciones

	const void imprimir(); // imprime el grafo

	int buscarPociones(int mochila, Posicion desde, vector<bool>& visitados);
	unsigned int elegirPrimerNodo(unsigned int opcion);
	Solucion tsp_goloso(unsigned int opcion_primer_nodo, unsigned int capacidad_mochila, unsigned int cantidad_cercanos); // devuelve la solucion como pide el enunciado, o un solo elemento (-1) si no hay solucion

private:
	struct Nodo {
		// constructor de Nodo, toma todos los parametros que tiene y los asigna por copia. pociones y visitado tienen valores por default
		Nodo() : id(0), tipo(Gimnasio)
		{};
		
		Nodo(unsigned int id, Posicion pos, Tipo tipo) : 
			id(id), pos(pos), tipo(tipo)
		{};

		unsigned int id; // id del nodo
		Posicion pos; // posicion en el mapa
		Tipo tipo; // tipo: Gimnasio o Pokeparada
	};

	struct NodoGimnasio : public Nodo {
		NodoGimnasio() : pociones_necesarias(0)
		{};

		NodoGimnasio(unsigned int id, Posicion pos, Tipo tipo, unsigned int pociones = 0) : 
			Nodo(id, pos, tipo), pociones_necesarias(pociones)
		{}

	 	bool const operator>(const NodoGimnasio& otro) const { // necesario para hacer el heap
			return (this->pociones_necesarias > otro.pociones_necesarias);	
		}

		unsigned int pociones_necesarias; // Solo para Gimnasios, pociones necesarias para ganar el gimnasio
	};

	vector<Nodo> _pokeparadas; // vector de Pokeparadas
	vector<NodoGimnasio> _gimnasios;
};

#endif 