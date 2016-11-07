Uso: la entrada se lee por stdin, TODOS LOS PARAMETROS SON OPCIONALES

	$ ./ej3.out [-g opcion_greedy] [-b opcion_busqueda] [-r repeticiones] [-e](para experimentar) [-v](dice por cual repeticion va)

	[-g opcion_greedy]
		0 ==> primera parada aleatoria (default)
		1 ==> primera parada elegida

	[-b opcion_busqueda]
		0 ==> vecindario a generado a partir de a lo sumo un swap (default)
		1 ==> vecindario a generado a partir de a lo sumo un dos swaps

	[-r repeticiones]
		k ==> k repeticiones

	[-e] para experimentar
		imprime por stdout con formato csv datos de cada ejecucion

	[-v] dice por cual repeticion va
		imprime por stderr la i-esima repeticion

		

Ejemplos:
	$ ./ej3.out -r 10 -e -b 1 -v < entrada

	$ ./ej3.out 1 0 -m 50 < entrada