#pragma once
#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/ArgumentOperation.h"

#include <vector>

#include "Interpreter/Operation/EquationTree/LeaveOperation/EvalOp.h"
#include "Variable/FunctionVariable.h"

class FunctionCallOperation : public ArgumentOperation
{
    std::unique_ptr<EvalOp> opToGetFunc;

    void assignVars(Context& context, FunctionVariable* funcVar);
    
public:
    FunctionCallOperation(std::unique_ptr<EvalOp>&& opToGetFunc,
        std::vector<std::unique_ptr<Operation>>& args);

    Variable* execute(Context& contex) override;

    ~FunctionCallOperation() override = default;
};
