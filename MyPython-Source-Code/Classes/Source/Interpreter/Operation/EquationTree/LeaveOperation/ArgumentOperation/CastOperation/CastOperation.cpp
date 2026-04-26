#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/CastOperation.h"

#include "../../../../../../../Exception/Errors/SyntaxError.h"

std::vector<std::unique_ptr<Operation>>& CastOperation::validateArgs(
    std::vector<std::unique_ptr<Operation>>& args) {
    if (args.size() != 1) {
        throw syntax_error("Cast operations accept only one argument. ");
    }

    return args;
}

bool CastOperation::isValid() {
    return args.size() == 1;
}

CastOperation::CastOperation(std::vector<std::unique_ptr<Operation>>& args)
    : ArgumentOperation(validateArgs(args)) { }
