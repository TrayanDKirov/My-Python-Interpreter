#pragma once
#include "../../Contex/Contex.h"

class Operation
{
public:
    virtual void execute(Contex& contex) = 0;

    virtual ~Operation() = default;
};
