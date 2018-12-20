cmake_minimum_required(VERSION 3.12)
project(Queue)

set(CMAKE_CXX_STANDARD 11)

add_executable(Queue main.cpp Queue.h Array_Queue.cpp Array_Queue.h Linked_Queue.cpp Linked_Queue.h)