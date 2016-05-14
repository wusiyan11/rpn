#include "unary.h"
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

Unary::Unary(int i,string expression) : a(i), opera(expression) {}

int Unary::eval() const{
	if (opera == "ABS") {
		int temp = abs(a);
		return temp;
	} else {
		int temp = 0 - a;
		return temp;
	}
}

string Unary::prettyPrint() const {
	if (opera == "ABS") {
		return ("|" + opera + "|");
	} else {
		return ("-" + opera);
	}
}
