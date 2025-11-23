cmake_minimum_required(VERSION 3.16)
project(VectorDynamic VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

# Main executable
add_executable(vector_demo
    src/main.cpp
)

# GoogleTest
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(vector_tests
    test/test_vector.cpp
    include/Vector.hpp
)

target_include_directories(vector_tests PRIVATE include)
target_link_libraries(vector_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(vector_tests)

enable_testing()
