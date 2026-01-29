#pragma once
#include "OperationBody.h"
#include "EquationTree/BasicEqTree.h"

class IfOperation : public Operation
{
    std::unique_ptr<BasicEqTree> condition;
    OperationBody ifBody;
    OperationBody elseBody;
    std::unique_ptr<IfOperation> elif;

    bool hasElse;
    bool hasElif;

public:

    static const std::string IF_NAME;
    static const std::string ELSE_NAME;
    static const std::string ELIF_NAME;

    IfOperation(std::unique_ptr<BasicEqTree>& condition, OperationBody& ifBody);
    IfOperation(std::unique_ptr<BasicEqTree>& condition, OperationBody& ifBody,
        OperationBody& elseBody);
    IfOperation(std::unique_ptr<BasicEqTree>& condition, OperationBody& ifBody,
        std::unique_ptr<IfOperation>& elif);

    Variable* execute(Context &contex) override;

    ~IfOperation() override = default;
};
