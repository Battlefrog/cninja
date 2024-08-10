#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

#define PLAYER_WIDTH 20.0f
#define PLAYER_HEIGHT 40.0f

typedef struct Player {
    //Animation anim;

    Texture2D texture;
    int frameWidth;
    int frameHeight;

    Rectangle sourceRec;
    Rectangle destRec;

    Vector2 position;
    Vector2 origin;
    int rotation;
} Player;

void InitPlayer(Player *player)
{
    player->position = (Vector2){180.0f, 130.0f};
    player->rotation = 0;

    player->texture = LoadTexture("resources/player/player_knife_idle.png");
    player->frameWidth = player->texture.width;
    player->frameHeight = player->texture.height;

    player->sourceRec = (Rectangle){0.0f, 0.0f, (float)player->frameWidth/20.0f, (float)player->frameHeight};
    player->destRec = (Rectangle){player->position.x, player->position.y, (float)player->frameWidth, (float)player->frameHeight};
    player->origin = (Vector2){(float)0.0f, (float)0.0f};
}

void UpdatePlayer(Player *player) 
{
    if (IsKeyDown(KEY_D)) player->position.x += 5;
    if (IsKeyDown(KEY_A)) player->position.x -= 5;
    if (IsKeyDown(KEY_W)) player->position.y -= 5;
    if (IsKeyDown(KEY_S)) player->position.y += 5;

    player->destRec = (Rectangle){player->position.x, player->position.y, (float)player->frameWidth/20.0f, (float)player->frameHeight};
    //player->rotation = (int)Vector2Angle(player->origin, GetMousePosition());
    //printf("%d\n", player->rotation);
}

void DrawPlayer(Player *player)
{
    DrawTexturePro(player->texture, player->sourceRec, player->destRec, player->origin, (float)player->rotation, WHITE);
}

void UnloadPlayer(Player *player)
{
    UnloadTexture(player->texture);
}

#endif