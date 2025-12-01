#include "../../Header/Variable/Bool.h"

#include <stdexcept>


const string Bool::TRUE_STR = "True";
const string Bool::FALSE_STR = "False";

Bool::Bool(const string &value)
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

Bool::Bool(bool value) : value(value) { }

string Bool::toString() const
{
    if (value)
        return TRUE_STR;
    return FALSE_STR;
}

Variable * Bool::clone() const
{
    return new Bool(*this);
}