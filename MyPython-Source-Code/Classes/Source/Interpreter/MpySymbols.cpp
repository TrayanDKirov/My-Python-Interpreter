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
