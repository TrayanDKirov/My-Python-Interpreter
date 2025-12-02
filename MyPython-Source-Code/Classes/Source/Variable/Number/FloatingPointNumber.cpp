#include "../../../Header/Variable/Number/FloatingPointNumber.h"

FloatingPointNumber::FloatingPointNumber(float value) : value(value) { }

std::string FloatingPointNumber::toString() const {
    return std::to_string(value);
}

int FloatingPointNumber::toInt() const {
    return (int)value;
}

int FloatingPointNumber::toBool() const {
    return (bool)value;
}

Variable * FloatingPointNumber::clone() const
{
    return new FloatingPointNumber(*this);
}
