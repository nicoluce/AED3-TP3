#include <math.h>
#include <utility>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h> 
#include <algorithm>
#include <random>
#include "grafo.h"

#define INF 99999999


Grafo::Grafo(unsigned int cantidad_gimnasios, unsigned int cantidad_pokeparadas) {
	// .reserve() sirve para agrandar el espacio del vector, asi evitamos problemas de resize.
	this->_pokeparadas.reserve(cantidad_pokeparadas);
	this->_gimnasios.reserve(cantidad_gimnasios);
}

unsigned int Grafo::agregar_pokeparada(const Posicion& pos) {
	// los IDs de los nodos son su posicion en el vector
	unsigned int new_id = this->_pokeparadas.size() + this->_gimnasios.size() + 1;
	this->_pokeparadas.push_back(Grafo::Nodo(new_id, pos, Pokeparada));
	return new_id;
}

unsigned int Grafo::agregar_gimnasio(const Posicion& pos, unsigned int pociones) {
	// los IDs de los nodos son su posicion en el vector
	unsigned int new_id = this->_gimnasios.size() + this->_pokeparadas.size() + 1;
	this->_gimnasios.push_back(Grafo::NodoGimnasio(new_id, pos, Gimnasio, pociones));
	return new_id;
}

const Distancia Grafo::distancia(const Posicion& p1, const Posicion& p2) {
	return (double) sqrt( (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second) ); // no se si hace falta el casteo 
}

// Donde va la magia
Solucion Grafo::tsp_goloso(unsigned int opcion_primer_nodo, unsigned int capacidad_mochila, unsigned int cantidad_cercanos) {
	priority_queue<NodoGimnasio, vector<NodoGimnasio>, greater<NodoGimnasio> > heapnasios (_gimnasios.begin(), _gimnasios.end());
	vector<bool> visitados(_pokeparadas.size(), false);

	unsigned int primer_nodo_indice = elegirPrimerNodo(opcion_primer_nodo);
	unsigned int pociones_en_mochila = 0;
	Solucion res;

	visitados[primer_nodo_indice] = true;
	Posicion posicion_actual = _pokeparadas[primer_nodo_indice].pos;

	if (capacidad_mochila >= 3) pociones_en_mochila += 3;
	else pociones_en_mochila = capacidad_mochila;

	res.ids.push_back(_pokeparadas[primer_nodo_indice].id);
	//res.ids.push_back(primer_nodo_indice);
	while(heapnasios.size() > 0) {
		while(heapnasios.size() > 0 && pociones_en_mochila >= heapnasios.top().pociones_necesarias) {

			vector<NodoGimnasio> gyms;
			unsigned int hasta;
			if(heapnasios.size() >= cantidad_cercanos){
				hasta = cantidad_cercanos;
			}else{
				hasta = heapnasios.size();
			}	
			for (unsigned int i = 0; i < hasta; ++i){
				gyms.push_back(heapnasios.top());
				heapnasios.pop();
			}

			srand(time(NULL));
			int j = rand() % hasta;

			while(gyms[j].pociones_necesarias > pociones_en_mochila){
				heapnasios.push(gyms[j]);
				gyms.erase(gyms.begin() + j);
				j = rand() % gyms.size();
			}

			NodoGimnasio gym = gyms[j];
			gyms.erase(gyms.begin() + j);
			res.ids.push_back(gym.id);
			res.distancia_recorrida += distancia(gym.pos, posicion_actual);
			posicion_actual = gym.pos;

			pociones_en_mochila -= gym.pociones_necesarias;

			for (unsigned int i = 0; i < gyms.size(); ++i){
				heapnasios.push(gyms[i]);
			}		
		}

		if (!heapnasios.empty()) {
			int indice_pokeparada_mas_cercana = buscarPociones(pociones_en_mochila,posicion_actual, visitados);

			if (indice_pokeparada_mas_cercana == -1) {
				res.ids.clear();
				return res;
			}

			res.distancia_recorrida += distancia(_pokeparadas[indice_pokeparada_mas_cercana].pos, posicion_actual);
			posicion_actual = _pokeparadas[indice_pokeparada_mas_cercana].pos;
			
			visitados[indice_pokeparada_mas_cercana] = true;
			
			if (pociones_en_mochila + 3 <= capacidad_mochila) pociones_en_mochila += 3;
			else pociones_en_mochila = capacidad_mochila;

			res.ids.push_back(_pokeparadas[indice_pokeparada_mas_cercana].id);
		}
	}

	return res;
}

int Grafo::buscarPociones(int mochila, Posicion desde, vector<bool>& visitados){
	Distancia min = INF;

	int res = -1;
	unsigned int i = 0;
	while (i < this->_pokeparadas.size()){
		if(!(visitados[i]) && distancia(this->_pokeparadas[i].pos, desde) < min){
			min = distancia(this->_pokeparadas[i].pos, desde);
			res = i;
		}
		i++;
	}
	return res;
}


unsigned int Grafo::elegirPrimerNodo(unsigned int opcion){
	unsigned int res;
	switch (opcion) {
		case 1:
		srand (time(NULL));
		res = (unsigned int) rand() % _pokeparadas.size();// + _pokeparadas.size();
		break;

		case 2:
		unsigned int min = INF;
		NodoGimnasio gym = _gimnasios[0];
		for (unsigned int i = 0; i < _gimnasios.size(); ++i){
			if(_gimnasios[i].pociones_necesarias < min ){
				gym = _gimnasios[i];
				min = _gimnasios[i].pociones_necesarias;
			}
		}

		unsigned int pociones = 0;
		vector<unsigned int> paradas;
		double mini = INF;
		Posicion desde = gym.pos;
		Nodo parada;
		while(pociones < gym.pociones_necesarias){
			mini = INF;
			for (unsigned int i = 0; i < _pokeparadas.size(); ++i){
				if(distancia(_pokeparadas[i].pos, desde) < mini && desde!= _pokeparadas[i].pos){
					mini = distancia(_pokeparadas[i].pos, desde);
					parada = _pokeparadas[i];
					res = i;
				}
			desde = parada.pos;
			}
			pociones +=3;
		}

		break;

	}

	return res;

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