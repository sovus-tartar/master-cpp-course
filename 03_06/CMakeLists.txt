cmake_minimum_required(VERSION 3.16)
project(GeometryHierarchy VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

# Main executable
add_executable(geometry_demo
    src/main.cpp
    src/Circle.cpp
    src/Triangle.cpp
    src/Rectangle.cpp
)

# GoogleTest
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(geometry_tests
    test/test_shapes.cpp
    src/Circle.cpp
    src/Triangle.cpp
    src/Rectangle.cpp
)

target_include_directories(geometry_tests PRIVATE include)
target_link_libraries(geometry_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(geometry_tests)

enable_testing()
