cmake_minimum_required(VERSION 3.20)
project(MyPython_Source_Code)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyPython_Source_Code
        main.cpp

        # ---------------------------------------------------------------
        # Interpreter Core
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Interpreter.cpp
        Classes/Source/Interpreter/Tokenizer.cpp
        Classes/Source/Interpreter/MpySymbols.cpp

        # ---------------------------------------------------------------
        # Context & Scope
        # ---------------------------------------------------------------
        Classes/Source/Contex/Context.cpp
        Classes/Source/Contex/Scope.cpp

        # ---------------------------------------------------------------
        # Variables
        # ---------------------------------------------------------------

        # Base
        Classes/Source/Variable/Variable.cpp
        Classes/Source/Variable/VariableFactory.cpp
        Classes/Source/Variable/BoolVariable.cpp
        Classes/Source/Variable/NoneVariable.cpp
        Classes/Source/Variable/VoidVariable.cpp

        # Numbers
        Classes/Source/Variable/Number/Number.cpp
        Classes/Source/Variable/Number/IntegerNumber.cpp
        Classes/Source/Variable/Number/FloatingPointNumber.cpp

        # Iterables
        Classes/Source/Variable/Iterable/IterableVariable.cpp
        Classes/Source/Variable/Iterable/StringVariable.cpp
        Classes/Source/Variable/Iterable/ListVariable.cpp

        # Functions
        Classes/Source/Variable/FunctionVariable.cpp

        # ---------------------------------------------------------------
        # Operations — Core
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Operation/Operation.cpp
        Classes/Source/Interpreter/Operation/OperationFactory.cpp
        Classes/Source/Interpreter/Operation/OperationBody.cpp
        Classes/Source/Interpreter/Operation/Assignment.cpp

        # ---------------------------------------------------------------
        # Operations — Control Flow
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Operation/IfOperation.cpp
        Classes/Source/Interpreter/Operation/WhileOperation.cpp
        Classes/Source/Interpreter/Operation/ForOperation.cpp
        Classes/Source/Interpreter/Operation/BreakOperation.cpp
        Classes/Source/Interpreter/Operation/ContinueOperation.cpp
        Classes/Source/Interpreter/Operation/PassOperation.cpp

        # ---------------------------------------------------------------
        # Operations — Functions
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/FuncDefOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/FunctionCallOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/ReturnOperation.cpp

        # ---------------------------------------------------------------
        # Operations — Import
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Operation/ImportOperation.cpp

        # ---------------------------------------------------------------
        # Expression Tree — Core & Leaf
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Operation/EquationTree/EquationTreeFactory.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/EvalOp.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ListEvalOp.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/GetElementOp.cpp

        # ---------------------------------------------------------------
        # Expression Tree — Arithmetic Operations
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/ArithmeticEqTree.cpp
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/PlusOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/MinusOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/MultOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/DivOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/PercentOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/ArithmeticEqTree/PowerOperation.cpp

        # ---------------------------------------------------------------
        # Expression Tree — Boolean & Comparison Operations
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/BooleanEqTree.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/AndOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/OrOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/NotOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/EqualOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/DifferentOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/LessOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/BiggerOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/LessOrEqualOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/BoolEqTree/BiggerOrEqualOperation.cpp

        # ---------------------------------------------------------------
        # Expression Tree — Argument Operations
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/ArgumentOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/PrintOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/InputOperation.cpp

        # ---------------------------------------------------------------
        # Expression Tree — Type Cast Operations
        # ---------------------------------------------------------------
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/CastOperation.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/IntCastOp.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/FloatCastOp.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/StringCastOp.cpp
        Classes/Source/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/BoolCastOp.cpp
)

target_include_directories(MyPython_Source_Code PRIVATE
        ${CMAKE_SOURCE_DIR}/Classes/Header
)