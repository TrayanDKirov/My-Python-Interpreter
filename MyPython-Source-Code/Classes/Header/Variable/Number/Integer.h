#pragma once
#include "Number.h"

class Integer : public Number {
    int value = 0;
public:
    Integer(int value);

    string toString() const override;

    Variable* clone() const override;
    ~Integer() override = default;
};
