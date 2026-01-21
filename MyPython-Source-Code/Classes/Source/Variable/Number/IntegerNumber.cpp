#include "../../../Header/Variable/Number/IntegerNumber.h"

IntegerNumber::IntegerNumber(int value) : value(value) { }

std::string IntegerNumber::toString() const
{
    return std::to_string(value);
}

float IntegerNumber::toFloat() const
{
    return (float)value;
}

bool IntegerNumber::toBool() const
{
    return (bool)value;
}

int IntegerNumber::getValue() const
{
    return this->value;
}

Variable * IntegerNumber::clone() const
{
    return new IntegerNumber(*this);
}

bool operator==(const IntegerNumber& left, const IntegerNumber& right) {
    return left.value == right.value;
}
bool operator!=(const IntegerNumber& left, const IntegerNumber& right) {
    return left.value != right.value;
}
bool operator<(const IntegerNumber& left, const IntegerNumber& right) {
    return left.value < right.value;
}
bool operator>(const IntegerNumber& left, const IntegerNumber& right) {
    return left.value > right.value;
}
bool operator<=(const IntegerNumber& left, const IntegerNumber& right) {
    return left.value <= right.value;
}
bool operator>=(const IntegerNumber& left, const IntegerNumber& right) {
    return left.value >= right.value;
}