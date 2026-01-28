#pragma once
#include "Interpreter/Operation/EquationTree/EquationTree.h"

class ArithmeticEqTree : public EquationTree
{
public:
    ArithmeticEqTree(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);
};
