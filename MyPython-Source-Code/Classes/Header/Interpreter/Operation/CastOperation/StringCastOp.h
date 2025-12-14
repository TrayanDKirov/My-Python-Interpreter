#pragma once
#include "CastOperation.h"

class StringCastOp : public CastOperation
{
    std::unique_ptr<Operation> value;
public:
    static const std::string NAME;

    StringCastOp(std::unique_ptr<Operation> value);

    Variable* execute(Context &contex) override;

    ~StringCastOp() override = default;
};