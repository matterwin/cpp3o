
#ifndef NUM_LITERAL_H
#define NUM_LITERAL_H

#include "Literal.h"

// NumLiteral -> [+-]?([0-9]+)
struct NumLiteral : Literal {
  int value;
    
  NumLiteral(const int value, int l, int c) 
    : Literal(l, c), value(value) {}
  
  void print() const override {
    std::cout << value << std::endl;
  }
};

#endif
