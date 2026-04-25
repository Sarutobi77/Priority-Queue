cmake_minimum_required(VERSION 3.10)

# Name of your project
project(SimplifiedVectorLab)

# Require C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell the compiler where to look for header files
# This allows test.cpp to use: #include "array/vector.hpp"
include_directories(include)

# Create an executable named "run_tests" using your test file
add_executable(run_tests test.cpp)

enable_testing()
add_test(NAME my_test COMMAND my_test)