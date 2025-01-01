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

// 0 on success, -1 on error
int Lexer::lex() {
  std::cout << "Start of lexical process ..." << std::endl;

  Token* token = Lexer::getNextToken();
  while (token->type != END_OF_FILE) {
    tokens->push_back(*token);
    token = Lexer::getNextToken();
    if (!token) return -1;
  }
  tokens->push_back(*token);
   
  return 0;
}

Token* Lexer::getNextToken() {
  char c;
  while ((c = Lexer::getNextChar()) != EOF) {
    // Whitespace
    if (std::isspace(c)) {
      continue;
    }

    // Comment
    else if (c == '/') {
      // multi-line comment
      if ((c = Lexer::getNextChar()) == '*') {
        while ((c = Lexer::getNextChar()) != EOF) {
          if (c == '*') {
            if ((c = Lexer::getNextChar()) == '/') {
              break;
            }
          }
        }
        if (c == EOF) {
          printer->print("Missing closing */ for comment", lineNum, colNum);
          return nullptr;
        }
        continue;
      }
      // single-line comment
      else if (c == '/') {
        while ((c = Lexer::getNextChar()) != '\n') {}
        continue;
      } else {
        printer->print("Invalid comment", lineNum, colNum);
        return nullptr;
      }
    }    

    // integer
    else if (isdigit(c)) {
      int startColNum = colNum;
      std::string value = "";
      value.push_back(c);

      while ((c = Lexer::getNextChar()) != EOF && isdigit(c)) {
        value.push_back(c);
      }

      if (c != EOF && !isspace(c) && !isdigit(c)) {
        printer->print("Invalid integer", lineNum, colNum);
        return nullptr;
      }

      return new Token(TokenType::INTEGER, value, lineNum, startColNum);
    }

    // string
    else if (c == '"') {
      int startColNum = colNum;
      std::string value = "";

      while ((c = Lexer::getNextChar()) != '"' && c != EOF) {
        value.push_back(c);
      }
      if (c == EOF) {
        printer->print("Missing closing \" for string", lineNum, colNum);
        return nullptr;
      } 

      // consume closing "
      Lexer::consumeToken();

      return new Token(TokenType::STRING, value, lineNum, startColNum);
    }

    // WORD [a-zA-z_]
    else if (isalpha(c)) {
      int startColNum = colNum;
      std::string value = "";

      return new Token(TokenType::WORD, value, lineNum, startColNum);
    }

    // character 
    else if (c == '\'') {}

    // operator
    else if (c == '*') {}

    return new Token(TokenType::WORD, std::string(1, c), lineNum, colNum);
  }
  return new Token(TokenType::END_OF_FILE, "EOF", lineNum, colNum);
}

char Lexer::getNextChar() {
  char c = fileStream.get();
  if (c == '\n') {
    lineNum++;
    colNum = 1;
  } else {
    colNum++;
  }
  return c; 
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


