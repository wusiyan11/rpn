
#include <string>
#include <iostream>
#include "expr.h"

using namespace std;

class Num : public Expr {
	const int a;
	string opera;
public:
	Num(int x, string opera);
	int eval() const;
	std::string prettyPrint() const;
};
