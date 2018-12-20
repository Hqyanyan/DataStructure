cmake_minimum_required(VERSION 3.12)
project(Stack)

set(CMAKE_CXX_STANDARD 11)

add_executable(Stack main.cpp Stack.h Array_Stack.cpp Array_Stack.h Linked_Stack.cpp Linked_Stack.h)