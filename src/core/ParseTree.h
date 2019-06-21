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
  // Default constructor is deleted for safety
  ParseTree() = delete;

  /**
   * ParseTree Constructor
   * @pre none
   * @post Parse tree is made
   * @param filename : the file that is opened and read from
   */
  ParseTree(std::string filename);

  /**
   * printTree function
   * @pre Parse Tree is constructed
   * @post the tree is printed to terminal
   */
  void printTree();

  void parseLines();

private:
  // Head node to parse tree
  TreeNode *blockTree;
  // Vector holding all of the import libraries needed
  std::vector<std::string> importList;
};

#endif // DALIC_PARSETREE_H
