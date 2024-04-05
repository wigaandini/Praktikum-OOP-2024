#include <iostream>
#include "Expression.hpp"
using namespace std;
#include "AddExpression.hpp"
#include "SubstractExpression.hpp"
#include "NegativeExpression.hpp"

int main() {
    Expression* e;
    e = new AddExpression(
        new TerminalExpression(4),
        new TerminalExpression(6)
    );
    cout << e->solve() << endl;

    e = new SubstractExpression(
        new TerminalExpression(4),
        new TerminalExpression(6)
    );
    cout << e->solve() << endl;

    e = new NegativeExpression(
        new TerminalExpression(1)
    );
    cout << e->solve() << endl;
}