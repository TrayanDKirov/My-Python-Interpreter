#pragma once
#include "Interpreter/Operation/EquationTree/BooleanEqTree/BooleanEqTree.h"
#include "Variable/BoolVariable.h"

class BiggerOrEqualOperation : public BooleanEqTree
{
    BoolVariable* compareInt(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareFloat(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    BiggerOrEqualOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~BiggerOrEqualOperation() override = default;
};
