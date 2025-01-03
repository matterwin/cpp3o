# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Project files and output
TARGET = main
SRCS = ../src/main.cpp ../src/lexer/Lexer.cpp ../src/printer/Printer.cpp ../src/parser/Parser.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target to build the project
all: $(TARGET)

# Linking step to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Optional: Phony targets to avoid conflicts with files
.PHONY: all clean

