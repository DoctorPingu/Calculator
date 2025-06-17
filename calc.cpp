/************************************************************************************
* README
* ---------
* This task (2a Calculator) was completed independently.
* As part of the assignment requirements, no GenAI were used to directly solve the assignment, write logic or produce code output.
*
* Any usage of copying and pasting was purely for:
* - Rearranging sections of existing code.
* - Reverting back to earlier versions of my own work through the submissions tab.
* - Improving clarity, formatting or correcting previous logic.
*
* All debugging and problem solving followed academic integrity principles outlined by UTS.
************************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "calc.hpp"

std::ostream& Calc::operator<<(std::ostream& out, const Calc::Token& t) {
  out << "{'" << t.type << "', " << t.val << '}';
  return out;
}

bool Calc::operator==(const Calc::Token& a, const Calc::Token& b) {
  if (a.type != b.type) {
    return false;
  }
  if (a.type == 'n') {
    return a.val == b.val;
  }
  return true;
}

// Function we needed to work on for this task.
std::vector<Calc::Token> Calc::infixToPostfix(const std::vector<Token>& input) {
  std::vector<Token> output;     // Output list in postfix order.
  std::vector<Token> opStack;    // Stack to hold operators and parentheses.

  // Define operator precedence: higher value means higher precedence.
  auto precedence = [](char op) -> int {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
  };

  // Define associativity: all operators in this assignment are left-associative.
  auto isLeftAssociative = [](char) -> bool {
    return true;
  };

  // Process each token in the infix input.
  for (const Token& token : input) {
    if (token.type == 'n') {
      // If it's a numberr, add directly to output.
      output.push_back(token);
    } else if (token.type == '(') {
      // Left parenthesis goes on the stack.
      opStack.push_back(token);
    } else if (token.type == ')') {
      // Pop operators from stack to output until matching '(' is found.
      while (!opStack.empty() && opStack.back().type != '(') {
        output.push_back(opStack.back());
        opStack.pop_back();
      }
      // Discard the '(' itself.
      if (!opStack.empty() && opStack.back().type == '(') {
        opStack.pop_back();
      }
    } else {
      // Operator: pop from stack to output while top has higher or equal precedence.
      while (!opStack.empty()) {
        Token top = opStack.back();
        if (top.type == '(') break;
        if (precedence(top.type) > precedence(token.type) || (precedence(top.type) == precedence(token.type) && isLeftAssociative(token.type))) {
          output.push_back(top);
          opStack.pop_back();
        } else {
          break;
        }
      }
      // Push current operator onto the stack.
      opStack.push_back(token);
    }
  }

  // Pop any remaining operators from the stack to the output.
  while (!opStack.empty()) {
    output.push_back(opStack.back());
    opStack.pop_back();
  }

  return output;
}

int Calc::evalPostfix(const std::vector<Token>& tokens) {
  if (tokens.empty()) {
    return 0;
  }
  std::vector<int> stack;
  for (Token t : tokens) {
    if (t.type == 'n') {
      stack.push_back(t.val);
    } else {
      int val = 0;
      if (t.type == '+') {
        val = stack.back() + *(stack.end()-2);
      } else if (t.type == '*') {
        val = stack.back() * *(stack.end()-2);
      } else if (t.type == '-') {
        val = *(stack.end()-2) - stack.back();
      } else if (t.type == '/') {
        if (stack.back() == 0) {
          throw std::runtime_error("divide by zero");
        }
        val = *(stack.end()-2) / stack.back();
      } else {
          std::cout << "invalid token\n";
      }
      stack.pop_back();
      stack.pop_back();
      stack.push_back(val);
    }
  }
  return stack.back();
}

std::vector<Calc::Token> Calc::tokenise(const std::string& expression) {
  const std::vector<char> symbols = {'+', '-', '*', '/', '(', ')'};
  std::vector<Token> tokens {};
  for (std::size_t i =0; i < expression.size(); ++i) {
    const char c = expression[i];

    if (std::find(symbols.begin(), symbols.end(), c) != symbols.end()) {
      tokens.push_back({c});
    } else if (isdigit(c)) {
      std::string num {c};
      while (i + 1 < expression.size() && isdigit(expression[i + 1])) {
        ++i;
        num.push_back(expression[i]);
      }
      tokens.push_back({'n', std::stoi(num)});
    }
  }
  return tokens;
}

int Calc::eval(const std::string& expression) {
  std::vector<Token> tokens = tokenise(expression);
  std::vector<Token> postfix = infixToPostfix(tokens);
  return evalPostfix(postfix);
}
