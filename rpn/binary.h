
#include "expr.h"
#include <string>
#include <iostream>

using namespace std;

class Binary: public Expr{
	int value1;
	int value2;
	string sign;
	string expression1;
	string expression2;
public:
	Binary(int first,int second, string sign, string expression1, string expression2);
	int eval() const;
	std::string prettyPrint() const;
};
