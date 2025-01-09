
#ifndef BOOL_LITERAL_H
#define BOOL_LITERAL_H

#include "Literal.h"

// BoolLiteral -> 0 | (1-9)+
struct BoolLiteral : Literal {
  int value;
    
  BoolLiteral(const int value, int l, int c) 
    : Literal(l, c), value(value) {}
  
  void print() const override {
    std::cout << value << std::endl;
  }
};

#endif
