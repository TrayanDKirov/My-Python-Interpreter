#include "TestTokenizer.h"
#include "../Classes/Exception/ParsingException.h"
#include <iostream>
using namespace std;



string TestTokenizer::makeTokensIntoStr(const vector<string> &tokens) const {
    string result = "";
    for (size_t i = 0; i < tokens.size(); i++) {
        result += tokens[i];
        if (i != tokens.size()-1) {
            result += ", ";
        }
    }
    return result;
}

void TestTokenizer::test1() {
    std::cout << "Test 1: ";
    std::cout << "Parsing \"x = 10\": ";
    if (makeTokensIntoStr(tokenizer.tokenize("x = 10")) == "x, =, 10") {
        std::cout << "Passed!" << std::endl;
        return;
    }
    std::cout << "Failed!" << std::endl;
}

void TestTokenizer::test2() {
    std::cout << "Test 2: ";
    std::cout << "Parsing \"x    =    10\": ";
    if (makeTokensIntoStr(tokenizer.tokenize("x    =    10")) == "x, =, 10") {
        std::cout << "Passed!" << std::endl;
        return;
    }
    std::cout << "Failed!" << std::endl;
}

void TestTokenizer::test3() {
    std::cout << "Test 3: ";
    std::cout << "Parsing \"x    =    10   \": ";
    if (makeTokensIntoStr(tokenizer.tokenize("x    =    10   ")) == "x, =, 10") {
        std::cout << "Passed!" << std::endl;
        return;
    }
    std::cout << "Failed!" << std::endl;
}

void TestTokenizer::test5() {
    std::cout << "Test 5: ";
    std::cout << "Parsing \"x    =    10    \": ";
    if (makeTokensIntoStr(tokenizer.tokenize("x    =    10")) == "x, =, 10") {
        std::cout << "Passed!" << std::endl;
        return;
    }
    std::cout << "Failed!" << std::endl;
}

void TestTokenizer::test6() {
    std::cout << "Test 6: ";
    std::cout << "Parsing \"x    =    10   'Text    with    spaces'\": ";
    if (makeTokensIntoStr(tokenizer.tokenize("x    =    10   'Text    with    spaces'")) == "x, =, 10, Text    with    spaces") {
        std::cout << "Passed!" << std::endl;
        return;
    }
    std::cout << "Failed!" << std::endl;
}

void TestTokenizer::test7() {
    std::cout << "Test 7: ";
    std::cout << "Parsing \"x    =    10   'Text with \"another quotes\"  '\": ";
    if (makeTokensIntoStr(tokenizer.tokenize("x    =    10   'Text with \"another quotes\"  '")) == "x, =, 10, Text with \"another quotes\"  ") {
        std::cout << "Passed!" << std::endl;
        return;
    }
    std::cout << "Failed!" << std::endl;
}

void TestTokenizer::test8() {
    std::cout << "Test 8: ";
    std::cout << "Parsing \"x    =    10   'text 'nosepAfterEndQuote \": ";
    try {
        tokenizer.tokenize("x    =    10   'text 'nosepAfterEndQuote ");
    } catch (parsing_exception& ex) {
        std::cout << "Passed!" << std::endl;
        return;
    }
    std::cout << "Failed!" << std::endl;
}

void TestTokenizer::test9()
{
    std:;cout << "Test 9" << std::endl;
    std::cout << makeTokensIntoStr(tokenizer.tokenize("print(stringVar, 'str', x, y)")) << std::endl;
}

void TestTokenizer::test10()
{
    std:;cout << "Test 10" << std::endl;
    std::cout << makeTokensIntoStr(tokenizer.tokenize("print   (stringVar, 'str', x, y)")) << std::endl;
}

void TestTokenizer::runTests() {
    test1();
    test2();
    test3();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
}

