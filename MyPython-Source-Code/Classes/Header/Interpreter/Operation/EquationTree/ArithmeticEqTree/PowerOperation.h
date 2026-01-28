#pragma once
#include "ArithmeticEqTree.h"
#include "Variable/Number/Number.h"

class PowerOperation : public ArithmeticEqTree
{
    Number* powerInt(Variable* leftVar, Variable* rightVar);
    Number* powerFloat(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    PowerOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~PowerOperation() override = default;
};