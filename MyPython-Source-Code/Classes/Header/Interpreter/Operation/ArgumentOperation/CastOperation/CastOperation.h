#pragma once
#include "../ArgumentOperation.h"
#include "../../Operation.h"

class CastOperation : public ArgumentOperation
{
    static std::vector<std::unique_ptr<Operation>>& validateArgs(
        std::vector<std::unique_ptr<Operation>>& args);

protected:
    bool isValid();
public:
    CastOperation(std::vector<std::unique_ptr<Operation>>& args);
};