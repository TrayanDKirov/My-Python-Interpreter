#include "../../../Header/Variable/Iterable/StringVariable.h"

#include <stdexcept>

const char StringVariable::BIG_QUOTE = '"';
const char StringVariable::SMALL_QUOTE = '\'';

bool StringVariable::isValidString(const std::string& value)
{
    return (value[0] == SMALL_QUOTE &&  value[value.size()-1] == SMALL_QUOTE) ||
        (value[0] == BIG_QUOTE && value[value.size()-1] == BIG_QUOTE);
}

StringVariable::StringVariable(const std::string& value)
{
    if (!isValidString(value)) {
        throw std::invalid_argument("not a valid string should be \"...\" or '...'");
    }

    this->value = value.substr(1, value.size()-2);
}

std::string StringVariable::toString() const
{
    return SMALL_QUOTE + value + SMALL_QUOTE;
}

Variable * StringVariable::clone() const
{
    return new StringVariable(*this);
}