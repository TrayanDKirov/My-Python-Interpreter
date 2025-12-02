#pragma once
#include "CastOperation.h"

class FloatCastOp : public CastOperation
{
    std::unique_ptr<Variable> value;
public:
    static const std::string NAME;

    FloatCastOp(std::unique_ptr<Variable> value);

    std::unique_ptr<Variable> execute(Context &contex) override;

    ~FloatCastOp() override = default;
};
