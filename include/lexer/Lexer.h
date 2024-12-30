#ifndef LEXER_H
#define LEXER_H

#include <stack>
#include <iostream>
#include <fstream>
#include <vector>

#include "./Token.h"
#include "../printer/Printer.h"

class Lexer {
private:
  std::vector<Token>* tokens;
  std::string srcFile;
  Printer* printer;
  std::ifstream fileStream;
  int lineNum = 1, colNum = 0;
public:
  Lexer(std::vector<Token>* tokens, std::string src, Printer* p); 
  ~Lexer();
  int lex();
  Token getNextToken();
  bool getNextChar(char& c);
  void consumeToken();
  char peekAtNextChar();
};

#endif
