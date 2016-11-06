#ifndef __BUSQUEDA_LOCAL_H__
#define __BUSQUEDA_LOCAL_H__

#include "../Auxiliares/auxiliares.h"
#include "camino.hpp"

void parseo_entrada_busqueda_local(Grafo& g, GrafoCompleto<NodoP>& gc, int n, int m);
Solucion busquedaLocal(Solucion res, GrafoCompleto<NodoP>& gc, int capacidad_mochila, int opcion_busqueda);
bool esCaminoValido(Camino<NodoP>& c, int capacidadMochila);
void vecinos_swap(Camino<NodoP>& c, int capacidadMochila, vector< Camino<NodoP> >& res);
void vecinos_otros(Camino<NodoP>& c, vector< Camino<NodoP> >& res);
int min(int a, int b);
bool esPokeparada(const NodoP& n);

#endif