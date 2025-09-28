cmake_minimum_required(VERSION 3.27)

# Project name and C++ standard
project(Kvadratka LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# List source files manually
set(SOURCES
    src/main.cpp
    src/solver.cpp
)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})