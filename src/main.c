#include "raylib.h"
#include "../include/game.h"
#include <stdlib.h>

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");
    SetTargetFPS(15);

    InitGame();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREEN_BACKGROUND);

        if (IsKeyPressed(KEY_P))
        {
            if (gameState == PLAYING)
                gameState = PAUSE;
            else if (gameState == PAUSE)
                gameState = PLAYING;
        }
        switch (gameState)
        {
        case PLAYING:
            UpdateGame();
            DrawGame();
            break;

        case PAUSE:
            DisplayMessage("Game is paused. Press P to unpause again!");
            break;
        case GAME_OVER:
            DisplayMessage("Game over. Press R to restart, Q to quit.)");
            if (IsKeyPressed(KEY_R))
            {
                InitGame();
                gameState = PLAYING;
            }

            else if (IsKeyPressed(KEY_Q))
            {
                CloseWindow();
                exit(0);
            }
        }

        EndDrawing();
    }

    return 0;
}
