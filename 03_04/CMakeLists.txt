cmake_minimum_required(VERSION 3.16)
project(EntityTest VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

# Main executable
add_executable(entity_demo
    src/main.cpp
    src/Entity.cpp
)

# GoogleTest
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(entity_tests
    test/test_entity.cpp
    src/Entity.cpp
)

target_include_directories(entity_tests PRIVATE include)
target_link_libraries(entity_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(entity_tests)

enable_testing()
