#include "../include/food.h"
#include "../include/game.h"

void InitFood(Food *food)
{
    food->position.x = (GetRandomValue(gameBorder.x, SCREEN_WIDTH - gameBorder.x) / GRID_SIZE) * GRID_SIZE;
    food->position.y = (GetRandomValue(gameBorder.y, SCREEN_HEIGHT - gameBorder.y) / GRID_SIZE) * GRID_SIZE;
}

void DrawFood(const Food *food)
{
    DrawRectangleV(food->position, (Vector2){GRID_SIZE, GRID_SIZE}, RED);
}
