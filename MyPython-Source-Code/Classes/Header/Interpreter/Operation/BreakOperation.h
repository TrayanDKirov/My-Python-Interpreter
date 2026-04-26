#pragma once
#include "Operation.h"

class BreakOperation : public Operation
{
public:

    static const std::string NAME;

    BreakOperation();

    Variable* execute(Context& contex) override;

    ~BreakOperation() override = default;
};