#pragma once
#include "BooleanEqTree.h"
#include "Variable/BoolVariable.h"

class DifferentOperation : public BooleanEqTree
{
    BoolVariable* compareInt(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareFloat(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareString(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareBool(Variable* leftVar, Variable* rightVar);
    BoolVariable* compareNone(Variable* leftVar, Variable* rightVar);
public:
    static const std::string NAME;

    DifferentOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~DifferentOperation() override = default;
};
