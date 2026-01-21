#pragma once
#include "PrintOperation.h"

class InputOperation : public LeaveOperation {
    std::unique_ptr<PrintOperation> print;

public:

    static const std::string NAME;

    InputOperation(std::vector<std::unique_ptr<Operation>>& args);

    Variable* execute(Context &contex) override;

    ~InputOperation() override = default;
};
