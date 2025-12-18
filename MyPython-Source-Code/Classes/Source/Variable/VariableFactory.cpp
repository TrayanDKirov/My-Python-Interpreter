#include "../../Header/Variable/VariableFactory.h"
#include "../../Exception/VariableException.h"
#include "../../Header/Variable/Number/FloatingPointNumber.h"
#include "../../Header/Variable/Number/IntegerNumber.h"

#include <stdexcept>

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
        throw variable_exception("value is of type int but is out of range. ");
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
        throw variable_exception("value is of type float but is out of range. ");
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
        return new NoneVariable();
    }

    return new VoidVariable();
}

Variable* VariableFactory::createByName(const std::string &value, Context &context) const {
    return context.getScope().get(value)->clone();
}

VariableFactory & VariableFactory::getInstance() {
    static VariableFactory variableFactory;

    return variableFactory;
}
