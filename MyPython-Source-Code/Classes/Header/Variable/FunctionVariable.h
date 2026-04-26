#pragma once
#include <memory>
#include <vector>

#include "Variable.h"
#include "Interpreter/Operation/OperationBody.h"

class FunctionVariable : public Variable {
    std::string name;
    std::vector<std::string> varNames;
    std::shared_ptr<OperationBody> body;

public:
    static const std::string DEF_FUNC_NAME;

    FunctionVariable(const std::string& name, const std::vector<std::string>& varNames,
        std::shared_ptr<OperationBody> body);

    std::string toString() const override;

    std::string getName() const;
    const std::vector<std::string>& getVarNames() const;
    const OperationBody& getBody() const;

    Variable* clone() const override;
    ~FunctionVariable() override = default;
};
