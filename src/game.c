#include "raylib.h"
#include "../include/game.h"
#include "../include/snake.h"
#include "../include/food.h"

// Constant declarations
const Color GREEN_BACKGROUND = {148, 140, 60};
const Rectangle gameBorder = (Rectangle){SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8, SCREEN_WIDTH - SCREEN_WIDTH / 4, SCREEN_HEIGHT - SCREEN_HEIGHT / 4};

// Struct declarations
static Snake snake[MAX_SNAKE_LENGTH] = {0};
static Food food = {0};

// Initial values
static bool allowMove;
int length;
int framesCounter;

GameState gameState = PLAYING;

void InitGame()
{
    allowMove = true;
    length = 1;
    framesCounter = 0;

    gameState = PLAYING;

    InitSnake(snake);
    InitFood(&food);
}

void UpdateGame(void)
{

    if (gameState != GAME_OVER)
    {
        if (IsKeyPressed(KEY_RIGHT) && snake->direction.x == 0 && allowMove)
        {
            snake->direction = (Vector2){GRID_SIZE, 0};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_LEFT) && snake->direction.x == 0 && allowMove)
        {
            snake->direction = (Vector2){-GRID_SIZE, 0};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_UP) && snake->direction.y == 0 && allowMove)
        {
            snake->direction = (Vector2){0, -GRID_SIZE};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_DOWN) && snake->direction.y == 0 && allowMove)
        {
            snake->direction = (Vector2){0, GRID_SIZE};
            allowMove = false;
        }

        UpdateSnake(snake, length);

        CheckCollisionWithWall(snake);
        CheckCollisionWithFruit();
        CheckCollisionWithSelf(snake);

        allowMove = true;
        framesCounter++;
    };
}

void DrawGame(void)
{
    DrawRectangleLinesEx(gameBorder, 4, BLACK);
    for (int x = SCREEN_WIDTH / 8; x <= SCREEN_WIDTH - SCREEN_WIDTH / 8; x += GRID_SIZE)
    {
        DrawLine(x, SCREEN_HEIGHT / 8, x, SCREEN_HEIGHT - SCREEN_HEIGHT / 8, DARKGRAY);
    }
    for (int y = SCREEN_HEIGHT / 8; y <= SCREEN_HEIGHT - SCREEN_HEIGHT / 8; y += GRID_SIZE)
    {
        DrawLine(SCREEN_WIDTH / 8, y, SCREEN_WIDTH - SCREEN_WIDTH / 8, y, DARKGRAY);
    }

    DrawSnake(snake, length);
    DrawFood(&food);
    DrawText(TextFormat("Score: %i ", length - 1, framesCounter), gameBorder.x, (SCREEN_HEIGHT - gameBorder.y) + 10, 20, LIGHTGRAY);
}

void DisplayMessage(const char *message)
{
    int textWidth = MeasureText(message, 20);

    int textX = (SCREEN_WIDTH / 2) - (textWidth / 2);
    int textY = (SCREEN_HEIGHT / 2) - (20 / 2);

    DrawText(message, textX, textY, 20, LIGHTGRAY);
}

void CheckCollisionWithFruit()
{
    Rectangle snakeRect = {snake[0].position.x, snake[0].position.y, GRID_SIZE, GRID_SIZE};
    Rectangle foodRect = {food.position.x, food.position.y, GRID_SIZE, GRID_SIZE};

    if (CheckCollisionRecs(snakeRect, foodRect))
    {
        GrowSnake(snake, &length);
        InitFood(&food);
    }
}

void CheckCollisionWithWall(Snake *snake)
{
    if (snake[0].position.x >= SCREEN_WIDTH - gameBorder.x)
        snake[0].position.x = gameBorder.x;
    if (snake[0].position.x < gameBorder.x)
        snake[0].position.x += gameBorder.width;
    if (snake[0].position.y >= SCREEN_HEIGHT - gameBorder.y)
        snake[0].position.y = gameBorder.y;
    if (snake[0].position.y < gameBorder.y)
        snake[0].position.y += gameBorder.height;
}

void CheckCollisionWithSelf(Snake *snake)
{
    for (int i = 3; i < length; i++)
    {
        if ((snake[0].position.x == snake[i].position.x) && (snake[0].position.y == snake[i].position.y))
        {
            gameState = GAME_OVER;
        }
    }
}
