#pragma once
#include <string>
#include <unordered_set>

class MpySymbols {
public:
    static const char comment;

    static const char startBracket;
    static const char endBracket;
    static const char whiteSpaceSep;
    static const char commaSep;
    static const char sqStartBracket;
    static const char sqEndBracket;
    static const char smallQuote;
    static const char bigQuote;

    static const char plus;
    static const char minus;
    static const char mult;
    static const char div;
    static const char per;

    static const char less;
    static const char more;
    static const char equal;
    static const char different;
    static const std::string AND;
    static const std::string OR;
    static const std::string NOT;
    static const std::string EQUALS;

    static const size_t MAX_BUFFER_SIZE;

    static bool isOperator(char ch);
    static bool isPowerOperator(char ch1, char ch2);
    static bool isIntDelOperator(char ch1, char ch2);
    static bool isDifferenceOperator(char ch1, char ch2);

    static bool isBoolOperator(const std::string& str);

    static bool isCommaSep(const std::string& str);
    static bool isStartBracket(const std::string& str);
    static bool isEndBracket(const std::string& str);

    static std::string toMpyString(const std::string& str);
};
