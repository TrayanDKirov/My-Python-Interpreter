#include "../../Header/Interpreter/MpySymbols.h"

using std::string;

const char MpySymbols::startBracket = '(';
const char MpySymbols::endBracket = ')';
const char MpySymbols::bigQuote = '"';
const char MpySymbols::smallQuote = '\'';
const char MpySymbols::sqStartBracket = '[';
const char MpySymbols::sqEndBracket = ']';
const char MpySymbols::whiteSpaceSep = ' ';
const char MpySymbols::commaSep = ',';

const char MpySymbols::less = '<';
const char MpySymbols::more = '>';
const char MpySymbols::plus = '+';
const char MpySymbols::minus = '-';
const char MpySymbols::mult = '*';
const char MpySymbols::div = '/';
const char MpySymbols::per = '%';
const char MpySymbols::equal = '=';
const char MpySymbols::different = '!';

const std::string MpySymbols::AND = "and";
const std::string MpySymbols::OR = "or";
const std::string MpySymbols::NOT = "not";
const std::string MpySymbols::EQUALS = "==";

const size_t MpySymbols::MAX_BUFFER_SIZE = 1024;

bool MpySymbols::isOperator(char ch)
{
    return ch == less || ch == more || ch == plus || ch == minus ||
        ch == mult || ch == div || ch == per || ch == equal || ch == different;
}

bool MpySymbols::isPowerOperator(char ch1, char ch2) {
    return ch1 == mult && ch2 == mult;
}

bool MpySymbols::isIntDelOperator(char ch1, char ch2) {
    return ch1 == div && ch2 == div;
}

bool MpySymbols::isDifferenceOperator(char ch1, char ch2) {
    return ch1 == different && ch2 == equal;
}

bool MpySymbols::isBoolOperator(const std::string &str) {
    if (str.size()==1 && (str[0] == less || str[0] == more))
        return true;
    if (str.size() == 2 && str[1] == equal &&
        (str[0] == less || str[0] == more || str[0] == equal || str[0] == different))
        return true;
    return str == AND || str == OR || str == NOT;
}

bool MpySymbols::isCommaSep(const std::string &str) {
    return str.size() == 1 && str[0] == commaSep;
}

bool MpySymbols::isStartBracket(const std::string &str) {
    return str.size() == 1 && str[0] == startBracket;
}

bool MpySymbols::isEndBracket(const std::string &str) {
    return str.size() == 1 && str[0] == endBracket;
}
string MpySymbols::toMpyString(const string& str) {
    string quote = "";
    quote.push_back(bigQuote);

    return quote + str + quote;
}
