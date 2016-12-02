#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// g++ -std=c++11 grilla_rand.cpp -o grilla_rand
// ./grilla_rand 500 500 10 10 15 2

// alto ancho cantGim maxPociones capMochila proporcionPokeParadas

using namespace std;

int main(int argc, char const *argv[]){
	
	int ancho = atoi(argv[1]);
	int alto = atoi(argv[2]);
	int cantGim = atoi(argv[3]);
	int maxPociones = atoi(argv[4]);
	int capMochila = atoi(argv[5]);
	int proporcionPokeParadas = atoi(argv[6]);

	bool matriz[alto][ancho];
	for(int i = 0; i < alto; ++i){
		for(int j = 0; j < ancho; ++j){
			matriz[i][j] = false;
		}
	}

	string res = "";
	int cantPocMinimasParaGanar = 0;

	unsigned int seed;
	cin >> seed;
	srand(seed);

	for(int i=0; i< cantGim; i++){
		int x = rand() % ancho + 1;
		int y = rand() % alto + 1;
		while(matriz[y-1][x-1]){
			x = rand() % ancho + 1;
			y = rand() % alto + 1;
		}
		matriz[y-1][x-1] = true;
		int p = rand() % maxPociones + 1;
		cantPocMinimasParaGanar += p;
		res = res + to_string(x) + " " + to_string(y) + " " + to_string(p) + "\n";
	}

	int cantPoke = 0;
	int cantPokeMinimasParaGanar = cantPocMinimasParaGanar/3 + 1;

	for(int i=0; i<cantPokeMinimasParaGanar*proporcionPokeParadas; i++){
		int x = rand() % ancho + 1;
		int y = rand() % alto + 1;
		while(matriz[y-1][x-1]){
			x = rand() % ancho + 1;
			y = rand() % alto + 1;
		}
		matriz[y-1][x-1] = true;
		res = res + to_string(x) + " " + to_string(y) + "\n";
	}

	res = to_string(cantGim) + " " + to_string(cantPokeMinimasParaGanar*proporcionPokeParadas) + " " + to_string(capMochila) + "\n" + res;

	cout << res;

	return 0;
}