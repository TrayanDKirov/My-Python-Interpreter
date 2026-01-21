#pragma once

#include "../EquationTree.h"

class BooleanEqTree : public EquationTree
{

public:
    BooleanEqTree(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);
};
