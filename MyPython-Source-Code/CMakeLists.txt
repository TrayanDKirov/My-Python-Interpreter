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
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/ArgumentOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/PrintOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/EvalOp.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/BooleanEqTree.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/AndOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/EquationTreeFactory.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/InputOperation.cpp

        # Cast operations
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/CastOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/IntCastOp.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/FloatCastOp.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/StringCastOp.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/BoolCastOp.cpp

        # Context / Scope
        Classes/Source/Contex/Scope.cpp
        Classes/Source/Contex/Context.cpp

        # Variables
        Classes/Source/Variable/Variable.cpp
        Classes/Source/Variable/VariableFactory.cpp
        Classes/Source/Variable/BoolVariable.cpp
        Classes/Source/Variable/NoneVariable.cpp
        Classes/Source/Variable/VoidVariable.cpp

        Classes/Source/Variable/Number/IntegerNumber.cpp
        Classes/Source/Variable/Number/FloatingPointNumber.cpp
        Classes/Source/Variable/Number/Number.cpp

        Classes/Source/Variable/Iterable/Iterable.cpp
        Classes/Source/Variable/Iterable/StringVariable.cpp

        # Tests (if you want them in this executable)
        Tests/TestTokenizer.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/OrOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/BooleanEqTree/OrOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/NotOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/BooleanEqTree/NotOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/EqualOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/BooleanEqTree/EqualOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/DifferentOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/BooleanEqTree/DifferentOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/LessOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/BooleanEqTree/LessOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/BiggerOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/BooleanEqTree/BiggerOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/LessOrEqualOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/BooleanEqTree/LessOrEqualOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/BiggerOrEqualOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/BooleanEqTree/BiggerOrEqualOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/ArithmeticEqTree.cpp
        Classes/Header/Interpreter/Operation/EquationTree/ArithmeticEqTree/ArithmeticEqTree.h
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/PlusOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/ArithmeticEqTree/PlusOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/MinusOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/ArithmeticEqTree/MinusOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/MultOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/ArithmeticEqTree/MultOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/DivOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/ArithmeticEqTree/DivOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/PercentOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/ArithmeticEqTree/PercentOperation.h
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/PowerOperation.cpp
        Classes/Header/Interpreter/Operation/EquationTree/ArithmeticEqTree/PowerOperation.h
        Classes/Exception/ValueError.h
        Classes/Exception/ZeroDivisionError.h
        Classes/Exception/FileNotFoundError.h
        Classes/Source/Interpreter/Operation/IfOperation.cpp
        Classes/Header/Interpreter/Operation/IfOperation.h
        Classes/Source/Interpreter/Operation/OperationBody.cpp
        Classes/Header/Interpreter/Operation/OperationBody.h
        Classes/Source/Interpreter/Operation/PassOperation.cpp
        Classes/Header/Interpreter/Operation/PassOperation.h
        Classes/Source/Interpreter/Operation/WhileOperation.cpp
        Classes/Header/Interpreter/Operation/WhileOperation.h
        Classes/Source/Variable/Iterable/ListVariable.cpp
        Classes/Header/Variable/Iterable/ListVariable.h
        Classes/Exception/IndexError.h
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ListEvalOp.cpp
        Classes/Header/Interpreter/Operation/EquationTree/LeaveOperation/ListEvalOp.h
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/GetElementOp.cpp
        Classes/Header/Interpreter/Operation/EquationTree/LeaveOperation/GetElementOp.h
)

target_include_directories(MyPython_Source_Code PRIVATE
        ${CMAKE_SOURCE_DIR}/Classes/Header
)