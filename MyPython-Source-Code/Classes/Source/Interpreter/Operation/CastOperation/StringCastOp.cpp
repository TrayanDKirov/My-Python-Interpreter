#include "../../../../Header/Interpreter/Operation/CastOperation/StringCastOp.h"

#include "../../../../Exception/VariableException.h"
#include "../../../../Header/Variable/BoolVariable.h"
#include "../../../../Header/Variable/Number/FloatingPointNumber.h"
using std::make_unique;
using std::unique_ptr;

#include "../../../../Header/Variable/Iterable/StringVariable.h"
#include "../../../../Header/Variable/Number/IntegerNumber.h"

const std::string StringCastOp::NAME = "str";

StringCastOp::StringCastOp(unique_ptr<Variable> value) : value(std::move(value)) { }

unique_ptr<Variable> StringCastOp::execute(Context& contex)
{
    Variable* val = value.get();
    if (StringVariable* strVal = dynamic_cast<StringVariable*>(val)) {
        return unique_ptr<Variable>(strVal->clone());
    }
    if (FloatingPointNumber* fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        return make_unique<StringVariable>(fVal->toString());
    }
    if (BoolVariable* bVal = dynamic_cast<BoolVariable*>(val)) {
        return make_unique<StringVariable>(bVal->toString());
    }
    if (IntegerNumber* iVal = dynamic_cast<IntegerNumber*>(val)) {
        return make_unique<StringVariable>(iVal->toString());
    }

    throw variable_exception("can not convert this type to string");
}