#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/FloatCastOp.h"

#include "../../../../../../../Exception/Errors/ValueError.h"
#include "../../../../../../../Header/Variable/BoolVariable.h"
#include "../../../../../../../Header/Variable/Number/FloatingPointNumber.h"
using std::make_unique;
using std::unique_ptr;

#include "../../../../../../../Header/Variable/Iterable/StringVariable.h"
#include "../../../../../../../Header/Variable/Number/IntegerNumber.h"

const std::string FloatCastOp::NAME = "float";

FloatCastOp::FloatCastOp(std::vector<unique_ptr<Operation>>& args) : CastOperation(args) { }

Variable* FloatCastOp::execute(Context& contex)
{
    Variable* val = args[0].get()->execute(contex);
    FloatingPointNumber* result = nullptr;
    
    if (auto strVal = dynamic_cast<StringVariable*>(val)) {
        result = new FloatingPointNumber(strVal->toFloat());
    }
    else if (auto fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        result = dynamic_cast<FloatingPointNumber*>(fVal->clone());
    }
    else if (auto bVal = dynamic_cast<BoolVariable*>(val)) {
        result = new FloatingPointNumber(bVal->toFloat());
    }
    else if (auto iVal = dynamic_cast<IntegerNumber*>(val)) {
        result = new FloatingPointNumber(iVal->toFloat());
    }

    delete val;
    if (result)
        return result;

    throw value_error("ValueError: can not convert this type to float");
}