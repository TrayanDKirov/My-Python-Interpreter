#include "../../../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/EvalOp.h"

#include "../../../../../Header/Variable/VariableFactory.h"
#include "../../../../../Header/Variable/VoidVariable.h"

EvalOp::EvalOp(const std::string& value)
    : value(value) { }

Variable* EvalOp::execute(Context &contex)
{
    VariableFactory variableFactory = VariableFactory::getInstance();
    Variable* var = variableFactory.create(value);

    if (VoidVariable* voidVar = dynamic_cast<VoidVariable*>(var)) {
        return variableFactory.createByName(value, contex);
    }
    
    return var;
}
