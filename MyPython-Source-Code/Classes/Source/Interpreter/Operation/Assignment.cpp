#include "../../../Header/Interpreter/Operation/Assignment.h"
#include "../../../Header/Variable/VariableFactory.h"

using std::unique_ptr;
using std::string;

const string Assignment::ASSIGMENT_OPERATOR = "=";
const string Assignment::ASSIGMENT_SYNTAX = "<name> = <value>";

Assignment::Assignment(const string& name, unique_ptr<Variable> value)
    : name(name), value(std::move(value)) { }

void Assignment::execute(Context& contex)
{
    contex.getScope().assign(name,  std::move(value));
}
