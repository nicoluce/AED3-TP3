
COLS='gimnasios,pokeparadas,mochila,tiempo,distancia_original,distancia_final,cantidad_de_mejoras,iteraciones,gim_sacados'

echo $COLS >> OUT-ej4.csv
for (( i=60; i <= 90; i += 10 )); do
	for (( j=0; j < 5; j += 1 )); do
		./ej4.out 1 5 0 5 -m 5 < ../Experimentacion/Grafos_random/grafo_random_$(($i))_$j >> OUT-ej4.csv
	done
done