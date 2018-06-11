cmake_minimum_required (VERSION 2.6)

SET(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")


project (EditDistance)

add_executable(EditDistance main.cc)
