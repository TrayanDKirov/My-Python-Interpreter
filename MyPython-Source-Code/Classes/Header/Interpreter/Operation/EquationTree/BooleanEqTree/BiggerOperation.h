#pragma once
#include "BooleanEqTree.h"
#include "Variable/BoolVariable.h"

class BiggerOperation : public BooleanEqTree
{
    BoolVariable* compareInt(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareFloat(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    BiggerOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~BiggerOperation() override = default;
};
