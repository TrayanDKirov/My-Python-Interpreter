#include "../../../../Header/Interpreter/Operation/CastOperation/BoolCastOp.h"

#include "../../../../Exception/VariableException.h"
#include "../../../../Header/Variable/BoolVariable.h"
#include "../../../../Header/Variable/Number/FloatingPointNumber.h"
using std::make_unique;
using std::unique_ptr;

#include "../../../../Header/Variable/Iterable/StringVariable.h"
#include "../../../../Header/Variable/Number/IntegerNumber.h"

const std::string BoolCastOp::NAME = "bool";

BoolCastOp::BoolCastOp(unique_ptr<Operation> value) : value(std::move(value)) { }

Variable* BoolCastOp::execute(Context& contex)
{
    Variable* val = value.get()->execute(contex);
    if (StringVariable* strVal = dynamic_cast<StringVariable*>(val)) {
        return new BoolVariable(strVal->toBool());
    }
    if (FloatingPointNumber* fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        return new BoolVariable(fVal->toBool());
    }
    if (BoolVariable* bVal = dynamic_cast<BoolVariable*>(val)) {
        return bVal->clone();
    }
    if (IntegerNumber* iVal = dynamic_cast<IntegerNumber*>(val)) {
        return new BoolVariable(iVal->toBool());
    }

    throw variable_exception("can not convert this type to bool");
}
