

#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/FuncDefOperation.h"

#include "Variable/FunctionVariable.h"
#include "Variable/VoidVariable.h"
using std::unique_ptr;
using std::vector;
using std::string;

const string FuncDefOperation::NAME = "def";

FuncDefOperation::FuncDefOperation(const std::string &name, const std::vector<std::string> &varNames,
                                   OperationBody&& body) : name(name), varNames(varNames),
                                   body(std::make_shared<OperationBody>(std::move(body))) { }

Variable * FuncDefOperation::execute(Context& contex) {
    contex.getScope().assign(name, unique_ptr<FunctionVariable>(
        new FunctionVariable(name, varNames, body)));

    return VoidVariable::getInstance().clone();
}
