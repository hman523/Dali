//
// Created by hunter on 6/10/19.
//

#include "ParseTree.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <stack>

/**
 * ParseTree Constructor
 * @pre none
 * @post Parse tree is made
 * @param filename : the file that is opened and read from
 */
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
  bool startOfLine = true;
  uint32_t linenumber = 1;
  while (file.get(curr)) {
    if (curr == '\n') {
      linenumber += 1;
    }

    if (curr == '$' && !inString && !inCpp) {
      inCpp = true;
      if (currentline != "") {

        throw std::logic_error("Cannot have c++ in a dali "
                               "expression. Error on line " +
                               std::to_string(linenumber));
      }
      currentline += "$";
    } else if (curr == '$' && !inString && inCpp) {
      currentline += "$";
      TreeNode *temp = new TreeNode(blocknest.top(), currentline);
      blockTree->addChild(temp);
      currentline = "";
      inCpp = false;
      startOfLine = true;
    } else if (curr == '"' && !inString && !inCpp) {
      inString = true;
      currentline += curr;

    } else if (curr == '"' && inString && !inCpp) {
      inString = false;
      currentline += curr;

    }

    else if (curr == '#' && !inCpp && !inString) {
      std::string lib = "";
      file.get(curr);
      while (curr != '\n') {
        if (curr != ' ') {
          lib += curr;
        }
        file.get(curr);
      }
      importList.push_back(lib);
      ++linenumber;
    }

    else if (curr == ';' && !inString && !inCpp) {
      TreeNode *temp = new TreeNode(blocknest.top(), currentline);
      blockTree->addChild(temp);
      currentline = "";
      startOfLine = true;
    } else if (curr == '{' && !inString && !inCpp) {
      TreeNode *temp = new TreeNode(blocknest.top(), currentline);
      blocknest.push(temp);
      blockTree->addChild(temp);
      currentline = "";
      startOfLine = true;
    } else if (curr == '}' && !inString && !inCpp) {
      blocknest.pop();
    } else if (startOfLine && (curr == ' ' || curr == '\n' || curr == '\t')) {
      // do nothing if whitespace at beginning of line
    } else {
      currentline += curr;
      startOfLine = false;
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

/**
 * printTree function
 * @pre Parse Tree is constructed
 * @post the tree is printed to terminal
 */
void ParseTree::printTree() {
  std::cout << "Imports:" << std::endl;
  for (uint32_t i = 0; i < importList.size(); ++i) {
    std::cout << "[" << importList[i] << "]" << std::endl;
  }
  blockTree->print();
}