#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
  WORD,
  CHARACTER,
  INTEGER,
  STRING,
  COMMENT,
  OPERATOR,
  END_OF_FILE
};

const std::string TokenTypeNames[] = {
  "WORD", "CHARACTER", "INTEGER", "STRING", "COMMENT", "OPERATOR", "END_OF_FILE"
};

struct Token {
  TokenType type;
  std::string value;
  int line;
  int column;

  Token(TokenType t, std::string s, int l, int c) 
    : type(t), value(s), line(l), column(c) {}
};

#endif
