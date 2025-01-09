
#ifndef NULL_LITERAL_H
#define NULL_LITERAL_H

#include "Literal.h"

// NullLiteral -> null
struct NullLiteral : Literal {
  NullLiteral(int l, int c) : Literal(l, c) {}
  
  void print() const override {
    std::cout << "null" << std::endl;
  }
};

#endif
