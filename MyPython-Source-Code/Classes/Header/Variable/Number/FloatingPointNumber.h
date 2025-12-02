#pragma once
#include "Number.h"

class FloatingPointNumber : public Number {
    float value = 0.0;
public:
    FloatingPointNumber(float value);

    std::string toString() const override;

    Variable* clone() const override;
    ~FloatingPointNumber() override = default;
};