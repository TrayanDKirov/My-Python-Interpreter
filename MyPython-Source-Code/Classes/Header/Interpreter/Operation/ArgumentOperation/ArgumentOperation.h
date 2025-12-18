#pragma once
#include <memory>
#include <vector>

#include "../Operation.h"

class ArgumentOperation : public Operation
{
protected:
    std::vector<std::unique_ptr<Operation>> args;

    std::vector<std::unique_ptr<Variable>> getArgs(Context& context);
public:
    ArgumentOperation(std::vector<std::unique_ptr<Operation>>& args);
};
