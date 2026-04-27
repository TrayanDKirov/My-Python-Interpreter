# 🐍 MyPython Interpreter

A Python-like scripting language interpreter written in C++. MyPython (`.mpy`) supports a substantial subset of Python syntax including variables, arithmetic, control flow, functions, lists, strings, and multi-file imports.

---

## ✨ Features

### 1️⃣0️⃣0️⃣1️⃣1️⃣ Data Types
| Type | Example |
|---|---|
| Integer | `x = 42` |
| Float | `x = 3.14` |
| String | `x = "hello"` or `x = 'hello'` |
| Boolean | `x = True` / `x = False` |
| None | `x = None` |
| List | `x = [1, 2, 3]` |

### ⚙️ Operators

**Arithmetic:** `+`, `-`, `*`, `/`, `%`, `**` (power)

**Comparison:** `==`, `!=`, `<`, `>`, `<=`, `>=`

**Boolean:** `and`, `or`, `not`

### 🔀 Control Flow

```python
# if / elif / else
if x > 10:
    print('big')
elif x > 5:
    print('medium')
else:
    print('small')

# while loop
i = 0
while i < 5:
    print(i)
    i = i + 1

# for loop (over lists and strings)
for x in [1, 2, 3]:
    print(x)

for ch in "hello":
    print(ch)

# break and continue
while i < 10:
    if i == 3:
        break
    i = i + 1

for x in nums:
    if x == 2:
        continue
    print(x)
```

### 🔧 Functions

```python
def greet(name):
    print("Hello, ", name)

greet("Alice")

def factorial(n):
    if n <= 1:
        return 1
    return n * factorial(n - 1)

print(factorial(5))
```

- Supports recursion
- `return` exits with a value
- Functions are first-class variables stored in scope

### 📋 Lists

```python
nums = [1, 2, 3, 4]
print(nums[0])       # index read
nums[1] = 99         # index write
nums[i + 1] = 5      # expression as index
print(nums)          # prints full list
```

### 🔤 Strings

```python
a = "hello"
b = " world"
print(a + b)         # concatenation
print(a[0])          # character access
for ch in a:         # iteration
    print(ch)
```

### 🔄 Type Casting

```python
int("42")       # string to int
float("3.14")   # string to float
str(100)        # number to string
bool(0)         # to boolean
```

### 🛠️ Built-in Functions

| Function | Description |
|---|---|
| `print(...)` | Print to stdout. Supports `sep` and `end` keyword args |
| `input(prompt)` | Prints just like `print(...)` then reads a line from stdin, returns as string |
| `int(x)` | Cast to integer |
| `float(x)` | Cast to float |
| `str(x)` | Cast to string |
| `bool(x)` | Cast to boolean |

### 📥 Import

Split code across multiple `.mpy` files using `import`:

```python
import tests.import_test.math_utils
import tests.import_test.greet_utils

print(factorial(5))
greet("Alice")
```

The import path uses `.` as a separator corresponding to the filesystem path from the working directory.

### 💬 Comments

```python
# This is a comment
x = 5  # inline comment
```

---

## 🗂️ Project Structure

```
MyPython-Source-Code/
├── main.cpp                        Entry point
├── Classes/
│   ├── Exception/
│   │   ├── Errors/                 Error types (TypeError, ValueError, SyntaxError, ...)
│   │   └── InterpreterCalls/       Control flow signals (ReturnCall, BreakCall, ContinueCall)
│   ├── Header/
│   │   ├── Interpreter/
│   │   │   ├── Interpreter.h       Reads and executes .mpy files
│   │   │   ├── Tokenizer.h         Splits source lines into tokens
│   │   │   ├── MpySymbols.h        Language symbol constants and helpers
│   │   │   └── Operation/
│   │   │       ├── OperationFactory.h      Parses tokens into Operation objects
│   │   │       ├── OperationBody.h         Sequence of operations (function/loop body)
│   │   │       ├── Assignment.h            Variable assignment
│   │   │       ├── IfOperation.h           if/elif/else
│   │   │       ├── WhileOperation.h        while loop
│   │   │       ├── ForOperation.h          for-in loop
│   │   │       ├── BreakOperation.h        break
│   │   │       ├── ContinueOperation.h     continue
│   │   │       ├── ImportOperation.h       import
│   │   │       ├── PassOperation.h         pass
│   │   │       └── EquationTree/
│   │   │           ├── EquationTreeFactory.h       Expression parser (precedence climbing)
│   │   │           ├── ArithmeticEqTree/           +, -, *, /, %, **
│   │   │           ├── BooleanEqTree/              ==, !=, <, >, <=, >=, and, or, not
│   │   │           └── LeaveOperation/
│   │   │               ├── EvalOp.h                Literal or variable lookup
│   │   │               ├── ListEvalOp.h            List literal [...]
│   │   │               ├── GetElementOp.h          Index access x[i]
│   │   │               └── ArgumentOperation/
│   │   │                   ├── PrintOperation.h         print 
│   │   │                   ├── InputOperation.h         input 
│   │   │                   ├── FuncDefOperation.h       def function(a, b)
│   │   │                   ├── FunctionCallOperation.h  function(4, 3) 
│   │   │                   ├── ReturnOperation.h        return
│   │   │                   └── CastOperation/           int(), float(), str(), bool()
│   │   ├── Variable/
│   │   │   ├── Variable.h                Abstract base
│   │   │   ├── BoolVariable.h            bool
│   │   │   ├── NoneVariable.h            None
│   │   │   ├── VoidVariable.h            Internal sentinel (not exposed to user)
│   │   │   ├── FunctionVariable.h        <function:f>
│   │   │   ├── Number/      
│   │   │   │   ├── IntegerNumber.h       int
│   │   │   │   └── FloatingPointNumber.h float
│   │   │   └── Iterable/
│   │   │       ├── IterableVariable.h
│   │   │       ├── StringVariable.h      str
│   │   │       └── ListVariable.h        list [1, 2, 4]
│   │   └── Contex/
│   │       ├── Context.h       Holds scope + I/O streams
│   │       └── Scope.h         Variable name → value map with parent chain
├── tests/                      Feature test scripts (.mpy)
├── MpyPrograms/                Demo programs (.mpy)
└── results_from_tests/         Results after .\MyPython_Source_Code -run-tests
```

---

## 🔨 Building

The project uses CMake. Open it in CLion or build from the command line:

```bash
mkdir cmake-build-debug && cd cmake-build-debug
cmake ..
cmake --build .
```

---

## 🚀 Running

```bash
./MyPython_Source_Code <file-path>
```
Or
```bash
./MyPython_Source_Code -run-tests
```

The interpreter takes the `filePath` as argument. Then opnes the .mpy file and interprets it. Alternativly you can use `-run-tests`. The test files in tests\ are executed and you get the result - how many passed. In the results_from_test\ directory you will find the expected and actual output of each test file.

---

## 💡 Example Programs

### 🌀 Fibonacci (recursive)
```python
def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)

print(fib(7))
```

### 🫧 Bubble Sort
```python
nums = [64, 34, 25, 12, 22, 11, 90]
n = 7
i = 0
while i < n:
    j = 0
    while j < n - i - 1:
        if nums[j] > nums[j + 1]:
            temp = nums[j]
            nums[j] = nums[j + 1]
            nums[j + 1] = temp
        j = j + 1
    i = i + 1
print(nums)
```

### 🧮 Interactive Calculator
```python
a = input('')
while a != "q":
    a = int(a)
    op = input('')
    b = int(input(''))
    if op == "+":
        print(a + b)
    elif op == "-":
        print(a - b)
    elif op == "*":
        print(a * b)
    elif op == "/":
        print(a / b)
    a = input('')
```

---

## ⚠️ Error Handling

Runtime errors are caught and printed with the line number:

```
Line 5: ValueError: x not defined in this scope
Line 12: TypeError: Left and right side of + must be the same type.
Line 3: SyntaxError: indentation is not correct
```

**Error types implemented:** `SyntaxError`, `TypeError`, `ValueError`, `ZeroDivisionError`, `IndexError`, `FileNotFoundError`, `LogicError`

---

## 🏗️ Architecture Notes

**Parsing** is done in a single pass. `OperationFactory` tokenizes each line and builds an `Operation` tree. Expressions are parsed by `EquationTreeFactory` using a recursive precedence-climbing approach (8 priority levels: `or` → `and` → `not` → comparisons → `+/-` → `*/%` → `**` → leaf).

**Execution** is tree-walking. Each `Operation` node implements `execute(Context&)` which returns a `Variable*`. The `Context` carries the current `Scope` (a linked chain for nested scopes) and the I/O streams.

**Control flow** (`break`, `continue`, `return`) is implemented via C++ exceptions (`break_call`, `continue_call`, `return_call`) that unwind the call stack to the appropriate handler in `WhileOperation`, `ForOperation`, and `FunctionCallOperation`.

**Scoping** follows Python's flat function scope: `if` and `while` share the parent scope; functions create a new isolated scope.
