#pragma once
#include "Variable.h"

class BoolVariable : public Variable {
    bool value;

public:
    static const std::string TRUE_STR;
    static const std::string FALSE_STR;

    BoolVariable(const std::string& value);
    BoolVariable(bool value);

    std::string toString() const override;
    int toInt() const;
    float toFloat() const;

    Variable* clone() const override;
    ~BoolVariable() override = default;
};
