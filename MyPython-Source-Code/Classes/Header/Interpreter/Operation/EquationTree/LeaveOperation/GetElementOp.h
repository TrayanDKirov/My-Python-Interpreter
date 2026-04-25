#pragma once
#include <vector>

#include "LeaveOperation.h"
#include "ListEvalOp.h"

class GetElementOp : public LeaveOperation
{
    std::unique_ptr<Operation> getListOp;
    std::unique_ptr<Operation> getIndexOp;

public:

    GetElementOp(std::unique_ptr<Operation>& getListOp,
        std::unique_ptr<Operation>& getIndexOp);

    Variable* execute(Context &contex) override;

    ~GetElementOp() override = default;
};
