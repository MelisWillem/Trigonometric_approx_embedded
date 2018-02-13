cmake_minimum_required (VERSION 2.6)
project (npmc C)

# set the compiler with its flags
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_BUILD_TYPE Debug)

add_definitions(-Wall)
add_definitions(-Wextra)

# subdirectories with libraries
include_directories ("${PROJECT_SOURCE_DIR}/src")
add_subdirectory (src) # read out the cmakelist file

# Test the functionality
enable_testing()
add_subdirectory(src_test)

# Tests on the matrix/vector operations
add_test(NAME simple_test COMMAND  src_test/simple_test.out)
