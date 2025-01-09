#ifndef FUNCTION_NAME_H
#define FUNCTION_NAME_H

#include "Absyn.h"
#include "Identifier.h"

// FunctionName -> <Identifier>
struct FunctionName : ASTNode {
  Identifier id;
  FunctionName(const Identifier id, int l, int c) 
    : Absyn(l, c), id(id) {} 

  void print() const override {
    std::cout << id.value << std::endl;
  }
};

#endif
