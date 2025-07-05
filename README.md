# C++ Calculator Implementation

This repository provides an academic-style implementation of a basic arithmetic calculator in C++. It supports evaluating mathematical expressions using standard infix notation. Expressions are internally converted to postfix (Reverse Polish Notation) before evaluation, ensuring correctness and efficiency.

## Core Features

- **Basic Arithmetic Operations**: Supports addition (`+`), subtraction (`-`), multiplication (`*`), and integer division (`/`).
- **Expression Evaluation**: Parses and evaluates arithmetic expressions written in infix notation.
- **Postfix Conversion**: Internally converts expressions to postfix notation for efficient evaluation.
- **Robust Testing**: Comprehensive unit tests using Google Test framework to validate functionality.

## Implementation Details/Technology Used

- **Tokenisation**: Breaks down input strings into manageable tokens for parsing.
- **Infix to Postfix Conversion**: Uses the Shunting Yard algorithm to convert infix expressions into postfix notation.
- **Postfix Evaluation**: Evaluates postfix expressions efficiently using a stack-based approach.
- **Built With**:
  - C++17 Standard
  - Google Test framework for unit testing
  - Standard Template Library (STL)

## Compilation/Execution Instructions

### Prerequisites

- C++ compiler supporting C++17 (GCC 8+, Clang 10+)
- [Google Test](https://github.com/google/googletest) framework installed and configured.

### Compile and Run Tests

Compile the test suite (adjust paths to your Google Test installation):

```bash
g++ -std=c++17 main.cpp calc.cpp -o calculator_tests -I/path/to/googletest/include -L/path/to/googletest/lib -lgtest -lgtest_main -pthread
```

Run the tests:

```bash
./calculator_tests
```

All tests should pass, confirming correct functionality.

### Demonstrating Example Usage (Separately from Tests)

To demonstrate basic calculator functionality clearly, create a separate file (`demo.cpp`):

```cpp
#include <iostream>
#include "calc.hpp"

int main() {
    std::string expression = "3 + 5 * (10 - 4)";
    int result = Calc::eval(expression);
    std::cout << "Expression: " << expression << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

Compile separately:

```bash
g++ -std=c++17 demo.cpp calc.cpp -o demo
```

Run the demo:

```bash
./demo
```

### Expected Output:

```
Expression: 3 + 5 * (10 - 4)
Result: 33
```

## Assumptions/Limitations

- Supports integer arithmetic only (no floating-point calculations).
- Division operations perform integer division, truncating decimals.
- Does not handle invalid input or syntax errors robustly beyond basic parsing checks.

## Author Acknowledgement

Developed by Mohammed as part of Computer Science coursework at the University of Technology Sydney (UTS).
