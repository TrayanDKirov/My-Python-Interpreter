#pragma once
#include "ArithmeticEqTree.h"
#include "Variable/Number/Number.h"

class DivOperation : public ArithmeticEqTree
{
    Number* divInt(Variable* leftVar, Variable* rightVar);
    Number* divFloat(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    DivOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~DivOperation() override = default;
};