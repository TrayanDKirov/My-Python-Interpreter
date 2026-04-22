#include "../../../Header/Interpreter/Operation/Assignment.h"

#include "../../../Header/Variable/NoneVariable.h"
#include "../../../Header/Variable/VariableFactory.h"
#include "../../../Header/Variable/VoidVariable.h"

using std::unique_ptr;
using std::string;

const string Assignment::ASSIGMENT_OPERATOR = "=";
const string Assignment::ASSIGMENT_SYNTAX = "<name> = <value>";

Assignment::Assignment(const string& name, unique_ptr<Operation> operation)
    : name(name), operation(std::move(operation)) { }

Variable* Assignment::execute(Context& contex)
{
    unique_ptr<Variable> value(operation->execute(contex));
    contex.getScope().assign(name,  std::move(value));
    return VoidVariable::getInstance().clone();
}
