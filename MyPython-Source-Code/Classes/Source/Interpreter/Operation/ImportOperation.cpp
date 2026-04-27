#include "../../../Header/Interpreter/Operation/ImportOperation.h"

#include "../../../Exception/Errors/Error.h"
#include "../../../Exception/Errors/FileNotFoundError.h"
#include "Interpreter/Interpreter.h"
#include "Variable/VoidVariable.h"
using std::string;

const string ImportOperation::NAME = "import";

ImportOperation::ImportOperation(const string& filePath)
    : filePath(filePath) { }

void replaceChars(string& str, char ch1, char ch2) {
    for (char& c : str) {
        if (c == ch1)
            c = ch2;
    }
}

Variable* ImportOperation::execute(Context& contex) {
    string path = filePath;
    replaceChars(path, '.', '\\');
    path = ".\\" + path + ".mpy";
    Interpreter interpreter(path,
        contex.getInputStream(), contex.getOutputStream());
    
    try {
        interpreter.interpret(contex);
    } catch (file_not_found_error& error) {
        throw file_not_found_error((error.what() + string(": ") + filePath).c_str());
    } catch (error& err) {
        throw error(("Error interpreting: " + filePath + err.what()).c_str());
    }
    
    return VoidVariable::getInstance().clone();
}
