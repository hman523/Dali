#include "CodeGenerator.h"
#include "ParseTree.h"
#include <iostream>

std::string ofilename = "out.cpp";

void errorlogger(std::string e);



int main(int argc, char *argv[]) {
  std::cout << "Starting Dali Compiler" << std::endl;
  if (argc != 2) {
    std::cerr << "Need a file to compile" << std::endl;
    exit(1);
  }

  std::cout << "Creating parse tree" << std::endl;
  ParseTree *tree;
  try {
    tree = new ParseTree(std::string(argv[1]));
    std::cout << "Parse tree made successfully" << std::endl;
    // tree->printTree();

  } catch (std::logic_error e) {
    errorlogger("Parsing error: " + std::string(e.what()));
    exit(EXIT_FAILURE);
  }
  std::cout << "Generating code" << std::endl;
  CodeGenerator *gen;
  try {
    gen = new CodeGenerator(tree);
  } catch (std::logic_error e) {
    errorlogger("Code generation error: " + std::string(e.what()));
  }

  try {
    gen->WriteToFile(ofilename);
  } catch (std::exception e) {
    errorlogger("Writing to file error: " + std::string(e.what()));
  }

  return 0;
}

void errorlogger(const std::string e) { std::cerr << e << std::endl; }