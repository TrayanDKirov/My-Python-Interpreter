#pragma once
#include "CastOperation.h"

class BoolCastOp : public CastOperation
{
    std::unique_ptr<Variable> value;
public:
    static const std::string NAME;

    BoolCastOp(std::unique_ptr<Variable> value);

    std::unique_ptr<Variable> execute(Context &contex) override;

    ~BoolCastOp() override = default;
};