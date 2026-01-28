#pragma once
#include <string>
#include <vector>

#include "Operation.h"
#include "EquationTree/EquationTreeFactory.h"
#include "EquationTree/LeaveOperation/LeaveOperation.h"


class EvalOp;

class OperationFactory
{
    EquationTreeFactory eqTreeFactory;
    std::vector<std::unique_ptr<Operation>> parseArgs(const std::vector<std::string>& tokens,
        size_t start, size_t end);

    Operation* createAssigment(const std::vector<std::string>& tokens, size_t start, size_t end);

    Operation* create(const std::vector<std::string>& tokens, size_t start, size_t end);
public:

    OperationFactory();

    LeaveOperation* createLeave(const std::vector<std::string>& tokens,
        size_t start, size_t end);

    Operation* create(const std::vector<std::string>& tokens);
};
