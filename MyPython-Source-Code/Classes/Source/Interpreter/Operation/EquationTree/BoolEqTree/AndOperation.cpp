#include "../../../../../Header/Interpreter/Operation/EquationTree/BooleanEqTree/AndOperation.h"

#include "../../../../../Exception/Errors/TypeError.h"
#include "Variable/BoolVariable.h"
using std::unique_ptr;
using std::string;

const string AndOperation::NAME = "and";

AndOperation::AndOperation(unique_ptr<BasicEqTree> left,
    unique_ptr<BasicEqTree> right) : BooleanEqTree(std::move(left), std::move(right)) { }

Variable* AndOperation::execute(Context& contex)
{
    Variable* leftVar = left->execute(contex);
    BoolVariable* boolLeft = dynamic_cast<BoolVariable*>(leftVar);
    if (!boolLeft) {
        delete leftVar;
        
        throw type_error("Left equation of and must result in a bool");
    }

    if (boolLeft->getValue() == false)
    {
        return boolLeft;
    }
    Variable* rightVar = right->execute(contex);
    BoolVariable* boolRight = dynamic_cast<BoolVariable*>(rightVar);
    if (!boolRight) {
        delete leftVar;
        delete rightVar;
        
        throw type_error("Right equation of and must result in a bool");
    }

    delete boolLeft;

    return boolRight;
}
