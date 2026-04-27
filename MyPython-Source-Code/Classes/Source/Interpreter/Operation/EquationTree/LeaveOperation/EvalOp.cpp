#include "../../../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/EvalOp.h"

#include <memory_resource>

#include "../../../../../Header/Variable/VariableFactory.h"
#include "../../../../../Header/Variable/VoidVariable.h"

EvalOp::EvalOp(const std::string& value)
    : value(value) { }

Variable* EvalOp::execute(Context &contex)
{
    VariableFactory variableFactory = VariableFactory::getInstance();
    Variable* var = variableFactory.create(value);

    if (dynamic_cast<VoidVariable*>(var)) {
        delete var;
        
        return variableFactory.createByName(value, contex);
    }
    
    return var;
}
