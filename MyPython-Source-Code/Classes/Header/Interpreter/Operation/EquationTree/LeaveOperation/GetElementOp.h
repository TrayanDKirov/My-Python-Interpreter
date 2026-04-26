#pragma once
#include <vector>

#include "LeaveOperation.h"
#include "ListEvalOp.h"

class GetElementOp : public LeaveOperation
{
    std::string iterableName;
    std::unique_ptr<Operation> getIndexOp;

public:

    GetElementOp(const std::string& iterableName,
        std::unique_ptr<Operation>& getIndexOp);

    Variable* execute(Context &contex) override;

    ~GetElementOp() override = default;
};
