#include "../../Header/Variable/VariableFactory.h"
#include "../../Header/Variable/Number/FloatingPointNumber.h"
#include "../../Header/Variable/Number/IntegerNumber.h"

#include <stdexcept>

#include "../../Exception/ValueError.h"
#include "../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/BoolCastOp.h"
#include "../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/FloatCastOp.h"
#include "../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/IntCastOp.h"
#include "../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/StringCastOp.h"
#include "../../Header/Variable/BoolVariable.h"
#include "../../Header/Variable/NoneVariable.h"
#include "../../Header/Variable/VoidVariable.h"
#include "../../Header/Variable/Iterable/StringVariable.h"
using std::unique_ptr;
using std::make_unique;
using std::string;

Variable* createInt(const string& value)
{
    try {
        size_t pos = 0;
        int i = std::stoi(value, &pos);
        if (pos == value.size()) {
            return new IntegerNumber(i);
        }
    } catch (const std::invalid_argument&) {
    } catch (const std::out_of_range&) {
        throw value_error("ValueError: value is of type int but is out of range. ");
    } catch (...) { }

    return nullptr;
}

Variable* createFloat(const string& value)
{
    try {
        std::size_t pos = 0;
        float f = std::stof(value, &pos);
        if (pos == value.size()) {
            return new FloatingPointNumber(f);
        }
    } catch (const std::invalid_argument&) {
    } catch (const std::out_of_range&) {
        throw value_error("ValueError: value is of type float but is out of range. ");
    } catch (...) { }

    return nullptr;
}

Variable* createString(const string& value)
{
    try {
        return new StringVariable(value);
    } catch (const std::invalid_argument&) {
    } catch (...) { }

    return nullptr;
}

Variable* createBool(const string& value) {
    try {
        return new BoolVariable(value);
    } catch (const std::invalid_argument&) {
    } catch (...) { }

    return nullptr;
}

Variable* VariableFactory::create(const string& value) const {
    Variable* result;
    result = createInt(value);
    if (result)
        return result;

    result = createFloat(value);
    if (result)
        return result;

    result = createString(value);
    if (result)
        return result;

    result = createBool(value);
    if (result)
        return result;

    if (value == NoneVariable::NAME) {
        return NoneVariable::getInstance().clone();
    }

    return VoidVariable::getInstance().clone();
}

Variable* VariableFactory::createByName(const std::string& name, Context& context) const
{
    return context.getScope().get(name)->clone();
}

std::string VariableFactory::getTypeOfVariable(Variable* variable)
{
    if (BoolVariable* bVar = dynamic_cast<BoolVariable*>(variable))
        return BoolCastOp::NAME;
    if (IntegerNumber* ilVar = dynamic_cast<IntegerNumber*>(variable))
        return IntCastOp::NAME;
    if (FloatingPointNumber* fVar = dynamic_cast<FloatingPointNumber*>(variable))
        return FloatCastOp::NAME;
    if (StringVariable* sVar = dynamic_cast<StringVariable*>(variable))
        return StringCastOp::NAME;
    if (NoneVariable* nVar = dynamic_cast<NoneVariable*>(variable))
        return NoneVariable::NAME;

    return "void";
}

VariableFactory & VariableFactory::getInstance()
{
    static VariableFactory variableFactory;

    return variableFactory;
}
