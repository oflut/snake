cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(SnakeGame VERSION 0.1)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add optimization flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

# Define source files
set(SOURCE_FILES
    src/main.c
    src/game.c
    src/snake.c
    src/food.c
)

set(HEADER_FILES
    include/snake.h
    include/food.h
)

# macOS specific settings
if(APPLE)
    # Find the Raylib package
    find_path(RL_INCLUDE_DIR NAMES raylib.h PATHS /opt/homebrew/opt/raylib/include)
    find_library(RL_LIBRARY NAMES raylib PATHS /opt/homebrew/opt/raylib/lib)

    # Add the executable for macOS
    add_executable(SNAKE ${SOURCE_FILES} ${HEADER_FILES})

    # Include Raylib
    target_include_directories(SNAKE PRIVATE ${RL_INCLUDE_DIR})

    # Link Raylib
    target_link_libraries(SNAKE ${RL_LIBRARY})
endif()

# Windows specific settings
if(WIN32)
    # Raylib for Windows (assuming it's installed or will be fetched)
    find_package(raylib QUIET)
    
    if (NOT raylib_FOUND)
        include(FetchContent)
        FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/refs/tags/4.2.0.tar.gz
        )
        FetchContent_MakeAvailable(raylib)
    endif()

    # Add the executable for Windows
    add_executable(SNAKE_WIN ${SOURCE_FILES} ${HEADER_FILES})

    # Link Raylib for Windows
    target_link_libraries(SNAKE_WIN raylib)
endif()

# Include directories for both targets
include_directories(${CMAKE_SOURCE_DIR}/include)