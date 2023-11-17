cmake_minimum_required(VERSION 3.18...3.25)

project(
  jigraph
  VERSION ${PACKAGE_VERSION_BASE}
  DESCRIPTION "A library for creating and manipulating graphs"
  HOMEPAGE_URL https://igraph.org
  LANGUAGES C CXX
)

set(IGRAPH_INTEGER_SIZE 32)
add_subdirectory(vendor/igraph)

add_subdirectory(src)
