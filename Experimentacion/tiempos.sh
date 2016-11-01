# uso: ./correr_random.sh $CANTIDA DE NODOS$ $REPETICIONES$

# $1 = numero de ejercicio
# $2 = repeticiones
# $3 = entrada

make -C ../Ejercicio$1 || exit

../Ejercicio$1/ej$1.out -m $2 < $3 > data

python tiempos.py $1 < data
