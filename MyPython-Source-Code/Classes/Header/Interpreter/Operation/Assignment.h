#pragma once
#include <string>

#include "Operation.h"

class Assignment : public Operation {
    std::string name = "";
    std::unique_ptr<Operation> operation;

public:

    static const std::string ASSIGMENT_OPERATOR;
    static const std::string ASSIGMENT_SYNTAX;

    Assignment(const std::string& name, std::unique_ptr<Operation> operation);

    std::unique_ptr<Variable> execute(Context& contex) override;

    ~Assignment() override = default;
};
