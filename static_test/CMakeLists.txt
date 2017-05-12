cmake_minimum_required(VERSION 3.5)
project(static_test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp file1.c file1.h)
add_executable(static_test ${SOURCE_FILES})