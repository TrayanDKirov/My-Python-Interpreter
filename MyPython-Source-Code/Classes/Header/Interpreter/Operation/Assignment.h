#pragma once
#include "Operation.h"

class Assignment : public Operation {
public:
    void execute() override;

    ~Assignment() override { }
};
