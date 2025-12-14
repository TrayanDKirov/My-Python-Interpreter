#include "../../Header/Variable/VariableFactory.h"
#include "../../Exception/VariableException.h"
#include "../../Header/Variable/Number/FloatingPointNumber.h"
#include "../../Header/Variable/Number/IntegerNumber.h"

#include <stdexcept>

#include "../../Header/Variable/BoolVariable.h"
#include "../../Header/Variable/Iterable/StringVariable.h"
using std::unique_ptr;
using std::make_unique;
using std::string;

VariableFactory::VariableFactory(const Context* context) : context(context) { }

Variable* VariableFactory::create(const string& value) const {
    try {
        size_t pos = 0;
        int i = std::stoi(value, &pos);
        if (pos == value.size()) {
            return new IntegerNumber(i);
        }
    } catch (const std::invalid_argument&) {
    } catch (const std::out_of_range&) {
        throw variable_exception("value is of type int but is out of range. ");
    }

    try {
        std::size_t pos = 0;
        float f = std::stof(value, &pos);
        if (pos == value.size()) {
            return new FloatingPointNumber(f);
        }
    } catch (const std::invalid_argument&) {
    } catch (const std::out_of_range&) {
        throw variable_exception("value is of type float but is out of range. ");
    }
    try {
        return new BoolVariable(value);
    } catch (const std::invalid_argument&) { }
    try {
        return new StringVariable(value);
    } catch (const std::invalid_argument&) { }

    return context->getScope().get(value)->clone();
}
