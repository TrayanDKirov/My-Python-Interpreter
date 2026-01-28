#pragma once
#include "FloatingPointNumber.h"
#include "Number.h"

class IntegerNumber : public Number {
    int value = 0;
public:
    IntegerNumber(int value);

    std::string toString() const override;
    float toFloat() const;
    bool toBool() const;

    int getValue() const;

    Variable* clone() const override;
    ~IntegerNumber() override = default;

    friend IntegerNumber operator+(const IntegerNumber& left, const IntegerNumber& right);
    friend IntegerNumber operator-(const IntegerNumber& left, const IntegerNumber& right);
    friend IntegerNumber operator*(const IntegerNumber& left, const IntegerNumber& right);
    friend FloatingPointNumber operator/(const IntegerNumber& left, const IntegerNumber& right);
    friend IntegerNumber operator%(const IntegerNumber& left, const IntegerNumber& right);

    friend IntegerNumber power(const IntegerNumber& left, const IntegerNumber& right);

    friend IntegerNumber opWholeDivision(const IntegerNumber& left, const IntegerNumber& right);

    friend bool operator==(const IntegerNumber& left, const IntegerNumber& right);
    friend bool operator!=(const IntegerNumber& left, const IntegerNumber& right);
    friend bool operator<(const IntegerNumber& left, const IntegerNumber& right);
    friend bool operator>(const IntegerNumber& left, const IntegerNumber& right);
    friend bool operator<=(const IntegerNumber& left, const IntegerNumber& right);
    friend bool operator>=(const IntegerNumber& left, const IntegerNumber& right);
};
