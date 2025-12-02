#pragma once
#include "Variable.h"

class NoneVariable : public Variable
{
    std::string value = "None";

public:

    std::string toString() const override;

    Variable * clone() const override;

    ~NoneVariable() override = default;
};
