#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE_LENGTH 256

#include "raylib.h"

typedef struct Snake
{
    Vector2 position;
    Vector2 direction;
    Color color;

} Snake;

void InitSnake(Snake *snake);
void DrawSnake(Snake *snake, int length);
void UpdateSnake(Snake *snake, int length);
void GrowSnake(Snake *snake, int *length);

#endif
