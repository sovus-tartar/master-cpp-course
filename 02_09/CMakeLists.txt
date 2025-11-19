cmake_minimum_required(VERSION 3.22)

# Project name and C++ standard
project(divisors LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Enable compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# List source files manually
set(SOURCES
    src/divisors.cpp
)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)

# Find GTest
find_package(GTest REQUIRED)

# Test executable
add_executable(my_tests test/test_divisors.cpp ${SOURCES})
target_include_directories(my_tests PRIVATE include)
target_link_libraries(my_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(my_tests)

# Enable testing
enable_testing()
