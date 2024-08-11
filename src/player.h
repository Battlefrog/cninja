#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

#define SCALE 4.0

typedef struct Player {
    //Animation anim;

    Texture2D texture;
    int frameWidth;
    int frameHeight;

    Rectangle sourceRec;
    Rectangle destRec;

    Vector2 position;
    Vector2 origin;
    float rotation;
} Player;

void InitPlayer(Player *player)
{
    player->position = (Vector2){180.0f, 130.0f};
    player->rotation = 0;

    player->texture = LoadTexture("resources/player/player.png");
    player->frameWidth = player->texture.width;
    player->frameHeight = player->texture.height;

    player->sourceRec = (Rectangle){0.0f, 0.0f, (float)player->frameWidth, (float)player->frameHeight};
    player->destRec = (Rectangle){player->position.x, player->position.y, (float)player->frameWidth*SCALE, (float)player->frameHeight*SCALE};
    //player->origin = Vector2Zero();
    player->origin = (Vector2){40.0f, 56.0f};
}

void UpdatePlayer(Player *player) 
{
    if (IsKeyDown(KEY_D)) player->position.x += 5;
    if (IsKeyDown(KEY_A)) player->position.x -= 5;
    if (IsKeyDown(KEY_W)) player->position.y -= 5;
    if (IsKeyDown(KEY_S)) player->position.y += 5;

    player->destRec = (Rectangle){player->position.x, player->position.y, (float)player->frameWidth*SCALE, (float)player->frameHeight*SCALE};
    
    float x = GetMouseX() - player->position.x;
    float y = GetMouseY() - player->position.y;
    player->rotation = (float)atan2(x, y) * -57.29578f; // https://stackoverflow.com/questions/74402587/point-texture-image-in-the-direction-of-the-cursor-in-raylib-c
}

void DrawPlayer(Player *player)
{
    DrawTexturePro(player->texture, player->sourceRec, player->destRec, player->origin, player->rotation + 90.0f, WHITE);
}

void UnloadPlayer(Player *player)
{
    UnloadTexture(player->texture);
}

#endif