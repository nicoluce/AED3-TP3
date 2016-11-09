#ifndef __CAMINO_HPP__
#define __CAMINO_HPP__

#include "../Ejercicio2/grafo.h"
#include <math.h> // distancia
#define MAX_POCIONES_POKEPARADA 3

using namespace std;

double distancia(const Posicion& p1, const Posicion& p2);

struct NodoP {
	Posicion pos;
	Tipo t;
	int pociones;
	NodoP(const Posicion& pos, Tipo tipo, int poc) : pos(pos), t(tipo), pociones(poc) {};
};

template<class T>
class GrafoCompleto {
	public:
		GrafoCompleto();
		~GrafoCompleto();	
		void agregarNodo(T&);
		const T& iesimoNodo(int i);
	private:
		vector<T> nodos;
};

template<class T>
class Camino {
	public:
		Camino(vector<T>& secuencia, vector<int>& ids); // O(n)
		Camino(const Camino<T>& otro); // O(n)
		~Camino();
		Camino<T>& operator=(const Camino<T>& otro);
		int largo() const; // O(1)
		double distanciaTotal() const; // O(1) -> deja de ser valida luego de un swap o reemplazar. Notar que: c == c.swap(i,j).swap(i,j)
		void actualizarDistancia(); // O(n)
		void swap(int i, int j); // O(1) -> swapea dos nodos del camino
		void reemplazarElemento(int i, T& e, int id); // O(1) -> reemplaza el elemento del camino
		const T& iesimoElemento(int i) const; // O(1)
		int iesimoId(int i) const; // O(1)
		ostream& imprimirCamino(ostream& out) const;
		void actualizarDistanciaSwap(int i, int j);

	private:
		vector<T> _camino;
		vector<int> _orden; 
		vector<int> _ids;
		double _dist;
};

// ******************************
// Grafo Completo
// ******************************

template<class T>
GrafoCompleto<T>::GrafoCompleto(){}

template<class T>
GrafoCompleto<T>::~GrafoCompleto(){}

template<class T>
void GrafoCompleto<T>::agregarNodo(T& nodo){
	nodos.push_back(nodo); // lo copia
}

template<class T>
const T& GrafoCompleto<T>::iesimoNodo(int i){
	return nodos[i];
}

// ******************************
// Camino
// ******************************

template<class T>
Camino<T>::Camino(vector<T>& secuencia, vector<int>& ids){
	_dist = 0;
	for(unsigned int i = 0; i < secuencia.size(); ++i){
		_orden.push_back(i);
		_camino.push_back(secuencia[i]);
		_ids.push_back(ids[i]);
	}
	actualizarDistancia();
}

template<class T>
Camino<T>::Camino(const Camino<T>& otro){
	_dist = 0;
	for(int i = 0; i < otro.largo(); ++i){
		_orden.push_back(otro._orden[i]);
		_camino.push_back(otro._camino[i]);
		_ids.push_back(otro._ids[i]);
	}
	actualizarDistancia();
}

template<class T>
Camino<T>::~Camino(){}

template<class T>
Camino<T>& Camino<T>::operator=(const Camino<T>& otro){
	if(this != &otro){
		_camino = otro._camino;
		_orden = otro._orden;
		_ids = otro._ids;
		actualizarDistancia();
	}
	return *this;
}

template<class T>
int Camino<T>::largo() const {
	return _camino.size();
}

template<class T>
double Camino<T>::distanciaTotal() const {
	return _dist;
}

template<class T>
void Camino<T>::actualizarDistancia(){
	_dist = 0;
	for(int i = 0; i < largo()-1; ++i)
		_dist += distancia(iesimoElemento(i).pos, iesimoElemento(i+1).pos);
}

template<class T>
void Camino<T>::swap(int i, int j){
	int aux = _orden[i];
	_orden[i] = _orden[j];
	_orden[j] = aux;
}

template<class T>
void Camino<T>::reemplazarElemento(int i, T& e, int id){
	_camino[_orden[i]] = e;
	_ids[_orden[i]] = id;
}

template<class T>
const T& Camino<T>::iesimoElemento(int i) const {
	return _camino[_orden[i]];
}

template<class T>
int Camino<T>::iesimoId(int i) const {
	return _ids[_orden[i]];
}

template<class T>
ostream& Camino<T>::imprimirCamino(ostream& out) const {
	// out << "[";
	out << fixed << setprecision(2) << distanciaTotal() << " ";
	out << largo()-1 << " ";
	for(int i = 0; i < largo(); ++i){
		out << iesimoId(i) << " ";
	}
	// out << "\b]"; // '\b' mueve el cursor una pos para atras
	return out;
}

template<class T>
ostream& operator<<(ostream& out, const Camino<T>& c){
	return c.imprimirCamino(out);
}

template<class T>
void Camino<T>::actualizarDistanciaSwap(int i, int j){
	if (j < i) {
		int t = i;
		i = j;
		j = t;
	}

	if(i+1 == j) {
		if (i == 0) {
			// _dist -= distancia(iesimoElemento(j).pos, iesimoElemento(j+1).pos);
			// _dist += distancia(iesimoElemento(i).pos, iesimoElemento(j+1).pos);
		} else {
			_dist -= distancia(iesimoElemento(i).pos, iesimoElemento(i-1).pos);
			_dist += distancia(iesimoElemento(j).pos, iesimoElemento(i-1).pos);
		}

		if (j == largo()-1) {
			// Como no hay caminos de dos nodos, si j == largo -1 entonces i != 0
			// _dist -= distancia(iesimoElemento(i).pos, iesimoElemento(i-1).pos);
			// _dist += distancia(iesimoElemento(j).pos, iesimoElemento(i-1).pos);
		} else {
			_dist -= distancia(iesimoElemento(j).pos, iesimoElemento(j+1).pos);
			_dist += distancia(iesimoElemento(i).pos, iesimoElemento(j+1).pos);
		}

	} else {
		if(i == 0){
			_dist -= distancia(iesimoElemento(i).pos, iesimoElemento(i+1).pos);
			_dist += distancia(iesimoElemento(j).pos, iesimoElemento(i+1).pos);
		} else {
			_dist -= distancia(iesimoElemento(i-1).pos, iesimoElemento(i).pos);
			_dist -= distancia(iesimoElemento(i).pos, iesimoElemento(i+1).pos);

			_dist += distancia(iesimoElemento(i-1).pos, iesimoElemento(j).pos);
			_dist += distancia(iesimoElemento(j).pos, iesimoElemento(i+1).pos);
		}

		if(j == largo()-1){
			_dist -= distancia(iesimoElemento(j-1).pos, iesimoElemento(j).pos);
			_dist += distancia(iesimoElemento(j-1).pos, iesimoElemento(i).pos);
		} else {
			_dist -= distancia(iesimoElemento(j-1).pos, iesimoElemento(j).pos);
			_dist -= distancia(iesimoElemento(j).pos, iesimoElemento(j+1).pos);

			_dist += distancia(iesimoElemento(j-1).pos, iesimoElemento(i).pos);
			_dist += distancia(iesimoElemento(i).pos, iesimoElemento(j+1).pos);
		}
	}
}

#endif