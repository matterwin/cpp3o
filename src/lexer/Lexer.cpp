#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "../../include/lexer/Lexer.h"
#include "../../include/printer/Printer.h"

Lexer::Lexer(std::vector<Token>* tokens, std::string src, Printer* p) 
  : tokens(tokens), srcFile(src), printer(p) {
  fileStream.open(src);
  if (!fileStream) {
    throw std::runtime_error("Could not open file: " + src);
  }
}

Lexer::~Lexer() {
  if (fileStream.is_open()) {
    fileStream.close();
  }
}

int Lexer::lex() {
  std::cout << "Start of lexical process ..." << std::endl;

  Token token = Lexer::getNextToken();
  while (token.type != END_OF_FILE) {
    tokens->push_back(token);
    token = Lexer::getNextToken();
  }
  tokens->push_back(token);
   
  return 0;
}

// When c == '_' it means we're at EOF
Token Lexer::getNextToken() {
  char c;
  while (Lexer::getNextChar(c)) {
    // Whitespace
    if (std::isspace(c)) {
      if (c == '\n') {
        lineNum++;
        colNum = 1;
      }
      continue;
    }

    // Comment
    else if (c == '/') {
      //TODO make a value for error printing, we print the value of comment on error for scanning
      std::string value = "";
      if (Lexer::getNextChar(c) && c == '*') {
        while (Lexer::getNextChar(c)) {
          if (c == '*') {
            if (Lexer::getNextChar(c) && c == '/') {
              break;
            }
          }
        }
        if (c == '_') {
          printer->print("Missing closing */ for comment", lineNum, colNum);
        }
        continue;
      }
      else if (c == '/') {
        while (Lexer::getNextChar(c) && c != '\n') {}
        continue;
      } else {
        printer->print("Expected start of comment", lineNum, colNum);
      }
    }    

    return Token(TokenType::WORD, std::string(1, c), lineNum, colNum);
  }
  return Token(TokenType::END_OF_FILE, "EOF", lineNum, colNum);
}

bool Lexer::getNextChar(char& c) {
  if (fileStream.get(c)) {
    colNum++;
    return true;
  }
  c = '_';
  return false;
}

void Lexer::consumeToken() {
  fileStream.get();
}

char Lexer::peekAtNextChar() {
  int nextChar = fileStream.peek();
  if (nextChar == EOF) {
    return '_';
  }
  return static_cast<char>(nextChar);
}


