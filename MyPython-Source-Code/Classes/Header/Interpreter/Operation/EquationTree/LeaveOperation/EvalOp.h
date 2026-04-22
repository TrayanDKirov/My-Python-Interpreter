#pragma once
#include "LeaveOperation.h"
#include "../../Operation.h"

class VariableFactory;

class EvalOp : public LeaveOperation
{
    std::string value;

public:

    EvalOp(const std::string& value);

    Variable* execute(Context &contex) override;

    ~EvalOp() override = default;
};
