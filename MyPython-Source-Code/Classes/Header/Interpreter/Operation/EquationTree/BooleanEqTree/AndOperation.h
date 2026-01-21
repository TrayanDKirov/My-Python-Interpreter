#pragma once
#include "BooleanEqTree.h"

class AndOperation : public BooleanEqTree
{
public:
    static const std::string NAME;

    AndOperation(std::unique_ptr<BasicEqTree> left, std::unique_ptr<BasicEqTree> right);

    Variable* execute(Context& contex) override;

    ~AndOperation() override = default;
};
