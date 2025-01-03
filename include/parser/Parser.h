#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "../lexer/Token.h"
#include "../printer/Printer.h"
#include "../absyn/absyn.h"

class Parser {
private:
  std::vector<Token>* tokens;
  std::string srcFile;
  Printer* printer;
  Program* pgm;
public:
  Parser(std::vector<Token>* tokens, std::string src, Printer* p, Program* pgm);
  int parse();
};

#endif
