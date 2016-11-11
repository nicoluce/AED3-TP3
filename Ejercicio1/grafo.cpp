#include <math.h>
#include <utility>

#include "grafo.h"

int recursiones = 0;
int podas = 0;
int soluciones = 0;


Grafo::Grafo(unsigned int cantidad_de_nodos) {
	this->_nodos.reserve(cantidad_de_nodos);
}

unsigned int Grafo::agregar_nodo(const Posicion& pos, const Tipo& tipo, unsigned int pociones) {
	unsigned int new_id = this->_nodos.size() + 1;
	this->_nodos.push_back(Grafo::Nodo(new_id, pos, tipo, pociones));
	return new_id;
}

const double distancia(const Posicion& p1, const Posicion& p2) {
	return sqrt( (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second) );
}

Solucion Grafo::tsp_backtracking(unsigned int mochila) {

	//---- Para experimentacion ----

	recursiones = 1;
	podas = 0;
	soluciones = 0;

	//------------------------------

	capacidad_mochila = mochila;
	visitados = vector<bool>(_nodos.size(), false);
	distancia_resultado = -1;
	camino_resultado.clear();

	for (unsigned int i = 0; i < _nodos.size(); i++) {
		if (_nodos[i].tipo == Pokeparada) {
			visitados[i] = true;
			vector<unsigned int> camino(1, _nodos[i].id);
			camino.reserve(_nodos.size());
			recursivo(i, 0, 0, camino);
			visitados[i] = false;
		}
	}

	Solucion res;
	res.ids = camino_resultado;
	res.distancia_recorrida = distancia_resultado;

	return res;
}

void Grafo::recursivo(unsigned int indice_actual, unsigned int pociones_actuales, Distancia distancia_recorrida, vector<unsigned int>& camino_actual) {

	//---- Para experimentacion ----
	recursiones++;
	//------------------------------

	// PODA: Si ya se conoce un resultado mejor, corta.
	if ((distancia_recorrida > distancia_resultado && distancia_resultado != -1) || !haySolucion(pociones_actuales)) {
		//---- Para experimentacion ----
		podas++;
		//------------------------------
		return;
	}

	// Aca va todo el manejo de las pociones.
	if (_nodos[indice_actual].tipo == Pokeparada) {
		if (pociones_actuales + 3 <= capacidad_mochila) pociones_actuales += 3;
		else pociones_actuales = capacidad_mochila;
	} else pociones_actuales -= _nodos[indice_actual].pociones_necesarias;

	// Si el estado actual no es solucion y todavia existe una...
	if (esSolucion()) {
		//---- Para experimentacion ----
		soluciones++;
		//------------------------------	

		// No chequeo que sea minimo porque la poda ya lo hubiera sacado.
		// Si llego hasta aca es porque es mejor.
		distancia_resultado = distancia_recorrida;
		camino_resultado = camino_actual;
		
		// Distancia d = 0;
		// for (unsigned int i = 1; i < camino_resultado.size(); i++) {
		// 	d += distancia(_nodos[camino_resultado[i]-1].pos, _nodos[camino_resultado[i-1]-1].pos);
		// }

		// cout << distancia_resultado << ' ' << d << ' ';
		// imprimir_vector(camino_resultado, "camino: ");
	} else {
		for (unsigned int i = 0; i < _nodos.size(); i++) {
			// Hago recursion en todos los nodos no visitados.
			if (!visitados[i] && 
				(!(_nodos[i].tipo == Gimnasio) or (_nodos[i].pociones_necesarias <= pociones_actuales)) && // Si es un gimnasio chequeo que me den las pociones
				(!(_nodos[i].tipo == Pokeparada) or (pociones_actuales < capacidad_mochila))) { // Si es pokeparada chequeo que no tenga la mochila llena
				
					camino_actual.push_back(_nodos[i].id);
					visitados[i] = true;
					
					recursivo(i, pociones_actuales, distancia_recorrida + distancia(_nodos[indice_actual].pos, _nodos[i].pos), camino_actual);
					
					visitados[i] = false;
					camino_actual.pop_back();
			}
		}
	}
}

bool Grafo::esSolucion() {
	bool res = true;
	for (unsigned int i = 0; i < _nodos.size(); i++) {
		res = res & (!(_nodos[i].tipo == Gimnasio) || visitados[i]);
	}
	return res;
}

bool Grafo::haySolucion(unsigned int pociones_actuales) {
	bool res = true;
	unsigned int pociones_necesarias = 0;
	unsigned int pociones_disponibles = pociones_actuales;
	for (unsigned int i = 0; i < _nodos.size(); i++) {
		if (_nodos[i].tipo == Gimnasio) {
			pociones_necesarias += _nodos[i].pociones_necesarias;
			res = (_nodos[i].pociones_necesarias <= capacidad_mochila);
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