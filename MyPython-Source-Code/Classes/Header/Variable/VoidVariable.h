#pragma once

#include "Variable.h"

class VoidVariable : public Variable
{
    VoidVariable() = default;
public:
    std::string toString() const override;

    Variable* clone() const override;

    ~VoidVariable() override = default;

    static VoidVariable& getInstance();
};
