#ifndef IF_STMT_H
#define IF_STMT_H

#include <iostream>

#include "Stmt.h"
#include "../Block.h"
#include "../expr/Expr.h"

// IfStmt -> if ( <Expr> ) <Block> (else <Block>)?
struct IfStmt : Stmt {
  Expr expr;
  Block ifBlock, elseBlock;
  
  IfStmt(int l, int c, Expr expr, Block ifBlock, Block elseBlock) 
    : Stmt(l, c), expr(expr), ifBlock(ifBlock), elseBlock(elseBlock) {}

  void print() const override {}
};

#endif
