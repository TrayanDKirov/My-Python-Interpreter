#pragma once
#include <string>
#include <vector>

#include "MpySymbols.h"

class Tokenizer
{
    char sep = MpySymbols::whiteSpaceSep;
    char commaSep = MpySymbols::commaSep;
    char bigQuote = MpySymbols::bigQuote;
    char smallQuote = MpySymbols::smallQuote;
    char startBracket = MpySymbols::startBracket;
    char endBracket = MpySymbols::endBracket;
    char sqStartBracket = MpySymbols::sqStartBracket;
    char sqEndBracket = MpySymbols::sqEndBracket;

    bool isInSmallQuotes = false;
    bool isInBigQuotes = false;

    bool isQuote(char ch) const;
    void assertQuoteAtEndOfToken(const std::string& text, size_t index) const;

    size_t parseInBrackets(std::vector<std::string>& tokens, const std::string& text, size_t currIndex);
    size_t parseQuotes(std::vector<std::string>& tokens, const std::string& text, size_t currIndex);

    std::string transformText(const std::string& text);

    size_t tokenize(std::vector<std::string>& tokens, const std::string& text, int curr,
        bool (*until)(size_t,const std::string&));

public:

    std::vector<std::string> tokenize(const std::string& text);
};
