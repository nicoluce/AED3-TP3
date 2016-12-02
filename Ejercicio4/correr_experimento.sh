# sh correr_experimento.sh

# A1: cantidad de nodos arranque
# A2: tope nodos
# A3: cantidad de nodos a avanzar
# A4: repeticiones
# A5: vecinos para sacar del heap
# A6: iteraciones de la busqueda

A1=10
A2=140
A3=10
A4=1

make

PATH='../Ejercicio3/Experimentacion/input/'
OUT='salida.csv'
COLS='gimnasios,pokeparadas,mochila,tiempo,distancia_original,distancia_final,cantidad_de_mejoras,iteraciones,gim_sacados'


/bin/rm -f $OUT

echo $COLS >> $OUT

echo '*********************************************'
echo 'Cantidad vecinos: 5		Iteraciones:5'
echo '*********************************************'
A5=5
A6=5

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 5		Iteraciones:10'
echo '*********************************************'
A5=5
A6=10

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 5		Iteraciones:15'
echo '*********************************************'
A5=5
A6=15

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 5		Iteraciones:20'
echo '*********************************************'
A5=5
A6=20

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 5		Iteraciones:30'
echo '*********************************************'
A5=5
A6=30

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 5		Iteraciones:40'
echo '*********************************************'
A5=5
A6=40

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 5		Iteraciones:50'
echo '*********************************************'
A5=5
A6=50

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done


echo '*********************************************'
echo 'Cantidad vecinos: 10		Iteraciones:5'
echo '*********************************************'
A5=10
A6=5

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 10		Iteraciones:10'
echo '*********************************************'
A5=10
A6=10

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 10		Iteraciones:15'
echo '*********************************************'
A5=10
A6=15

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 10		Iteraciones:20'
echo '*********************************************'
A5=10
A6=20

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 10		Iteraciones:30'
echo '*********************************************'
A5=10
A6=30

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 10		Iteraciones:40'
echo '*********************************************'
A5=10
A6=40

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 10		Iteraciones:50'
echo '*********************************************'
A5=10
A6=50

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done



echo '*********************************************'
echo 'Cantidad vecinos: 15		Iteraciones:5'
echo '*********************************************'
A5=15
A6=5

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 15		Iteraciones:10'
echo '*********************************************'
A5=15
A6=10

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 15		Iteraciones:15'
echo '*********************************************'
A5=15
A6=15

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 15		Iteraciones:20'
echo '*********************************************'
A5=15
A6=20

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 15		Iteraciones:30'
echo '*********************************************'
A5=15
A6=30

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 15		Iteraciones:40'
echo '*********************************************'
A5=15
A6=40

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done

echo '*********************************************'
echo 'Cantidad vecinos: 15		Iteraciones:50'
echo '*********************************************'
A5=15
A6=50

for (( i=$A1; i <= $A2; i += $A3 )); do
	echo '\n'
	echo 'GRAFO No: '$i'\n';
	for (( j=1; j <= 5; j += 1 )); do
		echo "      "$j
		./ej4.out 1 $A5 0 $A6 -m $A4 < $PATH/g_rand_N$i-W1000-H1000-MP5-Mochila5-PP2-$j >> $OUT
	done
done