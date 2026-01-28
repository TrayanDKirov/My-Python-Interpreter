#pragma once
#include "ArithmeticEqTree.h"
#include "Variable/Number/Number.h"

class PercentOperation : public ArithmeticEqTree
{
    Number* percentInt(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    PercentOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~PercentOperation() override = default;
};