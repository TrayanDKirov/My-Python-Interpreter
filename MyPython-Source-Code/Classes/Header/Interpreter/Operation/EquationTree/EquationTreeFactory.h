#pragma once
#include <string>
#include <vector>

#include "BasicEqTree.h"

class OperationFactory;

class EquationTreeFactory
{
    OperationFactory* operationFactory;

    BasicEqTree* createPr7(const std::vector<std::string>& tokens, size_t start, size_t end) const;
    BasicEqTree* createPr8(const std::vector<std::string>& tokens, size_t start, size_t end) const;

public:

    EquationTreeFactory(OperationFactory* operationFactory);
    BasicEqTree* create(const std::vector<std::string>& tokens, size_t start, size_t end) const;
};
