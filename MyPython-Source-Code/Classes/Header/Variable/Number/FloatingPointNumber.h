#pragma once
#include "Number.h"

class FloatingPointNumber : public Number {
    float value = 0.0;
public:
    FloatingPointNumber(float value);

    std::string toString() const override;
    int toInt() const;
    int toBool() const;

    Variable* clone() const override;
    ~FloatingPointNumber() override = default;

    friend bool operator==(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator!=(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator<(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator>(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator<=(const FloatingPointNumber& left, const FloatingPointNumber& right);
    friend bool operator>=(const FloatingPointNumber& left, const FloatingPointNumber& right);
};