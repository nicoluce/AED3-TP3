#include <math.h>
#include <utility>
#include <algorithm>

#include "grafo.h"

Grafo::Grafo(unsigned int cantidad_gimnasios, unsigned int cantidad_pokeparadas) {
	// .reserve() sirve para agrandar el espacio del vector, asi evitamos problemas de resize.
	this->_pokeparadas.reserve(cantidad_pokeparadas); 
	this->_gimnasios.reserve(cantidad_gimnasios);
}

unsigned int Grafo::agregar_pokeparada(const Posicion& pos) {
	// los IDs de los nodos son su posicion en el vector
	unsigned int new_id = this->_pokeparadas.size();
	this->_pokeparadas.push_back(Grafo::Nodo(new_id, pos, Pokeparada));
	return new_id;
}

unsigned int Grafo::agregar_gimnasio(const Posicion& pos, unsigned int pociones) {
	// los IDs de los nodos son su posicion en el vector
	unsigned int new_id = this->_gimnasios.size();
	this->_gimnasios.push_back(Grafo::NodoGimnasio(new_id, pos, Gimnasio, pociones));
	return new_id;
}

void Grafo::gimnasios_make_heap() {
	make_heap(this->_gimnasios.begin(), this->_gimnasios.end()); // funcion de C++, aka MaxHeapify
}

const double Grafo::distancia(const Posicion& p1, const Posicion& p2) {
	return (double) sqrt( pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2) ); // no se si hace falta el casteo 
}


// Donde va la magia
vector<int> Grafo::tsp_goloso(unsigned int primer_nodo_id, unsigned int capacidad_mochila) {
	
	return vector<int>();
}

// para imprimir el grafo, puede ser util
const void Grafo::imprimir() {
	cout << "{ \n";
	for (unsigned int i = 0; i < this->_gimnasios.size(); i++) {
		cout << "	" << this->_gimnasios[i].id;
		cout << " G " << this->_gimnasios[i].pociones_necesarias << ' ';

		cout << "<" << this->_gimnasios[i].pos.first << ", " << this->_gimnasios[i].pos.second << ">\n";
	}

	for (unsigned int i = 0; i < this->_pokeparadas.size(); i++) {
		cout << "	" << this->_pokeparadas[i].id;
		cout << " P ";

		cout << "<" << this->_pokeparadas[i].pos.first << ", " << this->_pokeparadas[i].pos.second << ">\n";
	}
	cout << "}" << endl;
}