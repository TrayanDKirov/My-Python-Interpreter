#pragma once
#include <string>
#include <vector>

#include "../../Variable/VariableFactory.h"
#include "Operation.h"


class OperationFactory
{
    VariableFactory* variableFactory;

    std::vector<std::unique_ptr<Operation>> parseArgs(const std::vector<std::string>& tokens,
        size_t start, size_t end) const;

    Operation* createAssigment(const std::vector<std::string>& tokens, size_t start, size_t end) const;

    Operation* create(const std::vector<std::string>& tokens, size_t start, size_t end) const;
public:

    OperationFactory(VariableFactory* variableFactory);

    Operation* createLeave(const std::vector<std::string>& tokens,
        size_t start, size_t end) const;

    Operation* create(const std::vector<std::string>& tokens) const;
};
