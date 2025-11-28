#pragma once
#include <string>

#include "Operation.h"

class Assignment : public Operation {
    std::string name = "";
    std::string value = "";
public:
    static const std::string ASSIGMENT_OPERATOR;
    static const std::string ASSIGMENT_SYNTAX;

    Assignment(const std::string& name, const std::string& value);

    void execute(Contex& contex) override;

    ~Assignment() override = default;
};
