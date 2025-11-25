#include "../../Header/Interpreter/Tokenizer.h"
#include "../../Exception/ParsingException.h"

using namespace std;

bool Tokenizer::isQuote(char ch) const {
    return ch == smallQuote || ch == bigQuote;
}

void Tokenizer::assertQuoteAtEndOfToken(const string& text, size_t index) const {
    if (isQuote(text[index]) && index+1<text.size() && text[index+1] != sep) {
        throw parsing_exception(("Parsing error: quote not in end of a token - "
             + text.substr(index-1, 3)).c_str());
    }
}

std::vector<std::string> Tokenizer::tokenize(const std::string &text) const {
    std::vector<std::string> tokens;

    bool isInSmallQuotes, isInBigQuotes, startNext, isInSpaces;
    isInBigQuotes = isInSmallQuotes = startNext = isInSpaces = false;
    std::string currToken = "";
    for (size_t i = 0; i < text.size(); i++) {
        char currChar = text[i];
        if (!(isInBigQuotes || isInSmallQuotes) && currChar == sep) {
            if (!isInSpaces) {
                startNext = isInSpaces = true;
            }
            continue;
        }

        if (startNext) {
            tokens.push_back(currToken);
            currToken.clear();
            startNext = isInSpaces = false;

            if (currChar == smallQuote) {
                isInSmallQuotes = true;
                continue;
            }
            if (currChar == bigQuote) {
                isInBigQuotes = true;
                continue;
            }
        }

        if (!isInBigQuotes && currChar == smallQuote) {
            assertQuoteAtEndOfToken(text, i);

            isInSmallQuotes = false;
            continue;
        }
        if (!isInSmallQuotes && currChar == bigQuote) {
            assertQuoteAtEndOfToken(text, i);

            isInBigQuotes = false;
            continue;
        }

        currToken.push_back(currChar);
    }
    tokens.push_back(currToken);

    return tokens;
}
