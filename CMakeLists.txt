cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(kata)

# Dependencies
# easy instant unittest
include_directories(external/Catch2/single_include)

# Build
include_directories(include)
set(SOURCES src/traversal.cc src/path_finder.cc)
add_library(kata ${SOURCES})

# Test
