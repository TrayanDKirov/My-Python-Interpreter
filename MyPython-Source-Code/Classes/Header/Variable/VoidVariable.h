#pragma once

#include "Variable.h"

class VoidVariable : public Variable
{
public:
    std::string toString() const override;

    Variable* clone() const override;

    ~VoidVariable() override = default;
};
