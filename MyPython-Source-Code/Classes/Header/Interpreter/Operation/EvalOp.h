#pragma once
#include "Operation.h"

class VariableFactory;

class EvalOp : public Operation
{
    std::string value;
    const VariableFactory* variableFactory;

public:

    EvalOp(const std::string& value, const VariableFactory* variableFactory);

    Variable* execute(Context &contex) override;

    ~EvalOp() override = default;
};
