#pragma once
#include "Variable.h"

class NoneVariable : public Variable
{
    std::string value = NAME;

public:
    static const std::string NAME;

    std::string toString() const override;

    Variable * clone() const override;

    ~NoneVariable() override = default;
};
