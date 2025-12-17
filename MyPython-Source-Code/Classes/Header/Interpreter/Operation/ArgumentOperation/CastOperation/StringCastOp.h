#pragma once
#include <vector>

#include "CastOperation.h"

class StringCastOp : public CastOperation
{
public:
    static const std::string NAME;

    StringCastOp(std::vector<std::unique_ptr<Operation>>& args);

    Variable* execute(Context &contex) override;

    ~StringCastOp() override = default;
};