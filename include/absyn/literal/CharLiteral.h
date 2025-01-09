
#ifndef CHAR_LITERAL_H
#define CHAR_LITERAL_H

#include "Literal.h"

// CharLiteral -> '[^']*'
struct CharLiteral : Literal {
  char value;
    
  CharLiteral(const char value, int l, int c) 
    : Literal(l, c), value(value) {}
  
  void print() const override {
    std::cout << value << std::endl;
  }
};

#endif
