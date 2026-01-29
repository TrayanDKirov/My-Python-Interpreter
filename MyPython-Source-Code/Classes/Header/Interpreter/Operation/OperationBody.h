#pragma once
#include <memory>
#include <vector>

#include "Operation.h"

class OperationBody {
    std::vector<std::unique_ptr<Operation>> operations;
public:

    OperationBody() = default;
    OperationBody(std::vector<std::unique_ptr<Operation>>& operations);

    void execute(Context& context);

    bool empty() const;
};
