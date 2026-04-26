#include "../../../Header/Variable/Number/FloatingPointNumber.h"
#include <cmath>

const float FloatingPointNumber::EPSI = 0.00001;

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

float FloatingPointNumber::getValue() const {
    return this->value;
}

Variable * FloatingPointNumber::clone() const
{
    return new FloatingPointNumber(*this);
}

FloatingPointNumber operator+(const FloatingPointNumber& left, const FloatingPointNumber& right)
{
    return left.value + right.value;
}
FloatingPointNumber operator-(const FloatingPointNumber& left, const FloatingPointNumber& right)
{
    return left.value - right.value;
}
FloatingPointNumber operator*(const FloatingPointNumber& left, const FloatingPointNumber& right)
{
    return left.value * right.value;
}
FloatingPointNumber operator/(const FloatingPointNumber& left, const FloatingPointNumber& right)
{
    return left.value / right.value;
}

FloatingPointNumber power(const FloatingPointNumber &left, const FloatingPointNumber &right)
{
    return FloatingPointNumber(std::pow(left.value, right.value));
}

bool operator==(const FloatingPointNumber& left, const FloatingPointNumber& right)
{
    return std::fabs(left.value - right.value) < FloatingPointNumber::EPSI;
}
bool operator!=(const FloatingPointNumber& left, const FloatingPointNumber& right) {
    return !(left == right);
}
bool operator<(const FloatingPointNumber& left, const FloatingPointNumber& right) {
    return left.value < right.value && !(left == right);
}
bool operator>(const FloatingPointNumber& left, const FloatingPointNumber& right) {
    return left.value > right.value && !(left == right);
}
bool operator<=(const FloatingPointNumber& left, const FloatingPointNumber& right) {
    return left.value < right.value || left == right;
}
bool operator>=(const FloatingPointNumber& left, const FloatingPointNumber& right) {
    return left.value > right.value || left == right;
}