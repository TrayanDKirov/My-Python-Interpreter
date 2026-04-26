#include "Interpreter/Operation/EquationTree/BooleanEqTree/BiggerOrEqualOperation.h"

#include "../../../../../Exception/Errors/TypeError.h"
#include "Variable/BoolVariable.h"
#include "Variable/NoneVariable.h"
#include "Variable/Number/FloatingPointNumber.h"
#include "Variable/Number/IntegerNumber.h"
using std::unique_ptr;
using std::string;

const string BiggerOrEqualOperation::NAME = ">=";

BoolVariable* BiggerOrEqualOperation::compareInt(Variable* leftVar, Variable* rightVar)
{
    IntegerNumber* leftInt = dynamic_cast<IntegerNumber*>(leftVar);
    if (!leftInt)
        return nullptr;
    IntegerNumber* rightInt = dynamic_cast<IntegerNumber*>(rightVar);
    if (!rightInt)
        return nullptr;

    BoolVariable* result = new BoolVariable(*leftInt >= *rightInt);

    return result;
}

BoolVariable * BiggerOrEqualOperation::compareFloat(Variable* leftVar, Variable* rightVar)
{
    FloatingPointNumber* leftFloat = dynamic_cast<FloatingPointNumber*>(leftVar);
    if (!leftFloat)
        return nullptr;
    FloatingPointNumber* rightFloat = dynamic_cast<FloatingPointNumber*>(rightVar);
    if (!rightFloat)
        return nullptr;

    BoolVariable* result = new BoolVariable(*leftFloat >= *rightFloat);

    return result;
}

BiggerOrEqualOperation::BiggerOrEqualOperation(unique_ptr<BasicEqTree> left,
                               unique_ptr<BasicEqTree> right) : BooleanEqTree(std::move(left), std::move(right)) { }

Variable* BiggerOrEqualOperation::execute(Context& contex)
{
    Variable* leftVar = left->execute(contex);
    Variable* rightVar = right->execute(contex);

    BoolVariable* result = nullptr;
    result = compareInt(leftVar, rightVar);
    if (!result)
        result = compareFloat(leftVar, rightVar);

    delete leftVar;
    delete rightVar;

    if (!result)
        throw type_error("Left and right side of >= must be the same type. ");
    return result;
}
