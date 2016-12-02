#!/bin/bash
# sh correr_experimento.sh 10 150 10 10

# 1: cantidad de nodos arranque
# 2: tope nodos
# 3: cantidad de nodos a avanzar
# 4: repeticiones

A1=10
A2=140
A3=10
A4=10

(cd .. && make)

PATH='input'
COLS='opcion_greedy,opcion_busqueda,cant_gim,cant_gim_mismo_costo,cant_poke,cap_mochila,tiempo_armado_grafo,tiempo_greedy,distancia_camino_greedy,tiempo_busqueda,distancia_camino,cant_mejoras,tiempo_swap,vecinos_prom,largo'
SET1='W5000-H5000-MP30-Mochila30-PP1'
SET2='W5000-H5000-MP30-Mochila30-PP2'
SET3='W5000-H5000-MP30-Mochila30-PP3'
SET4='W500-H500-MP30-Mochila30-PP2'
SET5='W1000-H1000-MP30-Mochila30-PP2'
SET6='W1000-H1000-MP10-Mochila30-PP2'
SET7='W1000-H1000-MP5-Mochila5-PP2'


###################################################
# SET1
###################################################
echo 'Ejecutando SET1\n'

echo $COLS >> out-$SET1

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo $i;
	for (( j=1; j <= 5; j += 1 )); do
		echo "   "$j;
		../ej3.out -g 1 -b 0 -r $A4 -e -v < $PATH/g_rand_N$i-$SET1-$j >> out-$SET1 2>> err-$SET1
		echo "    medio"
		../ej3.out -g 1 -b 1 -r $A4 -e -v < $PATH/g_rand_N$i-$SET1-$j >> out-$SET1 2>> err-$SET1
	done
done

###################################################
# SET2
###################################################
echo 'Ejecutando SET2\n'

echo $COLS >> out-$SET2

for (( i=$A1; i<=$A2; i+=$A3 )); do
	echo $i;
	for (( j=1; j <= 5; j += 1 )); do
		echo "   "$j;
		../ej3.out -g 1 -b 0 -r $A4 -e -v < $PATH/g_rand_N$i-$SET2-$j >> out-$SET2 2>> err-$SET2
		echo "    medio"
		../ej3.out -g 1 -b 1 -r $A4 -e -v < $PATH/g_rand_N$i-$SET2-$j >> out-$SET2 2>> err-$SET2
	done
done

###################################################
# SET3
###################################################
echo 'Ejecutando SET3\n'

echo $COLS >> out-$SET3

for (( i=$A1; i<=$A2; i+=$A3 )); do
	echo $i;
	for (( j=1; j <= 5; j += 1 )); do
		echo "   "$j;
		../ej3.out -g 1 -b 0 -r $A4 -e -v < $PATH/g_rand_N$i-$SET3-$j >> out-$SET3 2>> err-$SET3
		echo "    medio"
		../ej3.out -g 1 -b 1 -r $A4 -e -v < $PATH/g_rand_N$i-$SET3-$j >> out-$SET3 2>> err-$SET3
	done
done

# ##################################################
# SET4
# ##################################################
echo 'Ejecutando SET4\n'

echo $COLS >> out-$SET4

for (( i=$A1; i<=$A2; i+=$A3 )); do
	echo $i;
	for (( j=1; j <= 5; j += 1 )); do
		echo "   "$j;
		../ej3.out -g 1 -b 0 -r $A4 -e -v < $PATH/g_rand_N$i-$SET4-$j >> out-$SET4 2>> err-$SET4
		echo "    medio"
		../ej3.out -g 1 -b 1 -r $A4 -e -v < $PATH/g_rand_N$i-$SET4-$j >> out-$SET4 2>> err-$SET4
	done
done

###################################################
# SET5
###################################################
echo 'Ejecutando SET5\n'

echo $COLS >> out-$SET5

for (( i=$A1; i<=$A2; i+=$A3 )); do
	echo $i;
	for (( j=1; j <= 5; j += 1 )); do
		echo "   "$j;
		../ej3.out -g 1 -b 0 -r $A4 -e -v < $PATH/g_rand_N$i-$SET5-$j >> out-$SET5 2>> err-$SET5
		echo "    medio"
		../ej3.out -g 1 -b 1 -r $A4 -e -v < $PATH/g_rand_N$i-$SET5-$j >> out-$SET5 2>> err-$SET5
	done
done

###################################################
# SET6
###################################################
echo 'Ejecutando SET6\n'

echo $COLS >> out-$SET6

for (( i=$A1; i<=$A2; i+=$A3 )); do
	echo $i;
	for (( j=1; j <= 5; j += 1 )); do
		echo "   "$j;
		../ej3.out -g 1 -b 0 -r $A4 -e -v < $PATH/g_rand_N$i-$SET6-$j >> out-$SET6 2>> err-$SET6
		echo "    medio"
		../ej3.out -g 1 -b 1 -r $A4 -e -v < $PATH/g_rand_N$i-$SET6-$j >> out-$SET6 2>> err-$SET6
	done
done

###################################################
# SET7
###################################################
echo 'Ejecutando SET7\n'

echo $COLS >> out-$SET7

for (( i=$A1; i<=$A2; i+=$A3 )); do
	echo $i;
	for (( j=1; j <= 5; j += 1 )); do
		echo "   "$j;
		../ej3.out -g 1 -b 0 -r $A4 -e -v < $PATH/g_rand_N$i-$SET7-$j >> out-$SET7 2>> err-$SET7
		echo "    medio"
		../ej3.out -g 1 -b 1 -r $A4 -e -v < $PATH/g_rand_N$i-$SET7-$j >> out-$SET7 2>> err-$SET7
	done
done
