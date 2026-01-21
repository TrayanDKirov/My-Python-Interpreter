#pragma once
#include "BooleanEqTree.h"
#include "Variable/BoolVariable.h"

class EqualOperation : public BooleanEqTree
{
    BoolVariable* compareInt(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareFloat(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareString(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareBool(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareNone(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    EqualOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~EqualOperation() override = default;
};
