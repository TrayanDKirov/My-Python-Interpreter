#include "../../Header/Interpreter/Interpreter.h"

#include <fstream>
#include <iostream>

#include "../../Exception/Error.h"
#include "../../Exception/FileNotFoundError.h"
using std::ifstream;
using std::string;

Interpreter::Interpreter(const std::string& fileName, std::istream& is, std::ostream& os)
    : fileName(fileName), context(is, os), operationFactory(lines) { }

const std::string& Interpreter::getFileName() const {
    return this->fileName;
}

void Interpreter::setFileName(const std::string& fileName) {
    this->fileName = fileName;
}

void Interpreter::readLines(ifstream& inputFile) {
    string line = "";

    while (!inputFile.eof())
    {
        std::getline(inputFile, line);
        lines.push_back(line);
    }
}

void Interpreter::readFile() {
    std::ifstream inputFile(fileName.c_str(), std::ios::in);
    if (!inputFile.is_open())
    {
        throw file_not_found_error(("mypython: FileNotFoundError: file  " + fileName +  "  did not open. ").c_str());
    }

    readLines(inputFile);

    inputFile.close();
}

void Interpreter::interpret()
{
    readFile();

    size_t currLineIndex = 0;
    try {
        while (currLineIndex < lines.size())
        {
            Operation* operation = operationFactory.create(currLineIndex);
            operation->execute(context);

            delete operation;
        }
    } catch (error& error) {
        context.getOutputStream() << "Line " << currLineIndex+1 << ": " << error.what() << std::endl;
    }
}

void Interpreter::printContex() const
{
    std::cout << context << std::endl;
}
