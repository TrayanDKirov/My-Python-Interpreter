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

int main() {
    /*std::cout << "Enter file name: ";
    std::string fileName = "";
    std::cin >> fileName;
    Interpreter interpreter("testFile.py", std::cin, std::cout);

    std::cout << interpreter.getFileName() << std::endl;
    interpreter.interpret();*/

    TestTokenizer testTokenizer;
    testTokenizer.runTests();
    return 0;
}