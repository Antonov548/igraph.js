cmake_minimum_required(VERSION 3.18)

add_library(igraph-cpp INTERFACE)

target_include_directories(igraph-cpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
