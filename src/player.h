#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

#define SCALE 4.0
#define MOVE_SPEED 5.0

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
    player->origin = (Vector2){40.0f, 56.0f};
}

void UpdatePlayer(Player *player) 
{
    // Player Mouse Rotation
    float x = GetMouseX() - player->position.x;
    float y = GetMouseY() - player->position.y;
    player->rotation = (float)atan2(x, y) * -57.29578f; // https://stackoverflow.com/questions/74402587/point-texture-image-in-the-direction-of-the-cursor-in-raylib-c

    Vector2 rotationVector = {x, y};
    Vector2 movementVector = Vector2Normalize(Vector2MoveTowards(player->position, rotationVector, 1000.0f));
    movementVector = Vector2Scale(movementVector, MOVE_SPEED);

    printf("(%f, %f)\n", movementVector.x, movementVector.y);
    
    if (IsKeyDown(KEY_W))
    {
        player->position = Vector2Add(player->position, movementVector);
    }
    else if (IsKeyDown(KEY_S))
    {
        player->position = Vector2Subtract(player->position, movementVector);
    }
    else if (IsKeyDown(KEY_A))
    {
        player->position = Vector2Add(player->position, Vector2Reflect(movementVector, (Vector2){0.0f, -1.0f}));
    }
    else if (IsKeyDown(KEY_D))
    {
        player->position = Vector2Subtract(player->position, Vector2Reflect(movementVector, (Vector2){0.0f, 1.0f}));
    }

    player->destRec = (Rectangle){player->position.x, player->position.y, (float)player->frameWidth*SCALE, (float)player->frameHeight*SCALE};
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