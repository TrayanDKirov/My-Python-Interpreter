#include "../../../Header/Interpreter/Operation/WhileOperation.h"

#include "../../../Exception/ValueError.h"
#include "Variable/BoolVariable.h"
#include "Variable/VoidVariable.h"
using std::string;
using std::unique_ptr;

const string WhileOperation::NAME = "while";


WhileOperation::WhileOperation(std::unique_ptr<BasicEqTree>& condition, OperationBody& body)
    : condition(std::move(condition)), body(std::move(body)) { }

Variable* WhileOperation::execute(Context& contex) {
    Variable* condResult = condition->execute(contex);
    auto cond = dynamic_cast<BoolVariable*>(condResult);
    if (!cond) {
        delete condResult;
        
        throw value_error("ValueError: condition in while should return a bool value");
    }

    while (cond->getValue()) {
        delete cond;
        body.execute(contex);
        
        condResult = condition->execute(contex);
        cond = dynamic_cast<BoolVariable*>(condResult);
        if (!cond) {
            delete condResult;
            
            throw value_error("ValueError: condition in while should return a bool value");
        }
    }

    delete cond;

    return VoidVariable::getInstance().clone();
}