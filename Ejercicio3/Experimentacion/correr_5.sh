COLS='opcion_greedy,opcion_busqueda,cant_gim,cant_gim_mismo_costo,cant_poke,cap_mochila,tiempo_armado_grafo,tiempo_greedy,distancia_camino_greedy,tiempo_busqueda,distancia_camino,cant_mejoras,tiempo_swap,vecinos_prom'

echo 'Ejecutando SET1\n'

echo $COLS >> OUT_ej3

for (( i=20; i <= 150; i += 10 )); do
	for (( j=0; j < 5; j += 1 )); do
		echo $i $j; 
		../ej3.out -g 1 -b 0 -r 10 -e -v < ../../Experimentacion/Grafos_random/grafo_random_$(($i))_$j >> OUT_ej3
		../ej3.out -g 1 -b 1 -r 10 -e -v < ../../Experimentacion/Grafos_random/grafo_random_$(($i))_$j >> OUT_ej3
	done
done