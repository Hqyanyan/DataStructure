cmake_minimum_required(VERSION 3.10)
project(List)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        List main.cpp List.h
        Array_List.h Array_List.cpp
        Linked_List.h Linked_List.cpp)