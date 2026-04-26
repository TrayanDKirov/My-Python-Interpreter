#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/PrintOperation.h"

#include "../../../../../../Exception/Errors/TypeError.h"
#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/ArgumentOperation.h"
#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/StringCastOp.h"
#include "Variable/NoneVariable.h"
#include "Variable/VariableFactory.h"
#include "Variable/Iterable/StringVariable.h"
using std::make_unique;
using std::unique_ptr;
using std::string;

const std::string PrintOperation::NAME = "print";

void PrintOperation::assignVars(Context& myContext) {
    myContext.getScope().assign("end", "'\n'");
    myContext.getScope().assign("sep", "' '");
    this->variables = getArgs(myContext);
    Variable* sepVar = myContext.getScope().get("sep");
    StringVariable* sepStr = dynamic_cast<StringVariable*>(sepVar);
    if (!sepStr) {
        delete sepVar;
        
        throw type_error(("type of sep must be " + StringCastOp::NAME).c_str());
    }
    Variable* endVar = myContext.getScope().get("end");
    StringVariable* endStr = dynamic_cast<StringVariable*>(endVar);
    if (!endStr) {
        delete sepVar;
        delete endVar;
        
        throw type_error(("type of end must be " + StringCastOp::NAME).c_str());
    }

    this->sep = sepStr->getValue();
    this->end = endStr->getValue();

    delete sepVar;
    delete endVar;
}

PrintOperation::PrintOperation(std::vector<std::unique_ptr<Operation>>& args)
    : ArgumentOperation(args) { }

Variable* PrintOperation::execute(Context& contex)
{
    Context myContext = contex.getSubContext();
    assignVars(myContext);
    for (size_t i = 0; i < variables.size(); i++)
    {
        myContext.getOutputStream() << variables[i]->toString();
        if (i != variables.size() - 1)
        {
            myContext.getOutputStream() << sep;
        }
    }
    myContext.getOutputStream() << end;
    return NoneVariable::getInstance().clone();
}
