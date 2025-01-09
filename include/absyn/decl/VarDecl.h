#ifndef FUNCTION_DECL_H
#define FUNCTION_DECL_H

#include "Decl.h"

// VarDecl -> <Type> <Identifier> (, <Identifier>)* ;
//          | <Type> * <Identifier> (, <Identifier>)* ;
//          | <Type> & <Identifier> (, <Identifier>)* ;
struct VarDecl : Decl {
  Type type;
  std::vector<Identifier> identifiers;

  VarDecl()
  void print() const override {}
};

#endif
