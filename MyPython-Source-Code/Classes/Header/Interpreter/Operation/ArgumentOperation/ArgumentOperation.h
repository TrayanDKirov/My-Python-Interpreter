#pragma once
#include <memory>
#include <vector>

#include "../Operation.h"

class ArgumentOperation : public Operation
{
protected:
    std::vector<std::unique_ptr<Operation>> args;
public:
    ArgumentOperation(std::vector<std::unique_ptr<Operation>>& args);
};
