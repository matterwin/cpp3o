#ifndef ABSYN_H
#define ABSYN_H

struct Absyn {
  int lineNum;
  int colNum;
  
  Absyn(int l, int c) : lineNum(l), colNum(c) {}  
  virtual ~Absyn() = default;
  virtual void print() const = 0;
};

#endif
