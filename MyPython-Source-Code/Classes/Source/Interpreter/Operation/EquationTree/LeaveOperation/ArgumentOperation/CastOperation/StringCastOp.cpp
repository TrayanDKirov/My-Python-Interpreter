#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/StringCastOp.h"

#include "../../../../../../../Exception/Errors/ValueError.h"
#include "../../../../../../../Header/Variable/BoolVariable.h"
#include "../../../../../../../Header/Variable/Number/FloatingPointNumber.h"
using std::make_unique;
using std::unique_ptr;

#include "../../../../../../../Header/Variable/Iterable/StringVariable.h"
#include "../../../../../../../Header/Variable/Number/IntegerNumber.h"

const std::string StringCastOp::NAME = "str";

StringCastOp::StringCastOp(std::vector<unique_ptr<Operation>>& args) : CastOperation(args) { }

Variable* StringCastOp::execute(Context& contex)
{
    Variable* val = args[0].get()->execute(contex);
    StringVariable* result = nullptr;
    
    if (auto strVal = dynamic_cast<StringVariable*>(val)) {
        result = dynamic_cast<StringVariable*>(strVal->clone());
    }
    else if (auto fVal = dynamic_cast<FloatingPointNumber*>(val)) {
        result = new StringVariable("'" + fVal->toString() + "'");
    }
    else if (auto bVal = dynamic_cast<BoolVariable*>(val)) {
        result = new StringVariable("'" + bVal->toString() + "'");
    }
    else if (auto iVal = dynamic_cast<IntegerNumber*>(val)) {
        result = new StringVariable("'" + iVal->toString() + "'");
    }

    delete val;
    if (result)
        return result;

    throw value_error("ValueError: can not convert this type to string");
}