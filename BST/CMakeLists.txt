cmake_minimum_required(VERSION 3.12)
project(BST)

set(CMAKE_CXX_STANDARD 11)

add_executable(BST main.cpp BSTNode.cpp BSTNode.h BST.cpp BST.h Node.h)