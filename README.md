# Calculator

A C++ implementation of a mathematical expression evaluator using the Shunting-yard algorithm. Features infix to postfix conversion, operator precedence handling, and stack-based evaluation for efficient mathematical computation.

This project is a custom, from-scratch implementation of a mathematical expression parser and evaluator in C++. It is designed to process standard infix notation expressions and evaluate them with proper operator precedence and parentheses support, mimicking the functionality of a basic calculator.

The implementation uses the Shunting-yard algorithm to convert infix expressions to postfix notation (Reverse Polish Notation), then evaluates the postfix expression using a stack-based approach. The calculator automatically handles operator precedence and associativity, ensuring mathematically correct results.

## Core Features

-   **Infix to Postfix Conversion**: Implements the classic Shunting-yard algorithm for converting standard mathematical notation to Reverse Polish Notation.
-   **Proper Operator Precedence**: Automatically handles precedence rules with multiplication and division taking priority over addition and subtraction.
-   **Parentheses Support**: Full support for parentheses to override default operator precedence rules.
-   **Multi-digit Number Support**: Handles integers of arbitrary length, not limited to single digits.
-   **Error Handling**: Includes division by zero detection with appropriate runtime error reporting.

## Implementation Details

-   **Tokenizer**: The expression string is parsed into a `std::vector` of `Token` structures (`std::vector<Token>`). Each token represents either a number (type `'n'` with integer value) or an operator/parenthesis (character type).
-   **Shunting-yard Converter**: Converts the infix token sequence to postfix notation using operator precedence rules and a `std::vector<Token>` as an operator stack.
-   **Postfix Evaluator**: Uses a `std::vector<int>` as a stack to evaluate the postfix expression, performing operations as operators are encountered.

## How to Build and Run Tests

The project includes functionality to evaluate mathematical expressions with proper error handling.

### Prerequisites

-   A C++ compiler that supports the C++11 standard or later (e.g., GCC 7+, Clang 5+).

### Compiling and Running

1.  Navigate to the project's root directory in your terminal.
2.  Compile the source files using the following command:

   ```bash
   g++ -std=c++11 main.cpp calc.cpp -o calculator
   ```

3.  Execute the compiled program:

   ```bash
   ./calculator
   ```

   All operations should work correctly, confirming that the implementation is functioning as expected.

## Example Usage

Here is a simple example demonstrating how to use the `Calculator` functionality.

```cpp
#include <iostream>
#include "calc.hpp"

int main() {
   // 1. Evaluate a simple expression
   std::string expr1 = "3+4*2";
   int result1 = Calc::eval(expr1);
   std::cout << expr1 << " = " << result1 << std::endl;

   // 2. Use parentheses to override precedence
   std::string expr2 = "(1+2)*3";
   int result2 = Calc::eval(expr2);
   std::cout << expr2 << " = " << result2 << std::endl;

   // 3. Handle division
   std::string expr3 = "10/2-3";
   int result3 = Calc::eval(expr3);
   std::cout << expr3 << " = " << result3 << std::endl;

   // 4. Step-by-step processing (advanced usage)
   std::vector<Calc::Token> tokens = Calc::tokenise("2+3*4");
   std::vector<Calc::Token> postfix = Calc::infixToPostfix(tokens);
   int result4 = Calc::evalPostfix(postfix);
   std::cout << "2+3*4 = " << result4 << std::endl;

   // 5. Error handling
   try {
       int result5 = Calc::eval("10/0");
       std::cout << "10/0 = " << result5 << std::endl;
   } catch (const std::runtime_error& e) {
       std::cout << "Error: " << e.what() << std::endl;
   }

   return 0;
}
```
### Expected Output
```cpp
3+4*2 = 11
(1+2)*3 = 9
10/2-3 = 2
2+3*4 = 14
Error: divide by zero
```
*(Note: The calculator follows standard mathematical operator precedence rules.)*
