
import sys
import fileinput

import pandas
import numpy

ejercicio = sys.argv[1]

if ejercicio == '1':
	
	df = pandas.DataFrame.from_csv("./Datasets/Ejercicio1/dataset.csv")
	dataset = []
	salida = sys.stdin.readlines()
	data_parseada = []
	x = 0
	while x < len(salida)-3:
		solucion = salida[x].split('\n')[0]
		grafo = salida[x+1].split('\n')[0]
		data = salida[x+2].split('\n')[0]
		tiempo = salida[x+3].split('\n')[0]
		if '-1' not in solucion:
			data_parseada.append((solucion, grafo, data, tiempo))
		x += 4

	for solucion, grafo, data, tiempo in data_parseada:
		solucion = solucion.split()
		distancia = float(solucion[0])
		cantidad_aristas = int(solucion[1])
		# camino = [int(c) for c in solucion[2:]]

		grafo = grafo.split('Grafo: ')[1].split()
		gimnasios = int(grafo[0])
		pokeparadas = int(grafo[1])
		nodos = gimnasios + pokeparadas
		mochila = int(grafo[2])

		data = data.split('Data:')[1].split()
		recursiones = int(data[0])
		podas = int(data[1])
		soluciones = int(data[2])

		tiempo = long(tiempo.split('Tiempo: ')[1])
		dataset.append([tiempo, nodos, gimnasios, pokeparadas, mochila, distancia, cantidad_aristas, recursiones, podas, soluciones])

	new_df = pandas.DataFrame(dataset, columns=('Tiempo', 'Nodos', 'Gimnasios', 'Pokeparadas', 'Mochila', 'Distancia', 'Aristas', 'Recursiones', 'Podas', 'Soluciones'))

	df = pandas.concat([df, new_df], ignore_index=True)
	with open('./Datasets/Ejercicio1/dataset.csv', 'w') as f:
		df.to_csv(f)

elif ejercicio == 2:
	# df = pandas.DataFrame.from_csv("./Datasets/Ejercicio2/dataset.csv")
	dataset = []
	salida = sys.stdin.readlines()
	print salida
	data_parseada = []
	x = 0
	while x < len(salida)-3:
		solucion = salida[x].split('\n')[0]
		grafo = salida[x+1].split('\n')[0]
		data = salida[x+2].split('\n')[0]
		tiempo = salida[x+3].split('\n')[0]
		if '-1' not in solucion:
			data_parseada.append((solucion, grafo, data, tiempo))
		x += 4

	# for solucion, grafo, data, tiempo in data_parseada:
	
