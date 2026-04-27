#pragma once
#include "OperationBody.h"

class ImportOperation : public Operation
{
    std::string filePath;

public:

    static const std::string NAME;

    ImportOperation(const std::string& filePath);

    Variable* execute(Context& contex) override;

    ~ImportOperation() override = default;
};