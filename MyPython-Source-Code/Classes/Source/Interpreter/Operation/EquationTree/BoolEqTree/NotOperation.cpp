#include "Interpreter/Operation/EquationTree/BooleanEqTree/NotOperation.h"

#include "../../../../../Exception/Errors/TypeError.h"
#include "Variable/BoolVariable.h"
using std::unique_ptr;
using std::string;

const string NotOperation::NAME = "not";

NotOperation::NotOperation(unique_ptr<BasicEqTree> left,
    unique_ptr<BasicEqTree> right) : BooleanEqTree(std::move(left), std::move(right)) {  }

Variable* NotOperation::execute(Context &contex)
{
    Variable* rightVar = right->execute(contex);
    BoolVariable* boolRight = dynamic_cast<BoolVariable*>(rightVar);
    if (!boolRight) {
        delete rightVar;
        
        throw type_error("Right equation of not must result in a bool");
    }

    BoolVariable* result = new BoolVariable(!boolRight->getValue());
    delete boolRight;

    return result;
}