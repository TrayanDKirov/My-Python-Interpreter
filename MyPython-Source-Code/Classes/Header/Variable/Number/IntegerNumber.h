#pragma once
#include "Number.h"

class IntegerNumber : public Number {
    int value = 0;
public:
    IntegerNumber(int value);

    std::string toString() const override;
    float toFloat() const;
    bool toBool() const;

    Variable* clone() const override;
    ~IntegerNumber() override = default;
};
