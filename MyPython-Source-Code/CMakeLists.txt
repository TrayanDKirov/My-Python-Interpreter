cmake_minimum_required(VERSION 3.20)
project(MyPython_Source_Code)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyPython_Source_Code
        main.cpp

        # Interpreter
        Classes/Source/Interpreter/Interpreter.cpp
        Classes/Source/Interpreter/Tokenizer.cpp
        Classes/Source/Interpreter/MpySymbols.cpp

        # Operations
        Classes/Source/Interpreter/Operation/Operation.cpp
        Classes/Source/Interpreter/Operation/OperationFactory.cpp
        Classes/Source/Interpreter/Operation/Assignment.cpp
        Classes/Source/Interpreter/Operation/ArgumentOperation/ArgumentOperation.cpp
        Classes/Source/Interpreter/Operation/ArgumentOperation/PrintOperation.cpp
        Classes/Source/Interpreter/Operation/EvalOp.cpp

        # Cast operations
        Classes/Source/Interpreter/Operation/ArgumentOperation/CastOperation/IntCastOp.cpp
        Classes/Source/Interpreter/Operation/ArgumentOperation/CastOperation/FloatCastOp.cpp
        Classes/Source/Interpreter/Operation/ArgumentOperation/CastOperation/StringCastOp.cpp
        Classes/Source/Interpreter/Operation/ArgumentOperation/CastOperation/BoolCastOp.cpp

        # Context / Scope
        Classes/Source/Contex/Scope.cpp
        Classes/Source/Contex/Context.cpp

        # Variables
        Classes/Source/Variable/Variable.cpp
        Classes/Source/Variable/VariableFactory.cpp
        Classes/Source/Variable/BoolVariable.cpp
        Classes/Source/Variable/NoneVariable.cpp

        Classes/Source/Variable/Number/IntegerNumber.cpp
        Classes/Source/Variable/Number/FloatingPointNumber.cpp
        Classes/Source/Variable/Number/Number.cpp

        Classes/Source/Variable/Iterable/Iterable.cpp
        Classes/Source/Variable/Iterable/StringVariable.cpp

        # Tests (if you want them in this executable)
        Tests/TestTokenizer.cpp
        Classes/Exception/Error.h
        Classes/Exception/SyntaxError.h
        Classes/Source/Interpreter/Operation/ArgumentOperation/CastOperation/CastOperation.cpp
        Classes/Source/Interpreter/Operation/ArgumentOperation/InputOperation.cpp
        Classes/Header/Interpreter/Operation/ArgumentOperation/InputOperation.h
        Classes/Source/Variable/VoidVariable.cpp
        Classes/Header/Variable/VoidVariable.h
        Classes/Exception/TypeError.h
)

