//
// Created by hunter on 6/19/19.
//

#include "CodeGenerator.h"

CodeGenerator::CodeGenerator(ParseTree *tree) {}

std::string CodeGenerator::gensym() {
  return "G___SYMVAL" + std::to_string(GENSYMCOUNT++);
}
