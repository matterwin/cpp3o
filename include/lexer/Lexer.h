#ifndef LEXER_H
#define LEXER_H

#include <stack>
#include <iostream>
#include <fstream>
#include <vector>

#include "./Token.h"

class Lexer {
private:
  std::vector<Token>* tokens;
  std::string srcFile;
  std::ifstream fileStream;
  int lineNum = 1, colNum = 0;
public:
  Lexer(std::vector<Token>* tokens, std::string src);
  ~Lexer();
  int lex();
  Token getNextToken();
  bool getNextChar(char& c);
  void consumeToken();
  char peekAtNextChar();
};

#endif
