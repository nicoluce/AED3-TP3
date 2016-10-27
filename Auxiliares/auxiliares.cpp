
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"

using namespace std;

vector<int> split(const string &s, char delim) {
	vector<int> elems;
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(atoi(item.c_str()));
	}
	return elems;
}