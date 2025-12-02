#include "../../../../Header/Interpreter/Operation/CastOperation/BoolCastOp.h"

#include "../../../../Exception/VariableException.h"
#include "../../../../Header/Variable/BoolVariable.h"
#include "../../../../Header/Variable/Number/FloatingPointNumber.h"
using std::make_unique;
using std::unique_ptr;

#include "../../../../Header/Variable/Iterable/StringVariable.h"
#include "../../../../Header/Variable/Number/IntegerNumber.h"

const std::string BoolCastOp::NAME = "bool";

BoolCastOp::BoolCastOp(unique_ptr<Variable> value) : value(std::move(value)) { }

unique_ptr<Variable> BoolCastOp::execute(Context& contex)
{
    Variable* val = value.get();
    if (StringVariable* strVal = dynamic_cast<StringVariable*>(val)) {
        return make_unique<BoolVariable>(strVal->toBool());
    }
    if (FloatingPointNumber* fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        return make_unique<BoolVariable>(fVal->toBool());
    }
    if (BoolVariable* bVal = dynamic_cast<BoolVariable*>(val)) {
        return unique_ptr<Variable>(bVal->clone());
    }
    if (IntegerNumber* iVal = dynamic_cast<IntegerNumber*>(val)) {
        return make_unique<BoolVariable>(iVal->toBool());
    }

    throw variable_exception("can not convert this type to bool");
}
