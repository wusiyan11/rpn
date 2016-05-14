#include <iostream>
#include <sstream>
#include <string>
#include "binary.h"
using namespace std;

Binary::Binary(int first,int second, string sign, string expression1, string expression2) {
	value1 = first;
	value2 = second;
	this->sign = sign;
	this->expression1 = expression1;
	this->expression2 = expression2;
}

int Binary::eval() const {
	if (sign == "+") {
		return (value1 + value2);
	} else if (sign == "-") {
		return (value1 - value2);
	} else if (sign == "*") {
		return (value1 * value2);
	} else {
		return (value1 / value2);
	}
}

std::string Binary::prettyPrint() const {
	return ("(" + expression1 + sign + expression2 + ")");
}


