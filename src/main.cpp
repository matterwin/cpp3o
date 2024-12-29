#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>

#include "../include/lexer/Lexer.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "()()() x.x Error: No source file was provided ..." << std::endl;
    return -1;
  }
  std::string srcFile = argv[1];

  std::vector<Token>* tokens = new std::vector<Token>();
  Lexer* lexer = new Lexer(tokens, srcFile);

  // Lexical Analysis (Scanning)
  if (lexer->lex() < 0) {
    return -1;
  }
  delete lexer;

  for (const auto& t : *tokens) {
    std::cout << "Type: " << TokenTypeNames[t.type]
      << ", Value: " << t.value
      << ", Line: " << t.line
      << ", Column: " << t.column
      << std::endl;
  }
  delete tokens;

  // Syntacial Analysis (Parsing)
  
  // Semantical Analysis
  
  // IR 
  
  // Code Gen

  return 0;
}
