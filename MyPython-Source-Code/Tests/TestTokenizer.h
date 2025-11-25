#pragma once
#include "../Classes/Header/Interpreter/Tokenizer.h"

class TestTokenizer {
    Tokenizer tokenizer;

    std::string makeTokensIntoStr(const std::vector<std::string>& tokens) const;
public:
    void test1();
    void test2();
    void test3();
    void test5();
    void test6();
    void test7();
    void test8();

    void runTests();
};

