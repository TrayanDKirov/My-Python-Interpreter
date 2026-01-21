#pragma once
#include "BooleanEqTree.h"

class NotOperation : public BooleanEqTree
{
public:
    static const std::string NAME;

    NotOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~NotOperation() override = default;
};