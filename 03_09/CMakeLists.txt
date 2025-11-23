cmake_minimum_required(VERSION 3.16)
project(IPv4Project VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

# Main executable
add_executable(ipv4_demo
    src/main.cpp
)

# GoogleTest
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(ipv4_tests
    test/test_ipv4.cpp
    include/IPv4.hpp
)

target_include_directories(ipv4_tests PRIVATE include)
target_link_libraries(ipv4_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(ipv4_tests)

enable_testing()
