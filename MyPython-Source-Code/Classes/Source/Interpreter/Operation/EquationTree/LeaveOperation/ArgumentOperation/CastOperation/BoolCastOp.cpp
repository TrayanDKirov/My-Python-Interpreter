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
    BoolVariable* result = nullptr;
    
    if (auto strVal = dynamic_cast<StringVariable*>(val)) {
        result = new BoolVariable(strVal->toBool());
    }
    else if (auto fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        result = new BoolVariable(fVal->toBool());
    }
    else if (auto bVal = dynamic_cast<BoolVariable*>(val)) {        
        result = dynamic_cast<BoolVariable*>(bVal->clone());
    }
    else if (auto iVal = dynamic_cast<IntegerNumber*>(val)) {
        result = new BoolVariable(iVal->toBool());
    }

    delete val;
    if (result)
        return result;

    throw value_error("ValueError: can not convert this type to bool");
}
