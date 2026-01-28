#include "../../Header/Interpreter/Tokenizer.h"

#include "../../Exception/SyntaxError.h"
#include "../../Header/Interpreter/MpySymbols.h"

using namespace std;

bool Tokenizer::isQuote(char ch) const {
    return ch == MpySymbols::smallQuote || ch == MpySymbols::bigQuote;
}

void Tokenizer::assertQuoteAtEndOfToken(const string& text, size_t index) const
{
    if (isQuote(text[index]) && index+1<text.size() && text[index+1] != sep)
    {
        throw syntax_error(("SyntaxError: quote not in end of a token - "
             + text.substr(index-1, 3)).c_str());
    }
}

void addChar(vector<string>& arr, char ch) {
    string str = "";
    str.push_back(ch);
    arr.push_back(str);
}

size_t Tokenizer::parseInBrackets(vector<string>& tokens, const string& text, size_t curr)
{
    if (text[curr] != startBracket)
        return curr;

    string currToken = "";
    addChar(tokens, startBracket);
    int bracketCounter = 1;
    for (size_t i = curr + 1; i < text.size(); i++)
    {
        char currChar = text[i];

        if (currChar == endBracket) {
            if (!currToken.empty()) {
                tokens.push_back(currToken);
                currToken.clear();
            }

            addChar(tokens, endBracket);
            return i;
        }
        if (currChar == startBracket) {
            i = parseInBrackets(tokens, text, i);
            continue;
        }

        i = tokenize(tokens, text, i,
            [](size_t i, const string& text){return i < text.size() && text[i]!=MpySymbols::commaSep
                && text[i] != MpySymbols::endBracket;});
        if (text[i] == endBracket) {
            addChar(tokens, endBracket);
            return i;
        }

        addChar(tokens, commaSep);
    }

    throw syntax_error("no end bracket");
}

size_t Tokenizer::parseQuotes(std::vector<std::string>& tokens, const std::string& text, size_t curr)
{
    char quotes = text[curr];
    if ((quotes != smallQuote && quotes != bigQuote) || curr >= text.size())
        return curr;

    string currToken = "";
    currToken.push_back(text[curr]);
    for (size_t i = curr+1; i < text.size(); i++) {
        char currChar = text[i];
        currToken.push_back(currChar);

        if (currChar == quotes)
        {
            tokens.push_back(currToken);
            return i;
        }
    }

    throw syntax_error("there must be an end quote ");
}

string Tokenizer::transformText(const string& text)
{
    string result = "";
    bool isInQuotes = false;
    char quotes;
    for (size_t i = 0; i < text.size(); i++)
    {
        if (isInQuotes || (!MpySymbols::isOperator(text[i]) && !isQuote(text[i]))) {
            if (text[i] == quotes) {
                isInQuotes = false;
            }
            result.push_back(text[i]);
            continue;
        }
        if (text[i] == smallQuote || text[i] == bigQuote) {
            result.push_back(text[i]);
            quotes = text[i];
            isInQuotes = true;
            continue;
        }
        result.push_back(sep);
        result.push_back(text[i]);

        if (i+1 < text.size() && (text[i+1] == MpySymbols::equal
            || MpySymbols::isPowerOperator(text[i], text[i+1])
            || MpySymbols::isIntDelOperator(text[i], text[i+1])
            || MpySymbols::isDifferenceOperator(text[i], text[i+1]))) {
            result.push_back(text[i+1]);
            i++;
        }

        result.push_back(sep);
    }
    return result;
}

size_t Tokenizer::tokenize(vector<string>& tokens, const string& text, size_t curr, bool(*until)(size_t, const string&))
{
    bool startNext, isInSpaces;
    isInSpaces = false;
    startNext = true;
    string currToken = "";
    size_t i = curr-1;
    while (until(i+1, text)) {
        i++;
        char currChar = text[i];
        if (currChar == sep) {
            if (!isInSpaces) {
                startNext = isInSpaces = true;
            }
            continue;
        }

        if (startNext) {
            if (currToken != "")
            {
                tokens.push_back(currToken);
                currToken.clear();
            }
            startNext = isInSpaces = false;

            if (isQuote(currChar)) {
                i = parseQuotes(tokens, text, i);
                continue;
            }
            if (currChar == startBracket) {
                i = parseInBrackets(tokens, text, i);
                continue;
            }
        }
        else if (currChar == startBracket) {
            tokens.push_back(currToken);
            currToken.clear();

            i = parseInBrackets(tokens, text, i);
            continue;
        }
        else if (isQuote(currChar))
            throw syntax_error("quote not in start of token");
        else if (currChar == endBracket)
            throw syntax_error("end bracket without start bracket");

        currToken.push_back(currChar);
    }
    if (currToken != "")
        tokens.push_back(currToken);

    return i + 1;
}

std::vector<std::string> Tokenizer::tokenize(const std::string& originalText)
{
    vector<string> tokens;
    string text = transformText(originalText);
    tokenize(tokens, text, 0,
        [](size_t i, const string& text){return i < text.size();});

    return tokens;
}
