#pragma once
#include <string>

#include "Operation.h"

class PassOperation : public Operation {
public:

    static const std::string NAME;

    PassOperation() = default;

    Variable* execute(Context& contex) override;

    ~PassOperation() override = default;
};