
#ifndef STRING_LITERAL_H
#define STRING_LITERAL_H

#include "Literal.h"

// StringLiteral -> "[^"]*"
struct StringLiteral : Literal {
  std::string value;
    
  StringLiteral(const std::string& value, int l, int c) 
    : Literal(l, c), value(value) {}
  
  void print() const override {
    std::cout << value << std::endl;
  }
};

#endif
