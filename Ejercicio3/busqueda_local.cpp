#include "busqueda_local.h"

// ******************************
// Parseo Entrada
// ******************************

void parseo_entrada_busqueda_local(Grafo& g, GrafoCompleto<NodoP>& gc, int n, int m){
	string buffer;
	vector<int>entrada_parseada;

	for(int i = 0; i < n; i++){
		getline(cin, buffer, '\n');
		entrada_parseada = split(buffer, ' ');
		g.agregar_gimnasio(pair<int, int>(entrada_parseada[0], entrada_parseada[1]), entrada_parseada[2]);
		NodoP aux(pair<int, int>(entrada_parseada[0], entrada_parseada[1]), Gimnasio, entrada_parseada[2]);
		gc.agregarNodo(aux);
	}

	for(int i = 0; i < m; i++){
		getline(cin, buffer, '\n');
		entrada_parseada = split(buffer, ' ');
		g.agregar_pokeparada(pair<int, int>(entrada_parseada[0], entrada_parseada[1]));
		NodoP aux(pair<int, int>(entrada_parseada[0], entrada_parseada[1]), Pokeparada, 0);
		gc.agregarNodo(aux);
	}
}

// ******************************
// Calculo de vecinos
// ******************************

bool esCaminoValido(Camino<NodoP>& c, int capacidadMochila){
	int pociones = 0;
	int pesoActual = 0;
	for(int i = 0; i < c.largo(); ++i){
		if(esPokeparada(c.iesimoElemento(i))){
			pociones += min(MAX_POCIONES_POKEPARADA, capacidadMochila - pesoActual);
		} else {
			// entonces es gimnasio, si tengo menos pociones que lo que cuesta el gimnasio entonces perdi
			if(pociones < c.iesimoElemento(i).pociones)
				return false;
			pociones -= c.iesimoElemento(i).pociones;
		}
	}
	return true;
}

void vecinos_swap(Camino<NodoP>& c, int capacidadMochila, vector< Camino<NodoP> >& res){
	for(int i = 0; i < c.largo(); ++i){
		for(int j = i+1; j < c.largo(); ++j){
			c.swap(i, j);
			if(esCaminoValido(c, capacidadMochila))
				res.push_back(c);
			c.swap(i, j); // vuelvo a swapear para no modificar al c original
		}
	}
}

void vecinos_otros(Camino<NodoP>& c, vector< Camino<NodoP> >& res){
	return;	
}

// ******************************
// Busqueda Local
// ******************************

Solucion busquedaLocal(Solucion res, GrafoCompleto<NodoP>& gc, int capacidad_mochila, int opcion_busqueda){
	// armo el camino a partir de res:
	vector<NodoP> secuNodos;
	vector<int> secuIndex;
	for(unsigned int i = 0; i < res.ids.size(); ++i){
		secuNodos.push_back(gc.iesimoNodo(res.ids[i]-1)); // el -1 porque los ids empiezan desde 1
		secuIndex.push_back(res.ids[i]);
	}

	Camino<NodoP> camino(secuNodos, secuIndex);

	// itero hasta que no mejoro mas
	bool mejoraLaSolucion;
	do {
		mejoraLaSolucion = false;
		// calculo los vecinos
		vector< Camino<NodoP> > vecinos;
		switch(opcion_busqueda){
			case 0:
				vecinos_swap(camino, capacidad_mochila, vecinos);
				break;
			case 1:
				vecinos_otros(camino, vecinos);
				break;
		}

		// busco el minimo de todos los vecinos tal que, a su vez, sea menor a lo que ya tenia
		Distancia distMin = camino.distanciaTotal();
		int indexMin = -1;
		for(int i = 0; i < (int)vecinos.size(); ++i){
			if(vecinos[i].distanciaTotal() < distMin){
				indexMin = i;
				mejoraLaSolucion = true;
			}
		}
		
		// actualizo el camino con el minimo de los vecinos
		if(mejoraLaSolucion){
			camino = vecinos[indexMin];
		}

	} while(mejoraLaSolucion);

	Solucion s;
	s.distancia_recorrida = camino.distanciaTotal();
	for(int i = 0; i < camino.largo(); ++i){
		s.ids.push_back((unsigned int)camino.iesimoId(i));
	}
	return s;
}

// ******************************
// Funciones Auxiliares
// ******************************

int min(int a, int b){ return a < b ? a : b;}

bool esPokeparada(const NodoP& n){
	return n.t == Pokeparada;
}

double distancia(const Posicion& p1, const Posicion& p2){
	return sqrt( (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second) );
}