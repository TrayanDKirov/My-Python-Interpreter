#pragma once
#include "Tokenizer.h"
#include "Operation/OperationFactory.h"

#include <string>

class Interpreter {
    std::string fileName = "";
    Contex contex;

    Tokenizer tokenizer;
    OperationFactory operationFactory;

public:
    Interpreter(const std::string& fileName, std::istream& is, std::ostream& os);

    const std::string& getFileName() const;
    void setFileName(const std::string& fileName);

    void interpret();

    void printContex() const;
};
