#include "raylib.h"

int main(){

    const int screenWidth=800;
    const int screenHeight=600;

    InitWindow(screenWidth, screenHeight, "Snake - Games in C++");

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("SNAKE", 330, 200, 50, DARKGREEN);
        DrawText("Game scaffold is ready", 270, 280, 25, DARKGRAY);
        DrawText("Press ESC to close", 300, 350, 20, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
