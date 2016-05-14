#include <iostream>
#include <sstream>
#include <string>
#include "expr.h"
#include "num.h"
#include "unary.h"
#include "binary.h"

using std::string;
using std::cin;
using std::cout;
using std::istringstream;
using std::endl;


const int MAX_EXPRS = 10;

int main () {
  string s;
  Expr *stack[MAX_EXPRS];
  int counter=0;
  string expression1;
  string expression2;
// update the stack

  while (cin >> s) {

    if (counter > 9) {
      for (int i=0;i<10;i++) {
        delete stack[i];
      }
      cerr << "Stack overflow" << endl;
      return 1;
    }

    istringstream ss(s);
    int n;
    if (ss >> n) {
      // Intege
      string so_far=to_string(n);
      stack[counter]= new Num (n,so_far); 
      //cout<< stack[counter]->value;
      counter ++;

    }
    else {
      if (s == "NEG" || s == "ABS") {
        //cout<< "test1"<<endl;
        int temp1= stack[counter-1]->eval();
        expression1 = stack[counter-1]->prettyPrint();
        delete stack[counter-1];
        stack[counter-1] = new Unary(temp1,expression1);

      }
    else if (s == "+" || s == "-" || s == "*" || s == "/") {
        int temp1= stack[counter-1]->eval();
        int temp2= stack[counter-2]->eval();
        string expression1= stack[counter-1]->prettyPrint();
        string expression2= stack[counter-2]->prettyPrint();

        delete stack[counter-1];
        delete stack[counter-2];
        stack[counter-2] = new Binary(temp1,temp2,s,expression1,expression2);

        //cout<< "test3"<<endl;
        --counter;
      }
    }
  }
  cout << stack[0]->prettyPrint() << endl;
  cout << "= " << stack[0]->eval() << endl;
  delete stack[0];
}
