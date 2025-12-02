#include "../../Header/Variable/BoolVariable.h"

#include <stdexcept>
using std::string;

const string BoolVariable::TRUE_STR = "True";
const string BoolVariable::FALSE_STR = "False";

BoolVariable::BoolVariable(const string &value)
{
    if (value == TRUE_STR) {
        this->value = true;
        return;
    }
    if (value == FALSE_STR) {
        this->value = false;
        return;
    }

    throw std::invalid_argument("string value is not of type bool");
}

BoolVariable::BoolVariable(bool value) : value(value) { }

string BoolVariable::toString() const
{
    if (value)
        return TRUE_STR;
    return FALSE_STR;
}

int BoolVariable::toInt() const {
    return (int)value;
}

float BoolVariable::toFloat() const {
    return (float)value;
}

Variable * BoolVariable::clone() const
{
    return new BoolVariable(*this);
}
