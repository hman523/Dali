//
// Created by hunter on 6/10/19.
//

#ifndef DALIC_TREENODE_H
#define DALIC_TREENODE_H

#include <stdint-gcc.h>
#include <string>
#include <vector>

class TreeNode {
public:
  TreeNode(TreeNode *parent, std::string text);
  void addChild(TreeNode *child);
  bool hasChildren();
  std::string getText();
  void print();

private:
  TreeNode *parent;
  std::vector<TreeNode *> children;
  uint32_t numberofchildren;
  std::string text;
};

#endif // DALIC_TREENODE_H
