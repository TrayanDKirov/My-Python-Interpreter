#pragma once
#include "CastOperation.h"

class FloatCastOp : public CastOperation
{
    std::unique_ptr<Operation> value;
public:
    static const std::string NAME;

    FloatCastOp(std::unique_ptr<Operation> value);

    Variable* execute(Context &contex) override;

    ~FloatCastOp() override = default;
};
