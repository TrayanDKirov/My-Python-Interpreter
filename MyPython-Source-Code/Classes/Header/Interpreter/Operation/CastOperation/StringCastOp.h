#pragma once
#include "CastOperation.h"

class StringCastOp : public CastOperation
{
    std::unique_ptr<Variable> value;
public:
    static const std::string NAME;

    StringCastOp(std::unique_ptr<Variable> value);

    std::unique_ptr<Variable> execute(Context &contex) override;

    ~StringCastOp() override = default;
};