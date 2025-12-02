#include "PrintOp.h"

#include "../../../Variable/NoneVariable.h"
using std::make_unique;

const std::string PrintOp::NAME = "print";


PrintOp::PrintOp(std::vector<std::unique_ptr<Variable>> &args)
    : ArgumentOperation(args) { }

std::unique_ptr<Variable> PrintOp::execute(Context& contex)
{
    for (size_t i = 0; i < args.size(); i++)
    {
        contex.getOutputStream() << args[i]->toString();
        if (i != args.size())
        {
            contex.getOutputStream() << sep;
        }
    }
    contex.getOutputStream() << end;
    return make_unique<NoneVariable>();
}
