#pragma once
#include <string>
#include <vector>

#include "Operation.h"
#include "../ArgsParser.h"

class VariableFactory;

class OperationFactory
{
    VariableFactory* variableFactory;
    ArgsParser argsParser;
public:
    OperationFactory(VariableFactory* variableFactory);

    Operation* searchForSecondOperation(const std::vector<std::string>& tokens,
        size_t start, size_t end) const;
    Operation* searchForAssigment(const std::vector<std::string>& tokens) const;
    Operation* create(const std::vector<std::string>& tokens) const;
};
