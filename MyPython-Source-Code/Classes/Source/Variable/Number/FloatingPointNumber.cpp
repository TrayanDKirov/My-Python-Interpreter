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

bool operator==(const FloatingPointNumber& left, const FloatingPointNumber& right)
{
    float epsi = 0.000001;

    return abs(left.value - right.value) < epsi;
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