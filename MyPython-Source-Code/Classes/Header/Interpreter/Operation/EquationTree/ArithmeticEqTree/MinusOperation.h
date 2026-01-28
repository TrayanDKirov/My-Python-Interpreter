#pragma once
#include "ArithmeticEqTree.h"
#include "Variable/Number/Number.h"

class MinusOperation : public ArithmeticEqTree
{
    Number* minusInt(Variable* leftVar, Variable* rightVar);
    Number* minusFloat(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    MinusOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~MinusOperation() override = default;
};