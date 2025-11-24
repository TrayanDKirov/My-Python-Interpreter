#include "../../Header/Interpreter/Interpreter.h"

#include <ostream>
#include <fstream>

#include "../../Exception/InterpreterException.h"

Interpreter::Interpreter(const std::string& fileName, std::istream& is, std::ostream& os)
    : fileName(fileName), is(is), os(os) { }

const std::string& Interpreter::getFileName() const {
    return this->fileName;
}

void Interpreter::setFileName(const std::string& fileName) {
    this->fileName = fileName;
}

const size_t MAX_BUFFER_SIZE = 1024;

void Interpreter::interpret() const {
    std::ifstream inputFile(fileName.c_str(), std::ios::in);
    if (!inputFile.is_open())
    {
        throw interpreter_exception("Error: file did not open. ");
    }

    char buffer[MAX_BUFFER_SIZE];
    inputFile.getline(buffer, MAX_BUFFER_SIZE);
    while (!inputFile.eof())
    {
        auto tokens = tokenizer.tokenize(buffer);
        Operation* operation = operationFactory.create(tokens);

        operation->execute();
        //delete operation;

        inputFile.getline(buffer, MAX_BUFFER_SIZE);
    }
}
