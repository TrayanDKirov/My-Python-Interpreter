#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/FloatCastOp.h"

#include "../../../../../../../Exception/VariableException.h"
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
    if (StringVariable* strVal = dynamic_cast<StringVariable*>(val)) {
        return new FloatingPointNumber(strVal->toFloat());
    }
    if (FloatingPointNumber* fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        return fVal->clone();
    }
    if (BoolVariable* bVal = dynamic_cast<BoolVariable*>(val)) {
        return new FloatingPointNumber(bVal->toFloat());
    }
    if (IntegerNumber* iVal = dynamic_cast<IntegerNumber*>(val)) {
        return new FloatingPointNumber(iVal->toFloat());
    }

    throw variable_exception("can not convert this type to float");
}