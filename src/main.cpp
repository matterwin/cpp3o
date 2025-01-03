#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>

#include "../include/lexer/Lexer.h"
#include "../include/parser/Parser.h"
#include "../include/printer/Printer.h"

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

  Parser* parser = new Parser(tokens, srcFile, p);

  if (parser->parse() < 0) {
    return -1;
  }
  delete parser;
  delete tokens;

  // Syntacial Analysis (Parsing)
  
  // Semantical Analysis (Type Checking)
  
  // IR 
  
  // Code Gen

  return 0;
}
