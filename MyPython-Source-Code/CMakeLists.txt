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
        Classes/Exception/InterpreterException.h
        Classes/Source/Interpreter/Operation/Assignment.cpp
        Classes/Header/Interpreter/Operation/Assignment.h
        Classes/Exception/ParsingException.h
        Tests/TestTokenizer.cpp
        Tests/TestTokenizer.h
        Classes/Source/Variable/Variable.cpp
        Classes/Header/Variable/Variable.h
        Classes/Source/Variable/Number/Integer.cpp
        Classes/Header/Variable/Number/Integer.h
        Classes/Source/Variable/Number/FloatingPointNumber.cpp
        Classes/Header/Variable/Number/FloatingPointNumber.h
        Classes/Source/Variable/Number/Number.cpp
        Classes/Header/Variable/Number/Number.h
        Classes/Exception/OperationException.h
        Classes/Source/Contex/Scope.cpp
        Classes/Header/Contex/Scope.h
        Classes/Exception/ScopeException/ScopeException.h
        Classes/Exception/ScopeException/NotInScopeException.h
        Classes/Source/Variable/VariableFactory.cpp
        Classes/Header/Variable/VariableFactory.h
        Classes/Exception/VariableException.h
        Classes/Source/Contex/Contex.cpp
        Classes/Header/Contex/Contex.h
        Classes/Source/Variable/Bool.cpp
        Classes/Header/Variable/Bool.h
)
