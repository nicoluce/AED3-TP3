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

bool esCaminoValido(Camino<NodoP>& c, int capacidadMochila) {
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

int a = 0;

bool swap_pokeparadas(Camino<NodoP>& c, int capacidadMochila){

	Distancia distanciaOriginal = c.distanciaTotal();

	for(int i = 0; i < c.largo(); ++i){
		for(int j = i+1; j < c.largo(); ++j){
			if(c.iesimoElemento(i).t == Pokeparada && c.iesimoElemento(j).t == Pokeparada){
				c.actualizarDistanciaSwap(i, j);
				c.swap(i, j);	
				if((distanciaOriginal > c.distanciaTotal())){
					return true;
				}
				c.actualizarDistanciaSwap(i, j);
				c.swap(i, j); // vuelvo a swapear para no modificar al c original
			}
		}
	}

	return false;
}

bool swap_gimnasios(Camino<NodoP>& c, int capacidadMochila){

	Distancia distanciaOriginal = c.distanciaTotal();

	for(int i = 0; i < c.largo(); ++i) {
		for(int j = i+1; j < c.largo(); ++j) {
			if (c.iesimoElemento(i).t == Gimnasio && c.iesimoElemento(j).t == Gimnasio && c.iesimoElemento(i).pociones == c.iesimoElemento(j).pociones) {
				c.actualizarDistanciaSwap(i, j);
				c.swap(i, j);

				if((distanciaOriginal > c.distanciaTotal())){
					return true;
				}
				c.actualizarDistanciaSwap(i, j);
				c.swap(i, j); // vuelvo a swapear para no modificar al c original
			}
		}
	}

	return false;
}


// ******************************
// Busqueda Local
// ******************************

// Para los experimentos: 
// 		EXP_STR_AUX: cant_mejoras, vecinos_total, tiempo_swap
string EXP_STR_AUX = "";

Solucion busquedaLocal(Solucion res, GrafoCompleto<NodoP>& gc, int capacidad_mochila, int opcion_busqueda){
	// armo el camino a partir de res:
	vector<NodoP> secuNodos;
	vector<int> secuIndex;
	for(unsigned int i = 0; i < res.ids.size(); ++i){
		secuNodos.push_back(gc.iesimoNodo(res.ids[i]-1)); // el -1 porque los ids empiezan desde 1
		secuIndex.push_back(res.ids[i]);
	}

	Camino<NodoP> camino(secuNodos, secuIndex);

	unsigned int cant_mejoras = 0; // para experimentar
	double tiempo_swap  = 0; // para experimentar


	// itero hasta que no mejoro mas
	bool mejoraLaSolucion;
	do {

		cerr << cant_mejoras << endl;

		auto start = ya();
		mejoraLaSolucion = false;
		switch(opcion_busqueda){
			case 0:
				mejoraLaSolucion = swap_pokeparadas(camino, capacidad_mochila);
				break;
			case 1:
				mejoraLaSolucion = swap_gimnasios(camino, capacidad_mochila);
				break;
		}

		auto end = ya();
		tiempo_swap += chrono::duration_cast<chrono::duration<double, std::nano>>(end-start).count();
		
		// actualizo el camino con el minimo de los vecinos
		if(mejoraLaSolucion){
			cant_mejoras++; // para experimentar
		}

	} while(mejoraLaSolucion);

	EXP_STR_AUX += to_string(cant_mejoras)+","+to_string(tiempo_swap)+",";

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