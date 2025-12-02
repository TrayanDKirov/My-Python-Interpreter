#include "../../../Header/Interpreter/Operation/EvalOp.h"

#include "../../../Header/Variable/VariableFactory.h"

EvalOp::EvalOp(const std::string& value, const VariableFactory* variableFactory)
    : value(value), variableFactory(variableFactory) { }

std::unique_ptr<Variable> EvalOp::execute(Context &contex)
{
    return variableFactory->create(value);
}
