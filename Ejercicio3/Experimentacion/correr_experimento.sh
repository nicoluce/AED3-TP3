# sh correr_experimento.sh 10 150 10 10

# 1: cantidad de nodos arranque
# 2: tope nodos
# 3: cantidad de nodos a avanzar
# 4: repeticiones

(cd .. && make)

PATH='input'
COLS='opcion_greedy, opcion_busqueda, cant_gim, cant_gim_mismo_costo, cant_poke, cap_mochila, tiempo_armado_grafo, tiempo_greedy, distancia_camino_greedy, tiempo_busqueda, distancia_camino, cant_mejoras, tiempo_swap,'
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

for (( i = $1; i <= $2; i += $3 )); do
	echo $i;
	../ej3.out -g 1 -b 0 -r $4 -e -v < $PATH/g_rand_N$i-$SET1 >> out-$SET1 2>> err-$SET1
	../ej3.out -g 1 -b 1 -r $4 -e -v < $PATH/g_rand_N$i-$SET1 >> out-$SET1 2>> err-$SET1
done

###################################################
# SET2
###################################################
echo 'Ejecutando SET2\n'

echo $COLS >> out-$SET2

for (( i = $1; i <= $2; i += $3 )); do
	echo $i;
	../ej3.out -g 1 -b 0 -r $4 -e -v < $PATH/g_rand_N$i-$SET2 >> out-$SET2 2>> err-$SET2
	../ej3.out -g 1 -b 1 -r $4 -e -v < $PATH/g_rand_N$i-$SET2 >> out-$SET2 2>> err-$SET2
done

###################################################
# SET3
###################################################
echo 'Ejecutando SET3\n'

echo $COLS >> out-$SET3

for (( i = $1; i <= $2; i += $3 )); do
	echo $i;
	../ej3.out -g 1 -b 0 -r $4 -e -v < $PATH/g_rand_N$i-$SET3 >> out-$SET3 2>> err-$SET3
	../ej3.out -g 1 -b 1 -r $4 -e -v < $PATH/g_rand_N$i-$SET3 >> out-$SET3 2>> err-$SET3
done

###################################################
# SET4
###################################################
echo 'Ejecutando SET4\n'

echo $COLS >> out-$SET4

for (( i = $1; i <= $2; i += $3 )); do
	echo $i;
	../ej3.out -g 1 -b 0 -r $4 -e -v < $PATH/g_rand_N$i-$SET4 >> out-$SET4 2>> err-$SET4
	../ej3.out -g 1 -b 1 -r $4 -e -v < $PATH/g_rand_N$i-$SET4 >> out-$SET4 2>> err-$SET4
done

###################################################
# SET5
###################################################
echo 'Ejecutando SET5\n'

echo $COLS >> out-$SET5

for (( i = $1; i <= $2; i += $3 )); do
	echo $i;
	../ej3.out -g 1 -b 0 -r $4 -e -v < $PATH/g_rand_N$i-$SET5 >> out-$SET5 2>> err-$SET5
	../ej3.out -g 1 -b 1 -r $4 -e -v < $PATH/g_rand_N$i-$SET5 >> out-$SET5 2>> err-$SET5
done

###################################################
# SET6
###################################################
echo 'Ejecutando SET6\n'

echo $COLS >> out-$SET6

for (( i = $1; i <= $2; i += $3 )); do
	echo $i;
	../ej3.out -g 1 -b 0 -r $4 -e -v < $PATH/g_rand_N$i-$SET6 >> out-$SET6 2>> err-$SET6
	../ej3.out -g 1 -b 1 -r $4 -e -v < $PATH/g_rand_N$i-$SET6 >> out-$SET6 2>> err-$SET6
done

###################################################
# SET7
###################################################
echo 'Ejecutando SET7\n'

echo $COLS >> out-$SET7

for (( i = $1; i <= $2; i += $3 )); do
	echo $i;
	../ej3.out -g 1 -b 0 -r $4 -e -v < $PATH/g_rand_N$i-$SET7 >> out-$SET7 2>> err-$SET7
	../ej3.out -g 1 -b 1 -r $4 -e -v < $PATH/g_rand_N$i-$SET7 >> out-$SET7 2>> err-$SET7
done