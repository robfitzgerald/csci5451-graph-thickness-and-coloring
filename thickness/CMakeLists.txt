cmake_minimum_required(VERSION 3.3)
project(thickness)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp AdjMatrix.cpp KGraph.h)
add_executable(thickness ${SOURCE_FILES})