#include "../../../Header/Variable/Number/Integer.h"

Integer::Integer(int value) : value(value) { }

std::string Integer::toString() const {
    return std::to_string(value);
}

Variable * Integer::clone() const
{
    return new Integer(*this);
}