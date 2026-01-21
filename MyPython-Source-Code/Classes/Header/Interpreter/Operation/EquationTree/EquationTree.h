#pragma once
#include "BasicEqTree.h"
#include "../Operation.h"

class EquationTree : public BasicEqTree
{
protected:
    std::unique_ptr<BasicEqTree> left;
    std::unique_ptr<BasicEqTree> right;
    std::string operand;

public:

    EquationTree(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right)
        : left(std::move(left)), right(std::move(right)) { }

    ~EquationTree() override = default;
};
