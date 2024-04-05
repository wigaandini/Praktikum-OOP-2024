#include <iostream>
#include "NegativeExpression.hpp"
using namespace std;

NegativeExpression::NegativeExpression(Expression *x) : UnaryExpression(x) {}

int NegativeExpression::solve() {
    return this->x->solve() * (-1);
}