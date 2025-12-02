#include "../../../Header/Interpreter/Operation/Assignment.h"

#include "../../../Header/Variable/NoneVariable.h"
#include "../../../Header/Variable/VariableFactory.h"

using std::unique_ptr;
using std::string;

const string Assignment::ASSIGMENT_OPERATOR = "=";
const string Assignment::ASSIGMENT_SYNTAX = "<name> = <value>";

Assignment::Assignment(const string& name, unique_ptr<Operation> operation)
    : name(name), operation(std::move(operation)) { }

unique_ptr<Variable> Assignment::execute(Context& contex)
{
    contex.getScope().assign(name,  operation->execute(contex));
    return std::make_unique<NoneVariable>();
}
