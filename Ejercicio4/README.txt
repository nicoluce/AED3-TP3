Uso: la entrada se lee por stdin
	$ ./ej4.out <opcion_greedy_primer_nodo> <opcion_greedy_cercanos> <opcion_busqueda> <cantidad_iteraciones> [-m [repeticiones]]

	<opcion_greedy_primer_nodo>
		0 ==> primera parada aleatoria
		1 ==> primera parada elegida

	<opcion_greedy_cercanos>
		k ==> cantidad de gimnasios que se sacan del heap para ir, se elige uno random

	 <opcion_busqueda>
		0 ==> vecindario generado a partir de swaps
		1 ==> vecindario a generado a partir de a lo sumo un dos swaps

	<cantidad_iteraciones>
		k ==> cantidad de repeticiones del ciclo de GRASP

Ejemplos:
	$ ./ej4.out 0 5 0 100 < entrada

	$ ./ej4.out 0 5 0 100 -m 50 < entrada