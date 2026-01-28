#include "../../../Header/Variable/Number/IntegerNumber.h"
#include <cmath>

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

IntegerNumber operator+(const IntegerNumber& left, const IntegerNumber& right)
{
    return left.value + right.value;
}
IntegerNumber operator-(const IntegerNumber& left, const IntegerNumber& right)
{
    return left.value - right.value;
}
IntegerNumber operator*(const IntegerNumber& left, const IntegerNumber& right)
{
    return left.value * right.value;
}
FloatingPointNumber operator/(const IntegerNumber& left, const IntegerNumber& right)
{
    return FloatingPointNumber((float)left.value / (float)right.value);
}
IntegerNumber operator%(const IntegerNumber& left, const IntegerNumber& right)
{
    return left.value % right.value;
}

IntegerNumber power(const IntegerNumber &left, const IntegerNumber &right) {
    return IntegerNumber(std::pow(left.value, right.value));
}

IntegerNumber opWholeDivision(const IntegerNumber &left, const IntegerNumber &right) {
    return left.value / right.value;
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