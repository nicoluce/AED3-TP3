Uso: la entrada se lee por stdin
	$ ./ej3.out <opcion_greedy> <opcion_busqueda> [-m [repeticiones]]

	<opcion_greedy>
		0 ==> primera parada aleatoria
		1 ==> primera parada elegida de forma eficiente

	 <opcion_busqueda>
		0 ==> vecindario a generado a partir de swaps
		1 ==> por ahora nada

Ejemplos:
	$ ./ej3.out 0 0 < entrada

	$ ./ej3.out 1 0 -m 50 < entrada