#pragma once
#include "OperationBody.h"
#include "EquationTree/BasicEqTree.h"

class WhileOperation : public Operation
{
    std::unique_ptr<BasicEqTree> condition;
    OperationBody body;

public:

    static const std::string NAME;

    WhileOperation(std::unique_ptr<BasicEqTree>& condition, OperationBody& body);

    Variable* execute(Context& contex) override;

    ~WhileOperation() override = default;
};