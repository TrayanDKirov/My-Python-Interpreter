#pragma once
#include "Variable.h"

class Bool : public Variable {
    bool value;

public:
    static const std::string TRUE_STR;
    static const std::string FALSE_STR;

    Bool(const std::string& value);
    Bool(bool value);

    std::string toString() const override;

    Variable* clone() const override;
    ~Bool() override = default;
};
