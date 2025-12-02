#include "../../Header/Interpreter/Interpreter.h"
#include "../../Exception/InterpreterException.h"

#include <fstream>
#include <iostream>

Interpreter::Interpreter(const std::string& fileName, std::istream& is, std::ostream& os)
    : fileName(fileName), context(is, os),
    variableFactory(&context), operationFactory(&variableFactory) { }

const std::string& Interpreter::getFileName() const {
    return this->fileName;
}

void Interpreter::setFileName(const std::string& fileName) {
    this->fileName = fileName;
}

const size_t MAX_BUFFER_SIZE = 1024;

void Interpreter::interpret() {
    std::ifstream inputFile(fileName.c_str(), std::ios::in);
    if (!inputFile.is_open())
    {
        throw interpreter_exception("Error: file did not open. ");
    }

    char buffer[MAX_BUFFER_SIZE];
    inputFile.getline(buffer, MAX_BUFFER_SIZE);
    while (true)
    {
        auto tokens = tokenizer.tokenize(buffer);
        Operation* operation = operationFactory.create(tokens);

        operation->execute(context);
        delete operation;

        if (inputFile.eof())
            break;
        inputFile.getline(buffer, MAX_BUFFER_SIZE);
    }

    inputFile.close();
}

void Interpreter::printContex() const {
    std::cout << context << std::endl;
}
