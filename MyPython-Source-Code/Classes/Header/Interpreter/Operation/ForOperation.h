#pragma once
#include "OperationBody.h"
#include "EquationTree/BasicEqTree.h"
#include "Variable/Iterable/IterableVariable.h"

class ForOperation : public Operation
{
    std::string nameOfI = "i";
    std::unique_ptr<Operation> opToGetIter;
    OperationBody body;

public:

    static const std::string NAME;
    static const std::string IN;

    ForOperation(const std::string& nameOfI, std::unique_ptr<Operation> opToGetIter, OperationBody& body);

    Variable* execute(Context& contex) override;

    ~ForOperation() override = default;
};
