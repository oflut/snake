cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(SnakeGame VERSION 0.1)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable
add_executable(SNAKE src/main.c)

# Find the Raylib package
find_path(RL_INCLUDE_DIR NAMES raylib.h PATHS /opt/homebrew/opt/raylib/include)

# Include Raylib
include_directories(${RL_INCLUDE_DIR})

# Find the Raylib library
find_library(RL_LIBRARY NAMES raylib PATHS /opt/homebrew/opt/raylib/lib)

# Link Raylib
target_link_libraries(SNAKE ${RL_LIBRARY})