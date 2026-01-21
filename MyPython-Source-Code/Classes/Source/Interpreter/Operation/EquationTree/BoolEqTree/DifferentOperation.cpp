#include "Interpreter/Operation/EquationTree/BooleanEqTree/DifferentOperation.h"

#include "../Exception/TypeError.h"
#include "Variable/BoolVariable.h"
#include "Variable/NoneVariable.h"
#include "Variable/Iterable/StringVariable.h"
#include "Variable/Number/FloatingPointNumber.h"
#include "Variable/Number/IntegerNumber.h"
using std::unique_ptr;
using std::string;

const string DifferentOperation::NAME = "!=";

BoolVariable* DifferentOperation::compareInt(Variable* leftVar, Variable* rightVar)
{
    IntegerNumber* leftInt = dynamic_cast<IntegerNumber*>(leftVar);
    if (!leftInt)
        return nullptr;
    IntegerNumber* rightInt = dynamic_cast<IntegerNumber*>(rightVar);
    if (!rightInt)
        return nullptr;

    BoolVariable* result = new BoolVariable(!(leftInt->getValue() == rightInt->getValue()));

    return result;
}

BoolVariable * DifferentOperation::compareFloat(Variable *leftVar, Variable *rightVar)
{

    FloatingPointNumber* leftFloat = dynamic_cast<FloatingPointNumber*>(leftVar);
    if (!leftFloat)
        return nullptr;
    FloatingPointNumber* rightFloat = dynamic_cast<FloatingPointNumber*>(rightVar);
    if (!rightFloat)
        return nullptr;

    BoolVariable* result = new BoolVariable(!(*leftFloat == *rightFloat));

    return result;
}

BoolVariable * DifferentOperation::compareBool(Variable *leftVar, Variable *rightVar)
{
    BoolVariable* leftBool = dynamic_cast<BoolVariable*>(leftVar);
    if (!leftBool)
        return nullptr;
    BoolVariable* rightBool = dynamic_cast<BoolVariable*>(rightVar);
    if (!rightBool)
        return nullptr;

    BoolVariable* result = new BoolVariable(!(*leftBool == *rightBool));

    return result;
}

BoolVariable * DifferentOperation::compareNone(Variable *leftVar, Variable *rightVar)
{
    NoneVariable* leftNone = dynamic_cast<NoneVariable*>(leftVar);
    if (!leftNone)
        return nullptr;
    NoneVariable* rightNone = dynamic_cast<NoneVariable*>(rightVar);
    if (!rightNone)
        return nullptr;

    BoolVariable* result = new BoolVariable(false);

    return result;
}

BoolVariable* DifferentOperation::compareString(Variable* leftVar, Variable* rightVar)
{
    StringVariable* leftStr = dynamic_cast<StringVariable*>(leftVar);
    if (!leftStr)
        return nullptr;
    StringVariable* rightStr = dynamic_cast<StringVariable*>(rightVar);
    if (!rightStr)
        return nullptr;

    BoolVariable* result = new BoolVariable(!(*leftStr == *rightStr));

    return result;
}

DifferentOperation::DifferentOperation(unique_ptr<BasicEqTree> left,
    unique_ptr<BasicEqTree> right) : BooleanEqTree(std::move(left), std::move(right)) { }

Variable* DifferentOperation::execute(Context& contex)
{
    Variable* leftVar = left->execute(contex);
    Variable* rightVar = right->execute(contex);

    BoolVariable* result = nullptr;
    result = compareInt(leftVar, rightVar);
    if (!result)
        result = compareBool(leftVar, rightVar);
    if (!result)
        result = compareString(leftVar, rightVar);
    if (!result)
        result = compareFloat(leftVar, rightVar);

    delete leftVar;
    delete rightVar;

    if (!result)
        throw type_error("Left and right side of != must be the same type. ");
    return result;
}