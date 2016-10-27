#include <math.h>
#include <utility>

#include "grafo.h"

Grafo::Grafo(unsigned int cantidad_de_nodos) {
	this->_nodos.reserve(cantidad_de_nodos);
}

unsigned int Grafo::agregar_nodo(const Posicion& pos, const Tipo& tipo, unsigned int pociones) {
	unsigned int new_id = this->_nodos.size();
	this->_nodos.push_back(Grafo::Nodo(new_id, pos, tipo, pociones));
	return new_id;
}

const double Grafo::distancia(const Posicion& p1, const Posicion& p2) {
	return (double) sqrt( pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2) );
}

vector<int> Grafo::tsp_backtracking(unsigned int primer_nodo_id, unsigned int capacidad_mochila) {
	
	return vector<int>();
}

const void Grafo::imprimir() {
	cout << "{ \n";
	for (unsigned int i = 0; i < this->_nodos.size(); i++) {
		cout << "	" << this->_nodos[i].id;
		if (this->_nodos[i].tipo == Gimnasio) cout << " G " << this->_nodos[i].pociones_necesarias << ' ';
		else cout << " P ";

		cout << "<" << this->_nodos[i].pos.first << ", " << this->_nodos[i].pos.second << ">\n";
	}
	cout << "}" << endl;
}