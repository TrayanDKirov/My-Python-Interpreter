#include "../../../Header/Interpreter/Operation/ContinueOperation.h"

#include "../../../Exception/InterpreterCalls/ContinueCall.h"
using std::string;

const string ContinueOperation::NAME = "continue";

ContinueOperation::ContinueOperation() { }

Variable * ContinueOperation::execute(Context& contex) {
    throw continue_call("continue must be used in a body of for or while");
}
