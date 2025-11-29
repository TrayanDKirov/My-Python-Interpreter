#pragma once
#include <string>
#include <vector>

class Tokenizer {
    char sep = ' ';
    char bigQuote = '"';
    char smallQuote = '\'';
    char beginBracket = '(';
    char endBracket = ')';

    bool isQuote(char ch) const;
    void assertQuoteAtEndOfToken(const std::string& text, size_t index) const;

public:
    std::vector<std::string> tokenize(const std::string& text) const;
};
