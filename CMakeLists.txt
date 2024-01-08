cmake_minimum_required(VERSION 3.18...3.25)

project(
  jigraph
  VERSION ${PACKAGE_VERSION_BASE}
  DESCRIPTION "A library for creating and manipulating graphs"
  HOMEPAGE_URL https://igraph.org
  LANGUAGES C CXX
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(Misc)

option(ENABLE_TESTS "Enable tests" ON)

set(IGRAPH_INTEGER_SIZE 32)
add_subdirectory(vendor/igraph)
add_subdirectory(vendor/igraph-cpp)

execute_process(
  COMMAND git apply ${CMAKE_CURRENT_SOURCE_DIR}/cmake/igraph.patch
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/vendor/igraph
)

add_subdirectory(src)

if (ENABLE_TESTS)
  add_subdirectory(tests)
endif()
