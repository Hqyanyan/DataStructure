cmake_minimum_required(VERSION 3.12)
project(Graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(Graph main.cpp Graph.h MatrixGraph.cpp MatrixGraph.h LinkedGraph.cpp LinkedGraph.h)