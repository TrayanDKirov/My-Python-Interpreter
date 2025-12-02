#include "../../Header/Interpreter/Tokenizer.h"
#include "../../Exception/ParsingException.h"

using namespace std;

bool Tokenizer::isQuote(char ch) const {
    return ch == smallQuote || ch == bigQuote;
}

void Tokenizer::assertQuoteAtEndOfToken(const string& text, size_t index) const {
    if (isQuote(text[index]) && index+1<text.size() && text[index+1] != sep)
    {
        throw parsing_exception(("Parsing error: quote not in end of a token - "
             + text.substr(index-1, 3)).c_str());
    }
}

std::vector<std::string> Tokenizer::tokenize(const std::string &text) const {
    std::vector<std::string> tokens;

    bool isInSmallQuotes, isInBigQuotes, startNext, isInSpaces, shouldSkipSep, isInBrackets;
    isInBigQuotes = isInSmallQuotes = isInSpaces = shouldSkipSep = isInBrackets = false;
    startNext = true;
    std::string currToken = "";
    for (size_t i = 0; i < text.size(); i++) {
        char currChar = text[i];
        if (!shouldSkipSep && currChar == sep) {
            if (!isInSpaces) {
                startNext = isInSpaces = true;
            }
            continue;
        }

        if (startNext) {
            if (i != 0)
            {
                tokens.push_back(currToken);
                currToken.clear();
            }
            startNext = isInSpaces = false;

            if (currChar == smallQuote) {
                isInSmallQuotes = shouldSkipSep = true;
            }
            else if (currChar == bigQuote) {
                isInBigQuotes = shouldSkipSep = true;
            }
        }
        else if (!isInBigQuotes && !isInBrackets && currChar == smallQuote) {
            assertQuoteAtEndOfToken(text, i);

            isInSmallQuotes = shouldSkipSep = false;
        }
        else if (!isInSmallQuotes && !isInBrackets && currChar == bigQuote) {
            assertQuoteAtEndOfToken(text, i);

            isInBigQuotes = shouldSkipSep = false;
        }
        if (!(isInBigQuotes || isInSmallQuotes) && currChar == beginBracket) {
            shouldSkipSep = isInBrackets = true;
        }
        else if (!(isInBigQuotes || isInSmallQuotes) && currChar == endBracket) {
            shouldSkipSep = isInBrackets = false;
        }

        currToken.push_back(currChar);
    }
    tokens.push_back(currToken);

    return tokens;
}
