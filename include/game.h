#ifndef GAME_H
#define GAME_H

#include "../include/snake.h"

// Constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640
#define GRID_SIZE 20

// Variables
typedef enum GameState
{
    PLAYING = 0,
    PAUSE,
    GAME_OVER,
} GameState;

// Extern variables
extern GameState gameState;
extern const Rectangle gameBorder;
extern const Color GREEN_BACKGROUND;

// Functions
void InitGame();

void UpdateGame(void);
void DrawGame(void);

void DisplayMessage(const char *message);

void CheckCollisionWithSelf(Snake *snake);
void CheckCollisionWithWall(Snake *snake);
void CheckCollisionWithFruit();

#endif
