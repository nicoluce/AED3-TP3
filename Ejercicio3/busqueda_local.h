#ifndef __BUSQUEDA_LOCAL_H__
#define __BUSQUEDA_LOCAL_H__

#include <list>
#include "../Auxiliares/auxiliares.h"
#include "camino.hpp"

#include <chrono>
#define ya chrono::high_resolution_clock::now

extern string EXP_STR_AUX; // para experimentar

void parseo_entrada_busqueda_local(Grafo& g, GrafoCompleto<NodoP>& gc, int n, int m);
Solucion busquedaLocal(Solucion res, GrafoCompleto<NodoP>& gc, int capacidad_mochila, int opcion_busqueda);
bool esCaminoValido(Camino<NodoP>& c, int capacidadMochila);
bool vecinos_swap(Camino<NodoP>& c, int capacidadMochila);
bool vecinos_swap_doble(Camino<NodoP>& c, int capacidadMochila);
int min(int a, int b);
bool esPokeparada(const NodoP& n);

#endif