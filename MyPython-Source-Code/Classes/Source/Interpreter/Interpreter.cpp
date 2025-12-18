#include "../../Header/Interpreter/Interpreter.h"
#include "../../Exception/InterpreterException.h"

#include <fstream>
#include <iostream>

Interpreter::Interpreter(const std::string& fileName, std::istream& is, std::ostream& os)
    : fileName(fileName), context(is, os) { }

const std::string& Interpreter::getFileName() const {
    return this->fileName;
}

void Interpreter::setFileName(const std::string& fileName) {
    this->fileName = fileName;
}

void Interpreter::interpretLineByLine(std::ifstream& inputFile)
{
    char buffer[MpySymbols::MAX_BUFFER_SIZE];
    inputFile.getline(buffer, MpySymbols::MAX_BUFFER_SIZE);
    while (true)
    {
        auto tokens = tokenizer.tokenize(buffer);
        Operation* operation = operationFactory.create(tokens);

        operation->execute(context);
        delete operation;

        if (inputFile.eof())
            break;
        inputFile.getline(buffer, MpySymbols::MAX_BUFFER_SIZE);
    }
}

void Interpreter::interpret() {
    std::ifstream inputFile(fileName.c_str(), std::ios::in);
    if (!inputFile.is_open())
    {
        throw interpreter_exception("Error: file did not open. ");
    }

    try {
        interpretLineByLine(inputFile);
    } catch (interpreter_exception& ex) {
        context.getOutputStream() << "Error: " << ex.what() << std::endl;
    }

    inputFile.close();
}

void Interpreter::printContex() const {
    std::cout << context << std::endl;
}
