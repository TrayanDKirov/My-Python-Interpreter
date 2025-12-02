#pragma once
#include "CastOperation.h"

class IntCastOp : public CastOperation
{
    std::unique_ptr<Variable> value;
public:
    static const std::string NAME;

    IntCastOp(std::unique_ptr<Variable> value);

    std::unique_ptr<Variable> execute(Context &contex) override;

    ~IntCastOp() override = default;
};
