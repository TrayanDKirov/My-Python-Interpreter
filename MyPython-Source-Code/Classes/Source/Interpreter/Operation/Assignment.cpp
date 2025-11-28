#include "../../../Header/Interpreter/Operation/Assignment.h"

#include "../../../Header/Variable/VariableFactory.h"

const std::string Assignment::ASSIGMENT_OPERATOR = "=";
const std::string Assignment::ASSIGMENT_SYNTAX = "<name> = <value>";

Assignment::Assignment(const std::string& name, const std::string& value)
    : name(name), value(value) { }

void Assignment::execute(Contex& contex)
{
    VariableFactory& variableFactory = VariableFactory::getInstance();

    contex.getScope().assign(name,  unique_ptr<Variable>(variableFactory.create(value)));
}
