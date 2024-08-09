/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
Player player;
Texture2D backgroundTexture;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    InitPlayer(&player);

    Image img = GenImageChecked(64, 64, 32, 32, BROWN, RAYWHITE);
    backgroundTexture = LoadTextureFromImage(img);
    UnloadImage(img);
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    UpdatePlayer(&player);
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // Draw the tile background
    DrawTextureRec(backgroundTexture, (Rectangle){ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() }, Vector2Zero(), WHITE);
    DrawPlayer(&player);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    UnloadPlayer(&player);
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return -1;
}