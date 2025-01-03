#ifndef ABSYN_H
#define ABSYN_H

#include <vector>
#include <string>
#include <memory>

struct ASTNode {
  int lineNum;
  int colNum;
  
  ASTNode(int l, int c) : lineNum(l), colNum(c) {}  
  virtual ~ASTNode() = default;
};

struct Global : ASTNode {
  virtual void printNode() const = 0; 
  virtual ~Global() = default;
};

struct 

struct File : ASTNode {
  std::string fileName;
  std::vector<std::shared_ptr<Global>> globals; 

  File(const std::string& name) : ASTNode(0, 0), fileName(name) {}
};

struct Program : ASTNode {
  std::string object;
  std::vector<std::shared_ptr<File>> files; 

  Program(const std::string& o) 
    : ASTNode(0, 0), object(o) {}
};

#endif
