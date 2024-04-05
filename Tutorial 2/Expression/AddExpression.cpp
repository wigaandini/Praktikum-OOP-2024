#include <iostream>
#include "AddExpression.hpp"
using namespace std;

AddExpression::AddExpression(Expression* x, Expression* y) : BinaryExpression(x, y) {}

int AddExpression::solve() {
    return this->x->solve() + this->y->solve();
}