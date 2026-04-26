#include "../../../Header/Interpreter/Operation/BreakOperation.h"

#include "../../../Exception/InterpreterCalls/BreakCall.h"
using std::string;

const string BreakOperation::NAME = "break";

BreakOperation::BreakOperation() { }

Variable * BreakOperation::execute(Context &contex) {
    throw break_call("break must be used in body of for or while");
}
