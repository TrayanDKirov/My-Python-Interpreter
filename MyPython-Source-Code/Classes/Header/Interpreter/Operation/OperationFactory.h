#pragma once
#include <string>
#include <vector>

#include "Operation.h"

class VariableFactory;

class OperationFactory
{
    VariableFactory* variableFactory;
public:
    OperationFactory(VariableFactory* variableFactory);

    Operation* searchForAssigment(const std::vector<std::string>& tokens) const;
    Operation* create(const std::vector<std::string>& tokens) const;
};
