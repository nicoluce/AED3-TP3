#include <math.h>
#include <utility>
#include <algorithm>

#include "grafo.h"

#define INF 99999999


Grafo::Grafo(unsigned int cantidad_gimnasios, unsigned int cantidad_pokeparadas) {
	// .reserve() sirve para agrandar el espacio del vector, asi evitamos problemas de resize.
	this->_pokeparadas.reserve(cantidad_pokeparadas); 
	priority_queue< Grafo::NodoGimnasio, vector<Grafo::NodoGimnasio>, Grafo::comparacion> cola;	
	this->_gimnasios = 	cola;	

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
	this->_gimnasios.push(Grafo::NodoGimnasio(new_id, pos, Gimnasio, pociones));
	return new_id;
}

/*void Grafo::gimnasios_make_heap() {
	make_heap(this->_gimnasios.begin(), this->_gimnasios.end()); // funcion de C++, aka MaxHeapify
}*/

const double Grafo::distancia(const Posicion& p1, const Posicion& p2) {
	return (double) sqrt( (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second) ); // no se si hace falta el casteo 
}


// Donde va la magia
vector<unsigned int> Grafo::tsp_goloso(unsigned int primer_nodo_id, unsigned int capacidad_mochila) {
	unsigned int mochila = 0;
	unsigned int n = _gimnasios.size();
	unsigned int m = _pokeparadas.size();
	_pokeparadas[primer_nodo_id].visitado = true;
	Posicion desde;

	if(capacidad_mochila >= 3){
		mochila+=3;
	}else{
		mochila = capacidad_mochila;
	}

	vector<unsigned int> res;
	res.push_back(_pokeparadas[primer_nodo_id].id);

	while(res.size() < n+m){
		while(mochila >= _gimnasios.top().pociones_necesarias){
			NodoGimnasio gym = _gimnasios.top();
				res.push_back(gym.id);
				desde = gym.pos;
				mochila -= gym.pociones_necesarias;
				_gimnasios.pop();
			}
		}
		int aux;

		aux = buscarPociones(mochila, capacidad_mochila, desde);
		desde = _pokeparadas[aux].pos;
		if(mochila+3 <= capacidad_mochila){
			mochila += 3;
		}else{
			mochila = capacidad_mochila;
		}

		res.push_back(_pokeparadas[aux].id);



	return res;
	
}


unsigned int Grafo::buscarPociones(int mochila, unsigned int capacidad_mochila, Posicion desde){
	int min = INF;

	Grafo::Nodo res;

	for (unsigned int i = 0; i < _pokeparadas.size(); ++i){
		if(!(_pokeparadas[i].visitado) && distancia(_pokeparadas[i].pos, desde) < min){
			min = distancia(_pokeparadas[i].pos, desde);
			res = _pokeparadas[i];
		}
	}

	return res.id;
}
// para imprimir el grafo, puede ser util
/*const void Grafo::imprimir() {
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
}*/