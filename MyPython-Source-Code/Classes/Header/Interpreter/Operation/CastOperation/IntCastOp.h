#pragma once
#include "CastOperation.h"

class IntCastOp : public CastOperation
{
    std::unique_ptr<Operation> value;
public:
    static const std::string NAME;

    IntCastOp(std::unique_ptr<Operation> value);

    Variable* execute(Context &contex) override;

    ~IntCastOp() override = default;
};
