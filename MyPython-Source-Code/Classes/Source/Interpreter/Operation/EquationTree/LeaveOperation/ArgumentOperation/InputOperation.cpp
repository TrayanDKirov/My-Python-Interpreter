#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/InputOperation.h"

#include <istream>

#include "Interpreter/MpySymbols.h"
#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/PrintOperation.h"
#include "Variable/VariableFactory.h"
using std::unique_ptr;
using std::make_unique;
using std::string;

const std::string InputOperation::NAME = "input";

InputOperation::InputOperation(std::vector<std::unique_ptr<Operation>> &args)
{
    this->print = unique_ptr<PrintOperation>(new PrintOperation(args));
}

Variable* InputOperation::execute(Context& contex)
{
    print->execute(contex);

    string value = "";
    char buffer[MpySymbols::MAX_BUFFER_SIZE];
    contex.getInputStream().getline(buffer, MpySymbols::MAX_BUFFER_SIZE);
    value = std::move(MpySymbols::toMpyString(buffer));

    VariableFactory variableFactory = VariableFactory::getInstance();
    return variableFactory.create(value);
}
