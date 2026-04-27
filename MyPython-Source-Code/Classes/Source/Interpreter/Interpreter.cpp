#include "../../Header/Interpreter/Interpreter.h"

#include <fstream>
#include <iostream>

#include "../../Exception/Errors/Error.h"
#include "../../Exception/Errors/FileNotFoundError.h"
#include "../../Exception/InterpreterCalls/Call.h"
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
    Operation* operation = nullptr;
    try {
        while (currLineIndex < lines.size())
        {
            operation = operationFactory.create(currLineIndex);
            if (operation)
                delete operation->execute(context);

            delete operation;
            operation = nullptr;
        }
    } catch (error& error) {
        delete operation;
        
        context.getOutputStream() << "Line " << currLineIndex+1 << ": " << error.what() << std::endl;
    } catch (call& call) {
        delete operation;
        
        context.getOutputStream() << "Line " << currLineIndex+1 <<
            ": SyntaxError: " <<  call.what() << std::endl;
    } catch (...) {
        delete operation;
        throw;
    }
}

void Interpreter::interpret(Context& context) {
    readFile();

    size_t currLineIndex = 0;
    Operation* operation = nullptr;
    try {
        while (currLineIndex < lines.size())
        {
            operation = operationFactory.create(currLineIndex);
            if (operation)
                delete operation->execute(context);

            delete operation;
            operation = nullptr;
        }
    } catch(...) {
        delete operation;
        throw;
    }
}

void Interpreter::printContex() const
{
    std::cout << context << std::endl;
}
