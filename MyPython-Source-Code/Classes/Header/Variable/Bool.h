#pragma once
#include "Variable.h"

class Bool : public Variable {
    bool value;

public:
    static const string TRUE_STR;
    static const string FALSE_STR;

    Bool(const string& value);
    Bool(bool value);

    string toString() const override;

    ~Bool() override = default;
};
