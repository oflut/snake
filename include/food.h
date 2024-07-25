#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"

typedef struct Food
{
    Vector2 position;
    Color color;

} Food;

void InitFood(Food *food);
void DrawFood(const Food *food);

#endif
