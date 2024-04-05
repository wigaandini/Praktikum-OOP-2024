#ifndef _SUBTRACTEXPRESSION_HPP_
#define _SUBTRACTEXPRESSION_HPP_

#include "Expression.hpp"

class SubstractExpression : public BinaryExpression {
    public:
        SubstractExpression(Expression* x, Expression* y);
        int solve();
};

#endif