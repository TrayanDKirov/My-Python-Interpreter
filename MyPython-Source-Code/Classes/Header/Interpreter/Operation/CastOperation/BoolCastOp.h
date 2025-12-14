#pragma once
#include "CastOperation.h"

class BoolCastOp : public CastOperation
{
    std::unique_ptr<Operation> value;
public:
    static const std::string NAME;

    BoolCastOp(std::unique_ptr<Operation> value);

    Variable* execute(Context &contex) override;

    ~BoolCastOp() override = default;
};