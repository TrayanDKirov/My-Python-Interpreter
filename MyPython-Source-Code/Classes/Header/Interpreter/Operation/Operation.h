#pragma once
#include "../../Contex/Context.h"

class Operation
{
public:
    virtual std::unique_ptr<Variable> execute(Context& contex) = 0;

    virtual ~Operation() = default;
};
