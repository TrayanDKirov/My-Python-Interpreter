#include <iostream>
#include <sstream>
#include <string>
#include "Classes/Header/Interpreter/Interpreter.h"

struct TestCase {
    std::string fileName;
    std::string expected;
};

void runTest(const TestCase& test) {
    std::ostringstream actual;
    Interpreter interpreter(test.fileName, std::cin, actual);
    interpreter.interpret();

    std::cout << "=== " << test.fileName << " ===\n";
    std::cout << "Expected:\n" << test.expected;
    std::cout << "Actual:\n"   << actual.str();
    std::cout << (actual.str() == test.expected ? "PASS" : "FAIL") << "\n\n";
}

int main()
{
    TestCase tests[] = {
        {
            "testFile1.mpy",
            "8\n2\n15\n2\n125\n"
        },
        {
            "testFile2.mpy",
            "False\nTrue\nTrue\nFalse\nTrue\nFalse\nTrue\n"
        },
        {
            "testFile3.mpy",
            "big\nmedium\nnot positive\n"
        },
        {
            "testFile4.mpy",
            "42\n3.140000\nFalse\nTrue\n1\n"
        }
    };

    for (const auto& test : tests) {
        runTest(test);
    }

    return 0;
}
