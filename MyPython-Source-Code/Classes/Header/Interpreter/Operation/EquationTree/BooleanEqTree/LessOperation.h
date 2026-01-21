#pragma once
#include "BooleanEqTree.h"
#include "Variable/BoolVariable.h"

class LessOperation : public BooleanEqTree
{
    BoolVariable* compareInt(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareFloat(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    LessOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~LessOperation() override = default;
};
