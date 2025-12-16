#include <filesystem>
#include <iostream>
#include "Classes/Header/Interpreter/Interpreter.h"
#include "Tests/TestTokenizer.h"

void testTokenizer() {
    Tokenizer tokenizer;

    char buffer[1024];
    std::cin.getline(buffer, 1024);
    auto v = tokenizer.tokenize(buffer);
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size()-1) {
            std::cout << ", ";
        }
    }
}

int main()
{
    /*TestTokenizer test_tokenizer;
    test_tokenizer.runTests();*/

    //testTokenizer();

    Tokenizer tokenizer;
    auto tokens = tokenizer.tokenize("f('Hi',g(8))");
    for (auto token : tokens) {
        std::cout << token << std::endl;
    }
    return 0;
}