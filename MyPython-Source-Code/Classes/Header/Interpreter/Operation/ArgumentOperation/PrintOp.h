#pragma once
#include "ArgumentOperation.h"

class PrintOp : public ArgumentOperation
{
    char sep = ' ';
    char end = '\n';

public:
    static const std::string NAME;

    PrintOp(std::vector<std::unique_ptr<Variable>>& args);

    std::unique_ptr<Variable> execute(Context& contex) override;

    ~PrintOp() override = default;
};
