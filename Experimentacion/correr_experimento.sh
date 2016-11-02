#!/bin/bash

# 1: ejercicio
# 2: cantidad de nodos arranque
# 3: tope nodos
# 4: cantidad de nodos a avanzar
# 5: 
# 6: alpha
# 7: repeticiones

make -C ../Ejercicio$1 || exit

for (( i = $2; i <= $3; i += $4 )); do
	# let pokeparadas=($(($i*10))+3-1)/3

	python generador_grafos.py $i $5 $6 -o grafo_$i

	# echo Corriendo grafo de $i Gimnasios y $pokeparadas pokeparadas...
	./tiempos.sh $1 $7 grafo_$i
done

