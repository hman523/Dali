cmake_minimum_required (VERSION 3.10.2)
project (DaliC)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")
add_executable (dalic main.cpp ParseTree.cpp ParseTree.h TreeNode.cpp TreeNode.h CodeGenerator.cpp CodeGenerator.h)
