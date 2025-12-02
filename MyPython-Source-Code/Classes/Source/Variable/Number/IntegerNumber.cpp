#include "../../../Header/Variable/Number/IntegerNumber.h"

IntegerNumber::IntegerNumber(int value) : value(value) { }

std::string IntegerNumber::toString() const {
    return std::to_string(value);
}

float IntegerNumber::toFloat() const {
    return (float)value;
}

bool IntegerNumber::toBool() const {
    return (bool)value;
}

Variable * IntegerNumber::clone() const
{
    return new IntegerNumber(*this);
}
