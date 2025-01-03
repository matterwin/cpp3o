#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "../lexer/Token.h"
#include "../printer/Printer.h"

class Parser {
private:
  std::vector<Token>* tokens;
  std::string srcFile;
  Printer* printer;
public:
  Parser(std::vector<Token>* tokens, std::string src, Printer* p);
  int parse();
};

#endif
