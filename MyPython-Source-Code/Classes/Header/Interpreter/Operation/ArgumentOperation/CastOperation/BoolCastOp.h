#pragma once
#include <vector>

#include "CastOperation.h"

class BoolCastOp : public CastOperation
{
public:
    static const std::string NAME;

    BoolCastOp(std::vector<std::unique_ptr<Operation>>& args);

    Variable* execute(Context &contex) override;

    ~BoolCastOp() override = default;
};