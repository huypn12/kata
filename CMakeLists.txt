cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(kata)

# Dependencies
# easy instant unittest
include_directories(external/Catch2/single_include)

# Build
include_directories(include)
add_library(traversal src/traversal.cpp)
add_library(path_finder src/path_finder.cpp)

# Test
add_executable(test_traversal test/test_traversal.cpp)
target_link_libraries(test_traversal traversal)

add_executable(test_path_finder test/test_path_finder.cpp)
target_link_libraries(test_path_finder path_finder)
