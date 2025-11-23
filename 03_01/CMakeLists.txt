cmake_minimum_required(VERSION 3.22)

project(rectangle LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/rectangle.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)

# GoogleTest
find_package(GTest REQUIRED)

add_executable(rectangle_tests test/test_rectangle.cpp ${SOURCES})
target_include_directories(rectangle_tests PRIVATE include)
target_link_libraries(rectangle_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(rectangle_tests)

enable_testing()
