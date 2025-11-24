#pragma once
#include <string>
#include <vector>

#include "Operation.h"

class OperationFactory
{
public:
    Operation* create(const std::vector<std::string>& tokens) const;
};
