cmake_minimum_required(VERSION 3.16)
project(ListProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(include)

# Main executable
add_executable(list_demo
    src/main.cpp
    src/List.cpp
)

# ---- GTest ----
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(list_tests
    test/test_list.cpp
    src/List.cpp
)

target_include_directories(list_tests PRIVATE include)
target_link_libraries(list_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(list_tests)

enable_testing()
