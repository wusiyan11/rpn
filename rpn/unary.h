#include <string>
#include <iostream>
#include "expr.h"
using namespace std;


class Unary : public Expr {
  int a;
  string opera;
public:
  Unary(int i,string expression);
  int eval() const;
  string prettyPrint() const;

};
