// 	AED3 - TP3
//	Header Estructuras

#pragma once
// Representacion de grafo para algoritmo de Backtracking

#include <utility>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef double Distancia;
typedef pair<int, int> Posicion;
enum Tipo { Gimnasio, Pokeparada };

class Grafo {
public:
	Grafo(int cantidad_de_nodos);

	int agregar_nodo(const Posicion& pos, const Tipo& tipo, int pociones); // devuelve el id del nodo
	const double distancia(const Posicion& p1, const Posicion& p2);

	const void imprimir();

	vector<int> tsp_backtracking(int primer_nodo_id, int capacidad_mochila); // devuelve la solucion como pide el enunciado, o un solo elemento (-1) si no hay solucion

private:
	struct Nodo {
		Nodo(int id, Posicion pos, Tipo tipo, int pociones = 0, bool visitado = false) : 
			id(id), pos(pos), tipo(tipo), 
			pociones_necesarias(pociones), 
			visitado(visitado)
		{};

		int id;
		Posicion pos;
		Tipo tipo;
		int pociones_necesarias;
		bool visitado;
	};

	vector<Nodo> _nodos;
};

Grafo::Grafo(int cantidad_de_nodos = 0) {
	this->_nodos.reserve(cantidad_de_nodos);
}

int Grafo::agregar_nodo(const Posicion& pos, const Tipo& tipo, int pociones = 0) {
	int new_id = this->_nodos.size();
	this->_nodos.push_back(Grafo::Nodo(new_id, pos, tipo, pociones));
	return new_id;
}

const double Grafo::distancia(const Posicion& p1, const Posicion& p2) {
	return (double) sqrt( pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2) );
}

vector<int> Grafo::tsp_backtracking(int primer_nodo_id, int capacidad_mochila) {
	
	return vector<int>();
}

const void Grafo::imprimir() {
	cout << "{ \n";
	for (int i = 0; i < this->_nodos.size(); i++) {
		cout << "	" << this->_nodos[i].id;
		if (this->_nodos[i].tipo == Gimnasio) cout << " G " << this->_nodos[i].pociones_necesarias << ' ';
		else cout << " P ";

		cout << "<" << this->_nodos[i].pos.first << ", " << this->_nodos[i].pos.second << ">\n";
	}
	cout << "}" << endl;
}