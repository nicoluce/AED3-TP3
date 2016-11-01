
import random
import sys
import getopt

def main(argv):

	cantidad_de_gimnasios = int(argv[0])
	cantidad_de_pokeparadas = int(argv[1])
	capacidad_mochila = int(argv[2])
	modo = 'random'
	rango = int(argv[3])
	output = None

	try:
		opts, args = getopt.getopt(argv[4:], 'm:o:', ['modo=', 'output='])
	except getopt.GetoptErrors:
		sys.exit(2)

	for opt, arg in opts:
		if opt in ('-m', '--modo'):
			modo = arg
		elif opt in ('-o', '--output'):
			output = arg
	
	return {'Gimnasios':cantidad_de_gimnasios, 'Pokeparadas':cantidad_de_pokeparadas, 'Mochila':capacidad_mochila, 'Rango':rango, 'Modo':modo, 'Output':output}

def get_posicion(posiciones, rango):
	x = random.randint(1, rango)
	y = random.randint(1, rango)

	while (x, y) in posiciones:
		x = random.randint(1, rango)
		y = random.randint(1, rango)

	return (x, y)

def generar_random(cantidad_de_gimnasios, cantidad_de_pokeparadas, capacidad_mochila, rango, filename=None):
	if filename:
		output = open(filename, 'w')
	else:
		output = sys.stdout

	posiciones = []

	out_string = str(cantidad_de_gimnasios) + ' ' + str(cantidad_de_pokeparadas) + ' ' + str(capacidad_mochila) + '\n'

	for g in xrange(0,cantidad_de_gimnasios):
		pos = get_posicion(posiciones, rango)
		posiciones.append(pos)
		out_string += str(pos[0]) + ' ' + str(pos[1]) + ' '
		out_string += str(random.randint(1, 10)) + '\n'

	for p in xrange(0,cantidad_de_pokeparadas):
		pos = get_posicion(posiciones, rango)
		posiciones.append(pos)
		out_string += str(pos[0]) + ' ' + str(pos[1]) + '\n'

	out_string = out_string[:-1]

	print >>output, out_string

comandos = main(sys.argv[1:])

cantidad_de_gimnasios = comandos['Gimnasios']
cantidad_de_pokeparadas = comandos['Pokeparadas']
capacidad_mochila = comandos['Mochila']
rango = comandos['Rango']
output_filename = comandos['Output']

if cantidad_de_gimnasios*10 > cantidad_de_pokeparadas*3:
	print 'Error: No alcanzan las pokeparadas.'
	sys.exit(2)

if capacidad_mochila < 10:
	print 'Error: La capacidad de la mochila debe ser mayor a 10.'
	sys.exit(2)

if comandos['Modo'] == 'random':
	generar_random(cantidad_de_gimnasios, cantidad_de_pokeparadas, capacidad_mochila, rango, filename=output_filename)




