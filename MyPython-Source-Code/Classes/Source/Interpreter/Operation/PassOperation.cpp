#include "Interpreter/Operation/PassOperation.h"

#include "Variable/VoidVariable.h"
using std::string;

const string PassOperation::NAME = "pass";

Variable* PassOperation::execute(Context &contex) {
    return VoidVariable::getInstance().clone();
}
