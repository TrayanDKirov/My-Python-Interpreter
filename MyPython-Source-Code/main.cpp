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

int main() {
    /*std::cout << "Enter file name: ";
    std::string fileName = "";
    std::cin >> fileName;*/
    /*std::string fileName = "testFile.mpy";
    Interpreter interpreter(fileName, std::cin, std::cout);

    std::cout << interpreter.getFileName() << std::endl;
    interpreter.interpret();

    std::cout << std::endl << "Contex loaded: " << std::endl;
    interpreter.printContex();*/

    Tokenizer tokenizer;
    Context context;
    VariableFactory variable_factory(&context);
    OperationFactory operation_factory(&variable_factory);
    VariableFactory* v = &variable_factory;
    OperationFactory* o = &operation_factory;

    /*TestTokenizer testTokenizer;
    testTokenizer.runTests();*/

    /*TestArgsParser testArgsParser;
    testArgsParser.test1();*/

    return 0;
}