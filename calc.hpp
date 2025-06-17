#ifndef CALC_HPP_
#define CALC_HPP_

#include <vector>
#include <string>
#include <iostream>

namespace Calc {
struct Token {
  char type {};
  int val {};
};

std::vector<Token> tokenise(const std::string&);
std::vector<Token> infixToPostfix(const std::vector<Token>&);
int evalPostfix(const std::vector<Token>&);
int eval(const std::string&);

bool operator==(const Calc::Token&, const Calc::Token&);
std::ostream& operator<<(std::ostream&, const Calc::Token&);

}

#endif    // CALC_HPP_
