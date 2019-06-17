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
  bool inString = false;
  bool inCpp = false;
  while (file.get(curr)) {
    if (curr == '$' && !inString && !inCpp) {
      inCpp = true;
      /**if (currentline != ""){
          throw std::logic_error("Parse error: cannot have c++ in a dali
      expression");
      }**/
      currentline += "$";
    } else if (curr == '$' && !inString && inCpp) {
      currentline += "$";
      TreeNode *temp = new TreeNode(blocknest.top(), currentline);
      blockTree->addChild(temp);
      currentline = "";
      inCpp = false;
    } else if (curr == '"' && !inString && !inCpp) {
      inString = true;
      currentline += curr;

    } else if (curr == '"' && inString && !inCpp) {
      inString = false;
      currentline += curr;

    }

    else if (curr == ';' && !inString && !inCpp) {
      TreeNode *temp = new TreeNode(blocknest.top(), currentline);
      blockTree->addChild(temp);
      currentline = "";
    } else if (curr == '{' && !inString && !inCpp) {
      TreeNode *temp = new TreeNode(blocknest.top(), currentline);
      blocknest.push(temp);
      blockTree->addChild(temp);
      currentline = "";
    } else if (curr == '}' && !inString && !inCpp) {
      blocknest.pop();
    } else {
      currentline += curr;
    }
  }
  if (currentline != "") {
    TreeNode *temp = new TreeNode(blocknest.top(), currentline);
    blockTree->addChild(temp);
  }

  blocknest.pop();
  if (!blocknest.empty()) {
    throw std::logic_error("Missing or extra bracket error");
  }
  if (inCpp) {
    throw std::logic_error("Extra $: Are all C++ statements closed?");
  }
  if (inString) {
    throw std::logic_error("Extra \": Are all strings closed?");
  }
}

void ParseTree::printTree() { blockTree->print(); }