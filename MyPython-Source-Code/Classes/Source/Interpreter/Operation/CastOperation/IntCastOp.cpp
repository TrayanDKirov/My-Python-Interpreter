#include "../../../../Header/Interpreter/Operation/CastOperation/IntCastOp.h"

#include "../../../../Exception/VariableException.h"
#include "../../../../Header/Variable/BoolVariable.h"
#include "../../../../Header/Variable/Number/FloatingPointNumber.h"
using std::make_unique;
using std::unique_ptr;

#include "../../../../Header/Variable/Iterable/StringVariable.h"
#include "../../../../Header/Variable/Number/IntegerNumber.h"

const std::string IntCastOp::NAME = "int";

IntCastOp::IntCastOp(unique_ptr<Variable> value) : value(std::move(value)) { }

unique_ptr<Variable> IntCastOp::execute(Context& contex)
{
    Variable* val = value.get();
    if (StringVariable* strVal = dynamic_cast<StringVariable*>(val)) {
        return make_unique<IntegerNumber>(strVal->toInt());
    }
    if (FloatingPointNumber* fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        return make_unique<IntegerNumber>(fVal->toInt());
    }
    if (BoolVariable* bVal = dynamic_cast<BoolVariable*>(val)) {
        return make_unique<IntegerNumber>(bVal->toInt());
    }
    if (IntegerNumber* iVal = dynamic_cast<IntegerNumber*>(val)) {
        return unique_ptr<Variable>(iVal->clone());
    }

    throw variable_exception("can not convert this type to int");
}
