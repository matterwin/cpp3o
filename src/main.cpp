#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>

#include "../include/lexer/Lexer.h"
// #include "../include/parser/Parser.h"
#include "../include/printer/Printer.h"
#include "../include/absyn/Absyn.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "()()() x.x Error: No source file was provided ..." << std::endl;
    return -1;
  }
  std::string srcFile = argv[1];

  std::vector<Token>* tokens = new std::vector<Token>();
  Printer* p = new Printer(srcFile);
  Lexer* lexer = new Lexer(tokens, srcFile, p);

  // Lexical Analysis (Scanning)
  if (lexer->lex() < 0) {
    return -1;
  }
  delete lexer;

  // delete token vector after parser, we need to delete the tokens while parsing
  
  // Syntacial Analysis (Parsing)
  // Program* pgm = new Program("testO");

  // Parser* parser = new Parser(tokens, srcFile, p, pgm);
  //
  // if (parser->parse() < 0) {
  //   return -1;
  // }
  // delete parser;
  // delete tokens;

  // Semantical Analysis (Type Checking)
  
  // IR (non llvm, from scratch and no optimization to start)
  
  // Code Gen

  // delete nodes in pgm too
  // delete pgm;
  return 0;
}
