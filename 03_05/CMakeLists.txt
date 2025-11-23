cmake_minimum_required(VERSION 3.16)
project(ClientAdapter VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

# Main executable
add_executable(client_demo
    src/main.cpp
    src/Client.cpp
)

# GoogleTest
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(client_tests
    test/test_client.cpp
    src/Client.cpp
)

target_include_directories(client_tests PRIVATE include)
target_link_libraries(client_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(client_tests)

enable_testing()
