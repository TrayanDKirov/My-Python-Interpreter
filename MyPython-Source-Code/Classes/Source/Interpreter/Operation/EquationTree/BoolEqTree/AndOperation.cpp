#include "../../../../../Header/Interpreter/Operation/EquationTree/BooleanEqTree/AndOperation.h"

#include "../../../../../Exception/TypeError.h"
#include "../../../../../Header/Variable/BoolVariable.h"
using std::unique_ptr;
using std::string;

const string AndOperation::NAME = "and";

AndOperation::AndOperation(unique_ptr<BasicEqTree> left,
    unique_ptr<BasicEqTree> right) : BooleanEqTree(std::move(left), std::move(right)) { }

Variable* AndOperation::execute(Context& contex)
{
    Variable* leftVar = left->execute(contex);
    Variable* rightVar = right->execute(contex);
    BoolVariable* boolLeft = dynamic_cast<BoolVariable*>(leftVar);
    if (!boolLeft)
        throw type_error("Left equation of and must result in a bool");
    BoolVariable* boolRight = dynamic_cast<BoolVariable*>(rightVar);
    if (!boolRight)
        throw type_error("Right equation of and must result in a bool");

    BoolVariable* result = new BoolVariable(boolLeft->getValue() && boolRight->getValue());
    delete boolLeft;
    delete boolRight;

    return result;
}
