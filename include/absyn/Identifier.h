#ifndef IDENTIFIER_H
#define IDENTIFER_H 

#include <string>

#include "Absyn.h"

// Identifier -> [a-zA-Z][a-zA-Z0-9_]*
struct Identifier : Absyn {
  std::string value;

  Identifier(const std::string& str, int l, int c) 
    : Absyn(l, c), value(str) {}

  void print() const override {
    std::cout << value << std::endl;
  }
};

#endif
