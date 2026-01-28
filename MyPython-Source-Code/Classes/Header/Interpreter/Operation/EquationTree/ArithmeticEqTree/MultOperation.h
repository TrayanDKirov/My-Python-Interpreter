#pragma once
#include "ArithmeticEqTree.h"
#include "Variable/Number/Number.h"

class MultOperation : public ArithmeticEqTree
{
    Number* multInt(Variable* leftVar, Variable* rightVar);
    Number* multFloat(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    MultOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~MultOperation() override = default;
};