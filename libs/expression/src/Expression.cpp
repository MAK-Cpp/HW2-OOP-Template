#include "Expression.h"

#include <stdexcept>

#include "Add.h"
#include "Divide.h"
#include "Multiply.h"
#include "Negate.h"
#include "Subtract.h"

class NotImplementedException: public std::logic_error {
public:
    NotImplementedException() : std::logic_error("Method is not implemented!") {}
};

Multiply Expression::operator*(Expression const&) const {
    throw NotImplementedException();
}

Add Expression::operator+(Expression const&) const {
    throw NotImplementedException();
}

Subtract Expression::operator-(Expression const&) const {
    throw NotImplementedException();
}

Negate Expression::operator-() const {
    throw NotImplementedException();
}

Divide Expression::operator/(Expression const&) const {
    throw NotImplementedException();
}

Expression::~Expression() {
    // TODO: Implement
}