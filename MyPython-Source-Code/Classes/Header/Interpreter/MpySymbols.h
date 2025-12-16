#pragma once
#include <unordered_set>

class MpySymbols {
public:
    static const char startBracket;
    static const char endBracket;
    static const char whiteSpaceSep;
    static const char commaSep;
    static const char sqStartBracket;
    static const char sqEndBracket;
    static const char smallQuote;
    static const char bigQuote;

    static const char less;
    static const char more;
    static const char plus;
    static const char minus;
    static const char mult;
    static const char div;
    static const char per;
    static const char equal;
    static const char different;

    static bool isOperator(char ch);
    static bool isPowerOperator(char ch1, char ch2);
    static bool isIntDelOperator(char ch1, char ch2);
    static bool isDifferenceOperator(char ch1, char ch2);
};
