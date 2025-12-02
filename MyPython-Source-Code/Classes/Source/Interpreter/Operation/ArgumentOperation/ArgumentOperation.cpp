#include "../../../../Header/Interpreter/Operation/ArgumentOperation/ArgumentOperation.h"
using std::vector;
using std::unique_ptr;

ArgumentOperation::ArgumentOperation(vector<unique_ptr<Variable>>& args)
{
    for (size_t i = 0; i < args.size(); i++) {
        this->args.push_back(std::move(args[i]));
    }
}