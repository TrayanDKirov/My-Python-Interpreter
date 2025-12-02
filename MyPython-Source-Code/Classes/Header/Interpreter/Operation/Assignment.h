#pragma once
#include <string>

#include "Operation.h"

class Assignment : public Operation {
    std::string name = "";
    unique_ptr<Variable> value;
public:
    static const std::string ASSIGMENT_OPERATOR;
    static const std::string ASSIGMENT_SYNTAX;

    Assignment(const std::string& name, unique_ptr<Variable> value);

    void execute(Context& contex) override;

    ~Assignment() override = default;
};
