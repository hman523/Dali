//
// Created by hunter on 6/19/19.
//

#ifndef DALIC_CODEGENERATOR_H
#define DALIC_CODEGENERATOR_H

#include "ParseTree.h"
#include <string>

class CodeGenerator {

public:
  CodeGenerator() = delete;
  CodeGenerator(ParseTree *tree);

private:
  uint32_t GENSYMCOUNT;
  std::string gensym();
};

#endif // DALIC_CODEGENERATOR_H
