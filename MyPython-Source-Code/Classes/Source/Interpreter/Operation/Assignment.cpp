#include "../../../Header/Interpreter/Operation/Assignment.h"

#include "../../../Exception/Errors/TypeError.h"
#include "../../../Header/Variable/NoneVariable.h"
#include "../../../Header/Variable/VariableFactory.h"
#include "../../../Header/Variable/VoidVariable.h"
#include "Variable/Number/IntegerNumber.h"

using std::unique_ptr;
using std::string;

const string Assignment::ASSIGMENT_OPERATOR = "=";
const string Assignment::ASSIGMENT_SYNTAX = "<name> = <value>";

Assignment::Assignment(const string& name, unique_ptr<Operation> operation)
    : name(name), operation(std::move(operation)) { }

Assignment::Assignment(const std::string &name, std::unique_ptr<Operation> getIndexOp,
    std::unique_ptr<Operation> operation)
        : name(name), getIndexOp(std::move(getIndexOp)),
        operation(std::move(operation)) { }

Variable* Assignment::execute(Context& contex) {
    unique_ptr<Variable> value(operation->execute(contex));
    
    if (getIndexOp.get() == nullptr) 
        contex.getScope().assign(name,  std::move(value));
    else {
        Variable* indexVar = getIndexOp->execute(contex);
        auto index = dynamic_cast<IntegerNumber*>(indexVar);
        if (!index) {
            delete indexVar;

            throw type_error("type of index must be int");
        }
        
        contex.getScope().assignByIndex(name, index->getValue(), std::move(value));
        delete indexVar;
    }
    

    return VoidVariable::getInstance().clone();
}
