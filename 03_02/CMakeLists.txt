cmake_minimum_required(VERSION 3.16)
project(GeometryShapes VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(include)

# Main executable
add_executable(geometry
    src/main.cpp
    src/Circle.cpp
    src/Triangle.cpp
    src/Square.cpp
)

# ---- GTest ----
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(tests
    test/test_shapes.cpp
    src/Circle.cpp
    src/Triangle.cpp
    src/Square.cpp
)

target_link_libraries(tests PRIVATE GTest::gtest_main)
gtest_discover_tests(tests)

# Enable testing
enable_testing()