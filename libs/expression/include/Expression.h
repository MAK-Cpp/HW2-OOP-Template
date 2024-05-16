#ifndef HOMEWORK2_LIBS_EXPRESSION_INCLUDE_EXPRESSION_H_
#define HOMEWORK2_LIBS_EXPRESSION_INCLUDE_EXPRESSION_H_

#include <map>

#include "Exponential.h"

class Add;
class Multiply;
class Subtract;
class Divide;
class Negate;

class Expression {
public:

    Multiply operator*(Expression const&) const;
    Add operator+(Expression const&) const;
    Subtract operator-(Expression const&) const;
    Divide operator/(Expression const&) const;
    Negate operator-() const;
    virtual Exponential eval(std::map<std::string, Exponential> const&) const = 0;
    virtual std::string str() const = 0;
    virtual ~Expression();
};

#endif
