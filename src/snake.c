#include "raylib.h"
#include "../include/game.h"
#include "../include/food.h"
#include "../include/snake.h"

void InitSnake(Snake *snake)
{
    snake->position = (Vector2){gameBorder.x + GRID_SIZE, gameBorder.y + GRID_SIZE};
    snake->direction = (Vector2){GRID_SIZE, 0};
    snake->color = BLACK;
}

void DrawSnake(Snake *snake, int length)
{
    for (int i = 0; i < length; i++)
    {
        Rectangle r = (Rectangle){snake[i].position.x, snake[i].position.y, GRID_SIZE, GRID_SIZE};
        DrawRectangleRounded(r, 0.4, 4, snake->color);
    }
}

void UpdateSnake(Snake *snake, int length)
{
    for (int i = length - 1; i > 0; --i)
    {
        snake[i].position = snake[i - 1].position;
    }
    snake[0].position.y += snake->direction.y;
    snake[0].position.x += snake->direction.x;
}

void GrowSnake(Snake *snake, int *length)
{
    if (*length < MAX_SNAKE_LENGTH)

    {
        Vector2 newSegmentPosition = snake[*length - 1].position;
        snake[*length].position = newSegmentPosition;

        ++(*length);
    }
}
