//
// Created by hunter on 6/10/19.
//

#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode(TreeNode *myparent, std::string mytext)
    : parent(myparent), numberofchildren(0), text(mytext) {}

void TreeNode::addChild(TreeNode *child) {
  try {
    children.push_back(child);
    ++numberofchildren;
  } catch (...) {
    std::cerr << "Error adding child node to parent" << std::endl;
    numberofchildren = children.size();
  }
}

bool TreeNode::hasChildren() { return (numberofchildren != 0); }

void TreeNode::print() {
  std::cout << text << std::endl;
  if (hasChildren()) {
    for (uint32_t i = 0; i < numberofchildren; ++i) {
      children[i]->print();
    }
  }
}

std::string TreeNode::getText() { return text; }