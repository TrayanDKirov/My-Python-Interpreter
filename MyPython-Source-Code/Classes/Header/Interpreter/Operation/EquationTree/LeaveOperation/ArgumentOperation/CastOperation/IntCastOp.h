#pragma once
#include <vector>

#include "CastOperation.h"

class IntCastOp : public CastOperation
{
public:
    static const std::string NAME;

    IntCastOp(std::vector<std::unique_ptr<Operation>>& value);

    Variable* execute(Context &contex) override;

    ~IntCastOp() override = default;
};
