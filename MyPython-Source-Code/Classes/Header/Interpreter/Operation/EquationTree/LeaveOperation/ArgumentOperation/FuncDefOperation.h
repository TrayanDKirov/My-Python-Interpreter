#pragma once
#include <memory>
#include <vector>

#include "Interpreter/Operation/OperationBody.h"

class FuncDefOperation : public Operation
{
    std::string name;
    std::vector<std::string> varNames;
    std::shared_ptr<OperationBody> body;

public:

    static const std::string NAME;

    FuncDefOperation(const std::string& name, const std::vector<std::string>& varNames,
        OperationBody&& body);

    Variable* execute(Context& contex) override;

    ~FuncDefOperation() override = default;
};
