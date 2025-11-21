#include <iostream>
#include "Classes/Header/Interpreter/Interpreter.h"

int main() {
    std::cout << "Enter file name: ";
    std::string fileName = "";
    std::cin >> fileName;
    Interpreter interpreter("testFile.py", std::cin, std::cout);

    std::cout << interpreter.getFileName() << std::endl;
    interpreter.interpret();

    return 0;
}