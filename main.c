#include "include/raylib.h"
#include <stdio.h>

int main(void)
{

    const int screenWidth = 600;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Bouncing DVD");
    SetWindowIcon(LoadImage("files/icon.png"));

    Texture2D a[7];

    Image dvdimage1 = LoadImage("files/1.png");
    a[0] = LoadTextureFromImage(dvdimage1);
    UnloadImage(dvdimage1);

    Image dvdimage2 = LoadImage("files/2.png");
    a[1] = LoadTextureFromImage(dvdimage2);
    UnloadImage(dvdimage2);

    Image dvdimage3 = LoadImage("files/3.png");
    a[2] = LoadTextureFromImage(dvdimage3);
    UnloadImage(dvdimage3);

    Image dvdimage4 = LoadImage("files/4.png");
    a[3] = LoadTextureFromImage(dvdimage4);
    UnloadImage(dvdimage4);

    Image dvdimage5 = LoadImage("files/5.png");
    a[4] = LoadTextureFromImage(dvdimage5);
    UnloadImage(dvdimage5);

    Image dvdimage6 = LoadImage("files/6.png");
    a[5] = LoadTextureFromImage(dvdimage6);
    UnloadImage(dvdimage6);

    Image dvdimage7 = LoadImage("files/7.png");
    a[6] = LoadTextureFromImage(dvdimage7);
    UnloadImage(dvdimage7);

    Vector2 dvdPosition = {GetScreenWidth() / 2 - dvdimage1.width / 2, GetScreenHeight() / 2 - dvdimage1.height / 2};
    Vector2 dvdSpeed = {1.5f, 1.0f};

    int test = 0;
    bool pause = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE)) pause = !pause;


        if (!pause)
        {

        dvdPosition.x += dvdSpeed.x;
        dvdPosition.y += dvdSpeed.y;

        if ((dvdPosition.x >= (GetScreenWidth() - dvdimage1.width)) || (dvdPosition.x <= 0))
        {
            dvdSpeed.x *= -1.0f;
            test++;
        }
        if ((dvdPosition.y >= (GetScreenHeight() - dvdimage1.height)) || (dvdPosition.y <= 0))
        {
            dvdSpeed.y *= -1.0f;
            test++;
        }
        if (test > 6) test = 0;

        }

        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawTexture(a[test], dvdPosition.x, dvdPosition.y, WHITE);
        }
        EndDrawing();
    }

    
    for(int i = 0; i < 7; i++)
    {
        UnloadTexture(a[i]); 
    }
    CloseWindow();
    return 0;
}