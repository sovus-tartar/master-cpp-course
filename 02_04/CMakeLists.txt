cmake_minimum_required(VERSION 3.27)

# Project name and C++ standard
project(Armstrong LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Enable compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# List source files manually
set(SOURCES
    src/main.cpp
    src/armstrong.cpp
)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})