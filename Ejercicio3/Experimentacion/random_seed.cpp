#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// g++ -std=c++11 random_seed.cpp -o random_seed

using namespace std;

int main(int argc, char const *argv[]){
	
	sleep(1);
	cout << time(NULL);

	return 0;
}