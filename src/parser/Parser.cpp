#include <iostream>

#include "../../include/parser/Parser.h"
#include "../../include/printer/Printer.h"
#include "../../include/absyn/absyn.h"

Parser::Parser(std::vector<Token>* tokens, std::string src, Printer* p, Program* pgm)
  : tokens(tokens), srcFile(src), printer(p), pgm(pgm) {
  std::cout << "make  parser";
}

int Parser::parse() {
  return 0;
}


