cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(SnakeGame VERSION 0.1)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add optimization flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

# Add the executable
add_executable(SNAKE 
    src/main.c
    src/game.c
    src/snake.c
    src/food.c
    
    include/snake.h
    include/food.h
    )

# Find the Raylib package
find_path(RL_INCLUDE_DIR NAMES raylib.h PATHS /opt/homebrew/opt/raylib/include)

# Include Raylib
include_directories(${RL_INCLUDE_DIR})

# Find the Raylib library
find_library(RL_LIBRARY NAMES raylib PATHS /opt/homebrew/opt/raylib/lib)

# Link Raylib
target_link_libraries(SNAKE ${RL_LIBRARY})