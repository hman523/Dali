#include "ParseTree.h"
#include <iostream>

void errorlogger(std::string e);

int main(int argc, char *argv[]) {
  std::cout << "Starting Dali Compiler" << std::endl;
  if (argc != 2) {
    std::cout << "Need a file to compile" << std::endl;
    exit(1);
  }

  std::cout << "Creating parse tree" << std::endl;
  ParseTree *tree;
  try {
    tree = new ParseTree(std::string(argv[1]));
    tree->printTree();

  } catch (std::logic_error e) {
    errorlogger(e.what());
    exit(EXIT_FAILURE);
  }

  return 0;
}

void errorlogger(const std::string e) { std::cerr << e << std::endl; }