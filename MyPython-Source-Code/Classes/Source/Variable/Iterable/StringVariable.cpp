#include "../../../Header/Variable/Iterable/StringVariable.h"

#include <memory>
#include <stdexcept>

#include "../../../Exception/Errors/IndexError.h"
#include "../../../Exception/Errors/ValueError.h"
#include "../../../Header/Variable/BoolVariable.h"
using std::string;

const char StringVariable::BIG_QUOTE = '"';
const char StringVariable::SMALL_QUOTE = '\'';

bool StringVariable::isValidString(const std::string& value)
{
    return value.size() > 1 && ((value[0] == SMALL_QUOTE &&  value[value.size()-1] == SMALL_QUOTE) ||
        (value[0] == BIG_QUOTE && value[value.size()-1] == BIG_QUOTE));
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
    return value;
}

int StringVariable::toInt() const {
    if (value == "")
        throw value_error("empty string can not be cast to int");
    try {
        size_t pos = 0;
        int i = std::stoi(value, &pos);
        if (pos == value.size()) {
            return i;
        }
    } catch (const std::invalid_argument&) {
    } catch (const std::out_of_range&) {
        throw value_error("string is of type int but is out of range");
    }
    throw value_error("string is not of type int");
}

float StringVariable::toFloat() const {
    if (value == "")
        throw value_error("empty string can not be cast to float");
    try {
        std::size_t pos = 0;
        float f = std::stof(value, &pos);
        if (pos == value.size()) {
            return f;
        }
    } catch (const std::invalid_argument&) {
    } catch (const std::out_of_range&) {
        throw value_error("string is of type float but is out of range. ");
    }
    throw value_error("string is not of type float");
}

bool StringVariable::toBool() const {
    if (value == "")
        return false;
    return true;
}

std::string StringVariable::getValue() const {
    return this->value;
}

void StringVariable::setValue(const std::string& value) {
    this->value = value;
}

Variable* StringVariable::operator[](int index) const {
    if (index < 0 || index >= value.size()) {
        throw index_error("index is out of range");
    }

    string str = "";
    str += value[index];

    return new StringVariable("\"" + str + "\"");
}

char& StringVariable::operator[](int index) {
    if (index < 0 || index >= value.size()) {
        throw index_error("index is out of range");
    }

    return value[index];
}

size_t StringVariable::size() const {
    return this->value.size();
}

Variable* StringVariable::clone() const
{
    return new StringVariable(*this);
}

StringVariable operator+(const StringVariable &left, const StringVariable &right) {
    return StringVariable("'" + left.getValue() + right.getValue() + "'");
}

bool operator==(const StringVariable& left, const StringVariable& right)
{
    return left.value == right.value;
}
