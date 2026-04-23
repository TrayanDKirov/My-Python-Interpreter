#pragma once
#include <vector>

#include "LeaveOperation.h"
#include "../../Operation.h"

class VariableFactory;

class ListEvalOp : public LeaveOperation
{
    std::vector<std::unique_ptr<Operation>> elOps;

public:

    ListEvalOp(std::vector<std::unique_ptr<Operation>>& elOps);

    Variable* execute(Context &contex) override;

    ~ListEvalOp() override = default;
};