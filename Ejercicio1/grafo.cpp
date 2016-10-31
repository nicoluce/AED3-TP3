#include <math.h>
#include <utility>

#include "grafo.h"

Grafo::Grafo(unsigned int cantidad_de_nodos) {
	this->_nodos.reserve(cantidad_de_nodos);
}

unsigned int Grafo::agregar_nodo(const Posicion& pos, const Tipo& tipo, unsigned int pociones) {
	unsigned int new_id = this->_nodos.size() + 1;
	this->_nodos.push_back(Grafo::Nodo(new_id, pos, tipo, pociones));
	return new_id;
}

const double Grafo::distancia(const Posicion& p1, const Posicion& p2) {
	return sqrt( (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second) );
}

Solucion Grafo::tsp_backtracking(unsigned int capacidad_mochila) {
	Solucion res;
	res.distancia_recorrida = -1;

	vector<bool> visitados(_nodos.size(), false);
	for (unsigned int i = 0; i < _nodos.size(); i++) {
		if (_nodos[i].tipo == Pokeparada) {
			visitados[i] = true;
			vector<unsigned int> camino(1, _nodos[i].id);
			camino.reserve(_nodos.size());
			Solucion sub_res = recursivo(i, capacidad_mochila, 0, visitados, camino);
			visitados[i] = false;
			if (res.distancia_recorrida > sub_res.distancia_recorrida || res.distancia_recorrida == -1) res = sub_res;
		}
	}
	return res;
}

Solucion Grafo::recursivo(unsigned int id_actual, unsigned int capacidad_mochila, unsigned int pociones_actuales, vector<bool>& visitados, vector<unsigned int>& camino_actual) {

	if (_nodos[id_actual].tipo == Pokeparada) {
		if (pociones_actuales + 3 <= capacidad_mochila) pociones_actuales += 3;
		else pociones_actuales = capacidad_mochila;
	} else pociones_actuales -= _nodos[id_actual].pociones_necesarias;

	Solucion res;
	res.distancia_recorrida = -1;

	if (!esSolucion(_nodos, visitados) && haySolucion(_nodos, visitados, pociones_actuales, capacidad_mochila)) {
		for (unsigned int i = 0; i < _nodos.size(); i++) {
			if (!visitados[i] && (!_nodos[i].tipo == Gimnasio or (_nodos[i].pociones_necesarias <= pociones_actuales))) {				
				camino_actual.push_back(_nodos[i].id);
				
				visitados[i] = true;
				
				Solucion sub_res = recursivo(i, capacidad_mochila, pociones_actuales, visitados, camino_actual);

				if (sub_res.distancia_recorrida != -1) sub_res.distancia_recorrida += distancia(_nodos[id_actual].pos, _nodos[i].pos);
				if (res.distancia_recorrida > sub_res.distancia_recorrida || res.distancia_recorrida == -1) res = sub_res;
				
				visitados[i] = false;
				camino_actual.pop_back();
			}
		}
	}
	
	if (esSolucion(_nodos, visitados)) {
		res.distancia_recorrida = 0;
		res.ids = camino_actual;

		// Distancia d = 0;
		// for (unsigned int i = 1; i < camino_actual.size(); i++) {
		// 	d += distancia(_nodos[camino_actual[i]-1].pos, _nodos[camino_actual[i-1]-1].pos);
		// }
		// cout << d << ' ';
		// imprimir_vector(camino_actual, "camino: ");
	}
	return res;
}

bool Grafo::esSolucion(vector<Nodo>& nodos, vector<bool>& visitados) {
	bool res = true;
	for (unsigned int i = 0; i < nodos.size(); i++) {
		res = res & (!(_nodos[i].tipo == Gimnasio) || visitados[i]);
	}
	return res;
}

bool Grafo::haySolucion(vector<Nodo>& nodos, vector<bool>& visitados, unsigned int pociones_actuales, unsigned int capacidad_mochila) {
	bool res = true;
	unsigned int pociones_necesarias = 0;
	unsigned int pociones_disponibles = pociones_actuales;
	for (unsigned int i = 0; i < nodos.size(); i++) {
		if (nodos[i].tipo == Gimnasio) {
			pociones_necesarias += nodos[i].pociones_necesarias;
			res = (nodos[i].pociones_necesarias <= capacidad_mochila);
		} else {
			pociones_disponibles += 3;
		}
	}
	return res & (pociones_necesarias <= pociones_disponibles);
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