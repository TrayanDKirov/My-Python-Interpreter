#pragma once
#include "ArithmeticEqTree.h"
#include "Variable/Iterable/StringVariable.h"
#include "Variable/Number/Number.h"

class PlusOperation : public ArithmeticEqTree
{
    Number* plusInt(Variable* leftVar, Variable* rightVar);
    Number* plusFloat(Variable* leftVar, Variable* rightVar);
    StringVariable* plusString(Variable* leftVar, Variable* rightVar);

public:
    static const std::string NAME;

    PlusOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~PlusOperation() override = default;
};
