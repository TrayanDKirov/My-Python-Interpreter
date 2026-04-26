#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/IntCastOp.h"

#include "../../../../../../../Exception/Errors/ValueError.h"
#include "../../../../../../../Header/Variable/BoolVariable.h"
#include "../../../../../../../Header/Variable/Number/FloatingPointNumber.h"
using std::make_unique;
using std::unique_ptr;

#include "../../../../../../../Header/Variable/Iterable/StringVariable.h"
#include "../../../../../../../Header/Variable/Number/IntegerNumber.h"

const std::string IntCastOp::NAME = "int";

IntCastOp::IntCastOp(std::vector<unique_ptr<Operation>>& args) : CastOperation(args) { }

Variable* IntCastOp::execute(Context& contex)
{
    Variable* val = args[0].get()->execute(contex);
    IntegerNumber* result = nullptr;
    
    if (auto strVal = dynamic_cast<StringVariable*>(val)) {
        result = new IntegerNumber(strVal->toInt());
    }
    else if (auto fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        result = new IntegerNumber(fVal->toInt());
    }
    else if (auto bVal = dynamic_cast<BoolVariable*>(val)) {
        result = new IntegerNumber(bVal->toInt());
    }
    else if (auto iVal = dynamic_cast<IntegerNumber*>(val)) {
        result = dynamic_cast<IntegerNumber*>(iVal->clone());
    }

    delete val;
    if (result)
        return result;

    throw value_error("ValueError: can not convert this type to int");
}
