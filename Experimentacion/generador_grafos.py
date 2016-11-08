import matplotlib.pyplot as plt
import random
import sys
import getopt
from math import *

def main(argv):

	cantidad_de_gimnasios = int(argv[0])
	modo = 'random'
	output = None

	try:
		opts, args = getopt.getopt(argv[1:], 'm:o:', ['modo=', 'output='])
	except getopt.GetoptErrors:
		sys.exit(2)

	for opt, arg in opts:
		if opt in ('-m', '--modo'):
			modo = arg
		elif opt in ('-o', '--output'):
			output = arg
	
	return {'Gimnasios':cantidad_de_gimnasios, 'Modo':modo, 'Output':output}

def f(x, alpha):
	return int( ceil(alpha * (x**2))) + 1

def nuevaposicion(p1, p2):
	res = []
	for x in xrange(0,p2[0]):
		t = ()
		for y in xrange(0,p2[1]):
			t += (random.randint(p1[0], p1[1]),)
		res.append(t)
	return res

def distancia(p1, p2):
	return sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]))

def nodogenerator(lower_bound, upper_bound, distancia_entre_nodos, cantidad_de_gimnasios, alpha):
	out_string = ''
	total_pociones = 0

	posiciones_gimnasios = nuevaposicion((lower_bound, upper_bound), (1, 2))
	pociones_necesarias = f(0, alpha)
	total_pociones += pociones_necesarias
	out_string = str(posiciones_gimnasios[0][0]) + ' ' + str(posiciones_gimnasios[0][1]) + ' ' + str(pociones_necesarias) + '\n'
	max_pocion = pociones_necesarias

	i = 1
	while len(posiciones_gimnasios) < cantidad_de_gimnasios:
		newval = nuevaposicion((lower_bound, upper_bound), (1,2))[0]
		
		dis = distancia(newval, posiciones_gimnasios[0])
		for x in posiciones_gimnasios:
			dis = min(dis, distancia(newval, x))

		if dis >= distancia_entre_nodos:
			posiciones_gimnasios.append(newval)
			pociones_necesarias = f(i, alpha)
			max_pocion = max(max_pocion, pociones_necesarias)
			total_pociones += pociones_necesarias
			out_string += str(newval[0]) + ' ' + str(newval[1]) + ' ' + str(pociones_necesarias) + '\n'
			i += 1
		else:
			distancia_entre_nodos -= 0.1

	cantidad_de_pokeparadas = random.randint(ceil(total_pociones/3.0), ceil(total_pociones/3.0))

	posiciones_pokeparadas = list(posiciones_gimnasios)
	while len(posiciones_pokeparadas) < cantidad_de_gimnasios + cantidad_de_pokeparadas:
		newval = nuevaposicion((lower_bound, upper_bound), (1,2))[0]
		
		dis = distancia(newval, posiciones_pokeparadas[0])
		for x in posiciones_pokeparadas:
			dis = min(dis, distancia(newval, x))
		
		if dis >= distancia_entre_nodos:
			posiciones_pokeparadas.append(newval)
			out_string += str(newval[0]) + ' ' + str(newval[1]) + '\n'
		else:
			distancia_entre_nodos -= 0.1

	posiciones_pokeparadas = posiciones_pokeparadas[len(posiciones_gimnasios):]


	print posiciones_gimnasios
	print posiciones_pokeparadas

	plt.plot(*zip(*posiciones_gimnasios), marker='o', color='b', ls='')
	plt.plot(*zip(*posiciones_pokeparadas), marker='o', color='r', ls='')
	plt.show()

	out_string = str(cantidad_de_gimnasios) + ' ' + str(cantidad_de_pokeparadas) + ' ' + str(max_pocion + 2) + '\n' + out_string
	return out_string[:-1]

def generar_random(cantidad_de_gimnasios, alpha, rango_posiciones, filename=None):
	if filename:
		output = open(filename, 'w')
	else:
		output = sys.stdout
	# int(rango_posiciones*(1)/100)
	grafo = nodogenerator(0, rango_posiciones, ceil(rango_posiciones*0.1), cantidad_de_gimnasios, alpha)
	print >>output, grafo

def nodogenerator2(lower_bound, upper_bound, distancia_entre_nodos, cantidad_de_gimnasios, alpha):
	out_string = ''
	total_pociones = 0

	posiciones_gimnasios = nuevaposicion((lower_bound, upper_bound/4), (1, 2))
	pociones_necesarias = f(0, alpha)
	total_pociones += pociones_necesarias
	out_string = str(posiciones_gimnasios[0][0]) + ' ' + str(posiciones_gimnasios[0][1]) + ' ' + str(pociones_necesarias) + '\n'
	max_pocion = pociones_necesarias

	i = 1
	while len(posiciones_gimnasios) < cantidad_de_gimnasios:
		newval = nuevaposicion((lower_bound, upper_bound/4), (1,2))[0]
		
		dis = distancia(newval, posiciones_gimnasios[0])
		for x in posiciones_gimnasios:
			dis = min(dis, distancia(newval, x))

		if dis >= distancia_entre_nodos:
			posiciones_gimnasios.append(newval)
			pociones_necesarias = f(i, alpha)
			print pociones_necesarias
			max_pocion = max(max_pocion, pociones_necesarias)
			total_pociones += pociones_necesarias
			out_string += str(newval[0]) + ' ' + str(newval[1]) + ' ' + str(pociones_necesarias) + '\n'
			i += 1
		else:
			distancia_entre_nodos -= 0.1

	cantidad_de_pokeparadas = random.randint(ceil(total_pociones/3.0), ceil(total_pociones/3.0))

	posiciones_pokeparadas = list(posiciones_gimnasios)
	while len(posiciones_pokeparadas) < cantidad_de_gimnasios + cantidad_de_pokeparadas:
		newval = nuevaposicion((3*upper_bound/4, upper_bound), (1,2))[0]
		
		dis = distancia(newval, posiciones_pokeparadas[0])
		for x in posiciones_pokeparadas:
			dis = min(dis, distancia(newval, x))
		
		if dis >= distancia_entre_nodos:
			posiciones_pokeparadas.append(newval)
			out_string += str(newval[0]) + ' ' + str(newval[1]) + '\n'
		else:
			distancia_entre_nodos -= 0.1

	posiciones_pokeparadas = posiciones_pokeparadas[len(posiciones_gimnasios):]


	# print posiciones_gimnasios
	# print posiciones_pokeparadas

	# plt.plot(*zip(*posiciones_gimnasios), marker='o', color='b', ls='')
	# plt.plot(*zip(*posiciones_pokeparadas), marker='o', color='r', ls='')
	# plt.show()

	out_string = str(cantidad_de_gimnasios) + ' ' + str(cantidad_de_pokeparadas) + ' ' + str(total_pociones) + '\n' + out_string
	return out_string[:-1]


def alpha(cantidad_de_gimnasios):
	a = cantidad_de_gimnasios
	while a > 9:
		a = a / 10

	if a == 0:
		a = 1

	a = (0.05/ ( float(cantidad_de_gimnasios) / a))
	return a

def generar_esquinas(cantidad_de_gimnasios, alpha, rango_posiciones, filename=None):
	if filename:
		output = open(filename, 'w')
	else:
		output = sys.stdout

	print >>output, nodogenerator2(0, rango_posiciones, ceil(rango_posiciones*0.1), cantidad_de_gimnasios, alpha)


def generar_mejor_caso(cantidad_de_gimnasios, alpha, rango_posiciones, filename=None):
	if filename:
		output = open(filename, 'w')
	else:
		output = sys.stdout


	posiciones_gimnasios = []
	posiciones_pokeparadas = []

	ultima_posicion = 0
	out_string = ''

	y = 10

	for i in xrange(0,cantidad_de_gimnasios):
		pociones_necesarias = (i+1)*3

		x = ultima_posicion + int(ceil(pociones_necesarias/3.0)) + 2
		out_string = str(x) + ' ' + str(y) + ' ' + str(pociones_necesarias) + '\n' + out_string

		posiciones_gimnasios.append((x, y))

		for p in xrange(0, int(ceil(pociones_necesarias/3.0))):
			p_x = ultima_posicion+2+p
			posiciones_pokeparadas.append((p_x, y))
			out_string += str(p_x) + ' ' + str(y) + '\n'

		ultima_posicion = x


	out_string = str(len(posiciones_gimnasios)) + ' ' + str(len(posiciones_pokeparadas)) + ' ' + str(pociones_necesarias+2) + '\n' + out_string

	print >>output, out_string

	# plt.plot(*zip(*posiciones_gimnasios), marker='o', color='b', ls='')
	# plt.plot(*zip(*posiciones_pokeparadas), marker='o', color='r', ls='')
	# plt.show()




comandos = main(sys.argv[1:])

cantidad_de_gimnasios = comandos['Gimnasios']
rango_posiciones = cantidad_de_gimnasios*(cantidad_de_gimnasios*0.4) # 4%
output_filename = comandos['Output']
alpha = alpha(cantidad_de_gimnasios)

if cantidad_de_gimnasios < 5:
	alpha = 0.1
rango_posiciones = ceil(rango_posiciones)
rango_posiciones = max(rango_posiciones, 10)
if comandos['Modo'] == 'random':
	generar_random(cantidad_de_gimnasios, alpha, rango_posiciones, filename=output_filename)
elif comandos['Modo'] == 'esquina':
	generar_esquinas(cantidad_de_gimnasios, alpha, rango_posiciones, filename=output_filename)
elif comandos['Modo'] == 'mejor':
	generar_mejor_caso(cantidad_de_gimnasios, alpha, rango_posiciones, filename=output_filename)

else:
	sys.exit(2)
