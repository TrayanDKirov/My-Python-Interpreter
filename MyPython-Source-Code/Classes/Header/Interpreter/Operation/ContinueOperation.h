#pragma once
#include "Operation.h"

class ContinueOperation : public Operation
{
public:

    static const std::string NAME;

    ContinueOperation();

    Variable* execute(Context& contex) override;

    ~ContinueOperation() override = default;
};