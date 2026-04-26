#include "../../../Header/Interpreter/Operation/ForOperation.h"

#include "../../../Exception/Errors/TypeError.h"
#include "../../../Exception/InterpreterCalls/BreakCall.h"
#include "../../../Exception/InterpreterCalls/ContinueCall.h"
#include "Variable/BoolVariable.h"
#include "Variable/VoidVariable.h"
using std::string;
using std::unique_ptr;

const string ForOperation::NAME = "for";
const string ForOperation::IN = "in";

ForOperation::ForOperation(const string& nameOfI,
    unique_ptr<Operation> opToGetIter, OperationBody& body)
    : nameOfI(nameOfI), opToGetIter(std::move(opToGetIter)),
    body(std::move(body)) { }

Variable* ForOperation::execute(Context& contex) {
    Variable* var = opToGetIter->execute(contex);
    auto iterable = dynamic_cast<IterableVariable*>(var);
    if (!iterable) {
        delete var;

        throw type_error("for accepts only iterable");
    }

    Context myContex = contex.getSubContext();

    for (size_t i = 0; i < iterable->size(); i++) {
        myContex.getScope().assign(nameOfI, unique_ptr<Variable>((*iterable)[i]));

        try {
            body.execute(myContex);
        } catch (continue_call& cCall) {
            continue;
        } catch (break_call& bCall) {
            break;
        }
    }

    delete var;    
    return VoidVariable::getInstance().clone();
}
