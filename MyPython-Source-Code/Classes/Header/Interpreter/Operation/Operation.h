#pragma once
#include "../../Contex/Context.h"

class Operation
{
public:
    virtual Variable* execute(Context& contex) = 0;

    virtual ~Operation() = default;
};
