# AED3-TP3
TP3 - Algoritmos y Estructuras de Datos III (Heurísticas y Metaherísticas)


Hacer header del tipo grafo, todos son grafos completos, único para todo el tp.

- Exacto:
	Backtracking. Algoritmo recursivo para cada vecino calcular una posible solucion, parecido al 1 del tp1.

- Heuristica Golosa:
	- ir al gimnasio mas barato y si no puedo pagarlo voy a la pokeparada mas cercana.

	Posibilidades: 	. el mas lejos
					. el mas cerca
					. el menos caro
					. el mas caro
					. priorizar mochila llena 

- Heuristica Busqueda Local:
	no lo entiendo

- Metaheuristica:
	menos todavia

------------------------------------------------------------------------------

- heap para gimnasio en base al costo

- Arrancar siempre por una pokeparada
- podas:
	- la suma de pokeparadas*3 + mochila >= al costo de todos los gimnasios restantes
	- si estas en un gimnasio y no te dan las pociones, cortá. (revisar)


Nodo:
	- tipo, gimnasio o pokeparada
	- si es gimnasio, cuantas pociones requiere
	- posicion
	- visitado
	- id

------------------------------------------------------------------------------

- ver tema PC andi o nico para correr tipo SSH
