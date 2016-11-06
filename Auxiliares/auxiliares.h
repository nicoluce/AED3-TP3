#ifndef __AUXILIARES_H__
#define __AUXILIARES_H__

#include <vector>
#include <string>
#include <iostream>

using namespace std;

std::vector<int> split(const std::string& s, char delim);

template<typename T>
void imprimir_vector(const std::vector<T>& v, const std::string& v_name = "") {
	std::cout << v_name;
	for (unsigned int i = 0; i < v.size(); i++) {
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;
}

#endif 
