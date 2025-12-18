#include "../../../../Header/Interpreter/Operation/ArgumentOperation/ArgumentOperation.h"

#include "../../../../Header/Variable/VoidVariable.h"
using std::vector;
using std::unique_ptr;

vector<unique_ptr<Variable>> ArgumentOperation::getArgs(Context& context) {
    vector<unique_ptr<Variable>> result;
    for (size_t i = 0; i < args.size(); i++)
    {
        Variable* var = args[i].get()->execute(context);
        if (VoidVariable* voidVar = dynamic_cast<VoidVariable*>(var)) {
            delete voidVar;
            continue;
        }
        result.push_back(unique_ptr<Variable>(var));
    }

    return result;
}

ArgumentOperation::ArgumentOperation(vector<unique_ptr<Operation>>& args)
{
    for (size_t i = 0; i < args.size(); i++) {
        this->args.push_back(std::move(args[i]));
    }
}
