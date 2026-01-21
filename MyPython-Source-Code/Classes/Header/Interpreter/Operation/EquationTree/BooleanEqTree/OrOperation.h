#pragma once
#include "BooleanEqTree.h"

class OrOperation :public BooleanEqTree
{
public:
    static const std::string NAME;

    OrOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable * execute(Context &contex) override;

    ~OrOperation() override = default;
};
