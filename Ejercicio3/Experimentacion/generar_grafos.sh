#!/bin/bash

# SET1
# sh generar_grafos.sh 10 150 10 5000 5000 30 30 1

# SET2
# sh generar_grafos.sh 10 150 10 5000 5000 30 30 2

# SET3
# sh generar_grafos.sh 10 150 10 5000 5000 30 30 3

# SET4
# sh generar_grafos.sh 10 150 10 500 500 30 30 2

# SET5
# sh generar_grafos.sh 10 150 10 1000 1000 30 30 2

# SET6
# sh generar_grafos.sh 10 150 10 1000 1000 10 30 2

# SET7
# sh generar_grafos.sh 10 150 10 1000 1000 5 5 2

# 1: cantidad de gim arranque
# 2: tope gim
# 3: cantidad de gim a avanzar
# 4: ancho
# 5: alto
# 6: max pociones
# 7: capacidad mochila
# 8: proporcion pokeparadas

CARPETA='input'

# rm -r $CARPETA
mkdir $CARPETA

for (( i = $1; i <= $2; i += $3 )); do
	./grilla_rand $4 $5 $i $6 $7 $8 > $CARPETA/g_rand_N$i-W$4-H$5-MP$6-Mochila$7-PP$8
done