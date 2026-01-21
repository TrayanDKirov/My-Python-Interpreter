#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/IntCastOp.h"

#include "../../../../../../../Exception/VariableException.h"
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
    if (StringVariable* strVal = dynamic_cast<StringVariable*>(val)) {
        return new IntegerNumber(strVal->toInt());
    }
    if (FloatingPointNumber* fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        return new IntegerNumber(fVal->toInt());
    }
    if (BoolVariable* bVal = dynamic_cast<BoolVariable*>(val)) {
        return new IntegerNumber(bVal->toInt());
    }
    if (IntegerNumber* iVal = dynamic_cast<IntegerNumber*>(val)) {
        return iVal->clone();
    }

    throw variable_exception("can not convert this type to int");
}
