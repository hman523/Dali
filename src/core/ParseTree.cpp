//
// Created by hunter on 6/10/19.
//

#include "ParseTree.h"
#include <exception>
#include <fstream>
#include <stack>

ParseTree::ParseTree(std::string filename) {
  blockTree = new TreeNode(nullptr, "");
  std::stack<TreeNode *> blocknest;
  blocknest.push(blockTree);

  std::ifstream file;
  file.open(filename);
  char curr;
  std::string currentline("");
  while (file.get(curr)) {
    if (curr == ';') {
      TreeNode *temp = new TreeNode(blocknest.top(), currentline);
      blockTree->addChild(temp);
      currentline = "";
    } else if (curr == '{') {
      TreeNode *temp = new TreeNode(blocknest.top(), currentline);
      blocknest.push(temp);
      blockTree->addChild(temp);
      currentline = "";
    } else if (curr == '}') {
      blocknest.pop();
    } else {
      currentline += curr;
    }
  }

  blocknest.pop();
  if (!blocknest.empty()) {
    throw std::logic_error("Missing or extra bracket error");
  }
}

void ParseTree::printTree() { blockTree->print(); }