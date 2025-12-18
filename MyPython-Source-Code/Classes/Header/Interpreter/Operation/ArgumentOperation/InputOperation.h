#pragma once
#include "ArgumentOperation.h"
#include "PrintOperation.h"
#include "../../../Variable/VariableFactory.h"

class InputOperation : public Operation {
    std::unique_ptr<PrintOperation> print;

public:

    static const std::string NAME;

    InputOperation(std::vector<std::unique_ptr<Operation>>& args);

    Variable* execute(Context &contex) override;

    ~InputOperation() override = default;
};
