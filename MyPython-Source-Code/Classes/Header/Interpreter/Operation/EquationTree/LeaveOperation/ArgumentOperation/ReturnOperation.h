#pragma once
#include <string>

#include "Interpreter/Operation/Operation.h"

class ReturnOperation : public Operation {
    std::unique_ptr<Operation> opToGetResult;
    
public:

    static const std::string NAME;

    ReturnOperation(std::unique_ptr<Operation>&& opToGetResult);

    Variable* execute(Context& contex) override;

    ~ReturnOperation() override = default;
};