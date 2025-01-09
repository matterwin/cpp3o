#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <unordered_set>

enum TokenType {
  WORD,
  CHARACTER,
  INTEGER,
  STRING,
  COMMENT,
  SYMBOL,
  END_OF_FILE
};

const std::string TokenTypeNames[] = {
  "WORD", "CHARACTER", "INTEGER", "STRING", "COMMENT", "SYMBOL", "END_OF_FILE"
};

const std::unordered_set<std::string> cppReservedWords = {
  "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool",
  "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl",
  "concept", "const", "consteval", "constexpr", "constinit", "const_cast", "continue",
  "co_await", "co_return", "co_yield", "decltype", "default", "delete", "do", "double",
  "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for",
  "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept",
  "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public",
  "register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static",
  "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local",
  "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
  "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
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
