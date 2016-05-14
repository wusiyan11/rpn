#include <iostream>
#include <sstream>
#include <string>
#include "num.h"

using std::string;


Num::Num(int x, string opera) : a(x),opera(opera) {}

int Num::eval() const {
	return a;
}

std::string Num::prettyPrint() const {
	return opera;
}
