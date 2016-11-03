
import sys

gimnasios = int(sys.arg[1])

while gimnasios > 9:
	gimnasios = gimnasios / 10

if gimnasios == 0:
	gimnasios = 1

print (0.5/ ( float(sys.arg[1]) / gimnasios))