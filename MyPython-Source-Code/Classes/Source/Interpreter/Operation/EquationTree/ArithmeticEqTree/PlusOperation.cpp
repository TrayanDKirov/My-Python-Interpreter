#include "Interpreter/Operation/EquationTree/ArithmeticEqTree/PlusOperation.h"

#include "../../../../../Exception/Errors/TypeError.h"
#include "Variable/BoolVariable.h"
#include "Variable/Number/FloatingPointNumber.h"
#include "Variable/Number/IntegerNumber.h"
using std::unique_ptr;
using std::string;

const string PlusOperation::NAME = "+";

Number* PlusOperation::plusInt(Variable* leftVar, Variable* rightVar)
{
    IntegerNumber* leftInt = dynamic_cast<IntegerNumber*>(leftVar);
    if (!leftInt)
        return nullptr;
    IntegerNumber* rightInt = dynamic_cast<IntegerNumber*>(rightVar);
    if (!rightInt)
        return nullptr;

    IntegerNumber* result = new IntegerNumber(*leftInt + *rightInt);

    return result;
}

Number* PlusOperation::plusFloat(Variable* leftVar, Variable* rightVar)
{
    FloatingPointNumber* leftFloat = dynamic_cast<FloatingPointNumber*>(leftVar);
    if (!leftFloat)
        return nullptr;
    FloatingPointNumber* rightFloat = dynamic_cast<FloatingPointNumber*>(rightVar);
    if (!rightFloat)
        return nullptr;

    FloatingPointNumber* result = new FloatingPointNumber(*leftFloat + *rightFloat);

    return result;
}

PlusOperation::PlusOperation(unique_ptr<BasicEqTree> left,
                             unique_ptr<BasicEqTree> right) : ArithmeticEqTree(std::move(left), std::move(right)) { }

Variable* PlusOperation::execute(Context& contex)
{
    Variable* leftVar = left->execute(contex);
    Variable* rightVar = right->execute(contex);

    Number* result = nullptr;
    result = plusInt(leftVar, rightVar);
    if (!result)
        result = plusFloat(leftVar, rightVar);

    delete leftVar;
    delete rightVar;

    if (!result)
        throw type_error("Left and right side of + must be the same type. ");
    return result;
}