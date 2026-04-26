#pragma once
#include "Number.h"

class FloatingPointNumber : public Number {
    float value = 0.0;
public:
    static const float EPSI;
    
    FloatingPointNumber(float value);

    std::string toString() const override;
    int toInt() const;
    int toBool() const;

    float getValue() const;

    Variable* clone() const override;
    ~FloatingPointNumber() override = default;

    friend FloatingPointNumber operator+(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend FloatingPointNumber operator-(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend FloatingPointNumber operator*(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend FloatingPointNumber operator/(const FloatingPointNumber& left, const FloatingPointNumber& right);

    friend FloatingPointNumber power(const FloatingPointNumber& left, const FloatingPointNumber& right);

    friend bool operator==(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator!=(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator<(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator>(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator<=(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator>=(const FloatingPointNumber& left, const FloatingPointNumber& right);
};