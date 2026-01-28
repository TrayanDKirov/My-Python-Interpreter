#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/BoolCastOp.h"

#include "../../../../../../../Exception/ValueError.h"
#include "../../../../../../../Header/Variable/BoolVariable.h"
#include "../../../../../../../Header/Variable/Number/FloatingPointNumber.h"
using std::make_unique;
using std::unique_ptr;

#include "../../../../../../../Header/Variable/Iterable/StringVariable.h"
#include "../../../../../../../Header/Variable/Number/IntegerNumber.h"

const std::string BoolCastOp::NAME = "bool";

BoolCastOp::BoolCastOp(std::vector<unique_ptr<Operation>>& args) : CastOperation(args) { }

Variable* BoolCastOp::execute(Context& contex)
{
    Variable* val = args[0].get()->execute(contex);
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

    throw value_error("ValueError: can not convert this type to bool");
}
