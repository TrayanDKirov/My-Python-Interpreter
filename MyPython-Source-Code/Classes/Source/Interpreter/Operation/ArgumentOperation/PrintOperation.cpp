#include "../../../../Header/Interpreter/Operation/ArgumentOperation/PrintOperation.h"

#include <variant>

#include "../../../../Exception/TypeError.h"
#include "../../../../Header/Interpreter/Operation/ArgumentOperation/CastOperation/StringCastOp.h"
#include "../../../../Header/Variable/NoneVariable.h"
#include "../../../../Header/Variable/VariableFactory.h"
#include "../../../../Header/Variable/Iterable/StringVariable.h"
using std::make_unique;
using std::unique_ptr;
using std::string;

const std::string PrintOperation::NAME = "print";


void PrintOperation::assignVars(Context& myContext) {
    myContext.getScope().assign("end", "'\n'");
    myContext.getScope().assign("sep", "' '");
    this->variables = getArgs(myContext);
    StringVariable* sepVar = dynamic_cast<StringVariable*>(myContext.getScope().get("sep"));
    if (!(sepVar))
        throw type_error(("type of sep must be" + StringCastOp::NAME).c_str());
    StringVariable* endVar = dynamic_cast<StringVariable*>(myContext.getScope().get("end"));
    if (!endVar)
        throw type_error(("type of sep must be" + StringCastOp::NAME).c_str());

    this->sep = sepVar->toString();
    this->end = endVar->toString();
}

PrintOperation::PrintOperation(std::vector<std::unique_ptr<Operation>>& args)
    : ArgumentOperation(args) { }

Variable* PrintOperation::execute(Context& contex)
{
    Context myContext = Context(Scope(&contex.getScope()),
        contex.getInputStream(), contex.getOutputStream());
    assignVars(myContext);
    for (size_t i = 0; i < variables.size(); i++)
    {
        myContext.getOutputStream() << variables[i]->toString();
        if (i != args.size())
        {
            myContext.getOutputStream() << sep;
        }
    }
    myContext.getOutputStream() << end;
    return new NoneVariable();
}
