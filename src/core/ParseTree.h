//
// Created by hunter on 6/10/19.
//

#ifndef DALIC_PARSETREE_H
#define DALIC_PARSETREE_H

#include <string>
#include <vector>

#include "TreeNode.h"

class ParseTree {
public:
  //Default constructor is deleted for safety
    ParseTree() = delete;

    ParseTree(std::string filename);
  void printTree();

private:
  TreeNode *blockTree;
  std::vector<std::string> importlist;
};

#endif // DALIC_PARSETREE_H
