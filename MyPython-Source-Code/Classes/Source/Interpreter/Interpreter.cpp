#include "../../Header/Interpreter/Interpreter.h"

#include <fstream>
#include <iostream>

#include "../../Exception/Error.h"
#include "../../Exception/FileNotFoundError.h"

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
    size_t lineNumber = 0;
    try {
        while (true)
        {
            lineNumber++;
            if (buffer[0] != MpySymbols::comment && std::string(buffer) != std::string("")) {
                auto tokens = tokenizer.tokenize(buffer);
                Operation* operation = operationFactory.create(tokens);

                operation->execute(context);
                delete operation;
            }

            if (inputFile.eof())
                break;
            inputFile.getline(buffer, MpySymbols::MAX_BUFFER_SIZE);
        }
    } catch (error& error) {
        context.getOutputStream() << "Line " << lineNumber << error.what() << std::endl;
    }
}

void Interpreter::interpret() {
    std::ifstream inputFile(fileName.c_str(), std::ios::in);
    if (!inputFile.is_open())
    {
        throw file_not_found_error(("mypython: FileNotFoundError: file  " + fileName +  "  did not open. ").c_str());
    }

    interpretLineByLine(inputFile);

    inputFile.close();
}

void Interpreter::printContex() const {
    std::cout << context << std::endl;
}
