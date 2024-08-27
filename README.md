# Snake
## A simple Snake game implemented in C using the Raylib library.
![](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExMWJuZG93NHluY2JoMnE3NnkxOWJudGIwNTN4MGczNGMwaHp2Y2o2ZiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/2g9ECqtjZYY44Uul3h/giphy.gif)

## Description

This is a classic Snake game where the player controls a snake that grows longer as it eats food. The game ends if the snake collides with itself.

## Features

- Simple and intuitive gameplay
- Increasing difficulty as the snake grows longer
- Score tracking
- Game over and restart functionality

## Getting Started

### Prerequisites

- CMake (version 3.10 or higher)
- C compiler (supporting C99 standard)
- Raylib library

### Installation

1. Clone the repository:
   ```
   git clone https://github.com/oflut/snake.git
   ```

2. Navigate to the project directory:
   ```
   cd snake
   ```

3. Create a build directory and navigate to it:
   ```
   mkdir build && cd build
   ```

4. Run CMake to configure the project:
   ```
   cmake ..
   ```

5. Build the project using CMake:
   ```
   cmake --build .
   ```

## Usage

After building, you can find the executable in the `build` directory. Run the game with:

```
./SNAKE
```

### Controls

- Use arrow keys to control the snake's direction
- Press 'P' to pause/unpause the game
- Press 'R' to restart the game when it's over
- Press 'Q' to quit the game when it's over
