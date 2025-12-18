#pragma once
#include "ArgumentOperation.h"

class PrintOperation : public ArgumentOperation
{
    std::string sep;
    std::string end;
    std::vector<std::unique_ptr<Variable>> variables;

    void assignVars(Context& contex);
public:
    static const std::string NAME;

    PrintOperation(std::vector<std::unique_ptr<Operation>>& args);

    Variable* execute(Context& contex) override;

    ~PrintOperation() override = default;
};
