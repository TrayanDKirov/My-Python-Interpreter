#include "../../../../Header/Interpreter/Operation/CastOperation/FloatCastOp.h"

#include "../../../../Exception/VariableException.h"
#include "../../../../Header/Variable/BoolVariable.h"
#include "../../../../Header/Variable/Number/FloatingPointNumber.h"
using std::make_unique;
using std::unique_ptr;

#include "../../../../Header/Variable/Iterable/StringVariable.h"
#include "../../../../Header/Variable/Number/IntegerNumber.h"

const std::string FloatCastOp::NAME = "float";

FloatCastOp::FloatCastOp(unique_ptr<Variable> value) : value(std::move(value)) { }

unique_ptr<Variable> FloatCastOp::execute(Context& contex)
{
    Variable* val = value.get();
    if (StringVariable* strVal = dynamic_cast<StringVariable*>(val)) {
        return make_unique<FloatingPointNumber>(strVal->toFloat());
    }
    if (FloatingPointNumber* fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        return unique_ptr<Variable>(fVal->clone());
    }
    if (BoolVariable* bVal = dynamic_cast<BoolVariable*>(val)) {
        return make_unique<FloatingPointNumber>(bVal->toFloat());
    }
    if (IntegerNumber* iVal = dynamic_cast<IntegerNumber*>(val)) {
        return make_unique<FloatingPointNumber>(iVal->toFloat());
    }

    throw variable_exception("can not convert this type to float");
}