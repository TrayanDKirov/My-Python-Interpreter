#pragma once
#include <vector>

#include "CastOperation.h"

class FloatCastOp : public CastOperation
{
public:
    static const std::string NAME;

    FloatCastOp(std::vector<std::unique_ptr<Operation>>& args);

    Variable* execute(Context &contex) override;

    ~FloatCastOp() override = default;
};
