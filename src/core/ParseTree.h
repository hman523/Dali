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
  ParseTree(std::string filename);
  void printTree();

private:
  TreeNode *blockTree;
};

#endif // DALIC_PARSETREE_H
