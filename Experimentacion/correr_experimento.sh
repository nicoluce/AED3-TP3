#!/bin/bash

# 1: ejercicio
# 2: cantidad de nodos arranque
# 3: tope nodos
# 4: cantidad de nodos a avanzar
# 5: repeticiones

make clean -C ../Ejercicio$1 || exit
make -C ../Ejercicio$1 || exit
if [[ $1 == 1 ]]; then
	echo Aristas,Distancia,Gimnasios,Mochila,Nodos,Podas,Pokeparadas,Recursiones,Soluciones,Tiempo	
elif [[ $1 == 2 ]]; then
	echo Aristas,Distancia,Gimnasios,Mochila,Nodos,Pokeparadas,Tiempo	
fi

for (( i = $2; i <= $3; i += $4 )); do
	for (( j = 0; j < 5; j += 1 )); do
		# echo $i $j
		# python generador_grafos.py $i -m random -o grafo_random_$(($i))_$j
		../Ejercicio$1/ej$1.out -m $5 < ./Grafos_random/grafo_random_$(($i))_$j
	done
done

