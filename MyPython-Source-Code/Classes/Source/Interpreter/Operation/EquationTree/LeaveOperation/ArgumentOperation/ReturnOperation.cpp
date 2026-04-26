

#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/ReturnOperation.h"

#include "../../../../../../Exception/Errors/SyntaxError.h"
#include "../../../../../../Exception/InterpreterCalls/ReturnCall.h"
#include "Variable/VoidVariable.h"
using std::string;

const string ReturnOperation::NAME = "return";

ReturnOperation::ReturnOperation(std::unique_ptr<Operation>&& opToGetResult)
    : opToGetResult(std::move(opToGetResult)) { }

Variable * ReturnOperation::execute(Context& contex) {
    Variable* result = opToGetResult->execute(contex);
    if (dynamic_cast<VoidVariable*>(result))
        throw syntax_error("resultless operation can not be in return");
    
    throw return_call("only function should have return. ", result);
}
