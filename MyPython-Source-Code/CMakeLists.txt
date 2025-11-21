cmake_minimum_required(VERSION 3.20)
project(MyPython_Source_Code)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyPython_Source_Code
        main.cpp
        Classes/Source/Interpreter/Interpreter.cpp
        Classes/Source/Interpreter/Tokenizer.cpp
        Classes/Source/Interpreter/Operation/Operation.cpp
        Classes/Source/Interpreter/Operation/OperationFactory.cpp
        Classes/Header/Interpreter/Operation/OperationFactory.h
        Classes/Execption/InterpreterException.h
)
