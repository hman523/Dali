//
// Created by hunter on 6/19/19.
//

#include "CodeGenerator.h"
#include <numeric>
#include <fstream>

CodeGenerator::CodeGenerator(ParseTree *mytree) : tree(mytree) {}

void CodeGenerator::WriteToFile(std::string fname) {
  std::string out = std::accumulate(code.begin(), code.end(), std::string(""));
  std::ofstream ofile;
  ofile.open(fname);
  ofile << out;
  ofile.close();
}

std::string CodeGenerator::gensym() {
  return "G___SYMVAL" + std::to_string(GENSYMCOUNT++);
}
