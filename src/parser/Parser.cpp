#include <iostream>

#include "../../include/parser/Parser.h"
#include "../../include/printer/Printer.h"

Parser::Parser(std::vector<Token>* tokens, std::string src, Printer* p)
  : tokens(tokens), srcFile(src), printer(p) {
  std::cout << "makde  parser";
}

int Parser::parse() {
  return 0;
}
