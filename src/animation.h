#ifndef ANIMATION_H
#define ANIMATION_H

#include "raylib.h"

typedef struct Animation {
    int frame;
    int frameCounter;
    int endFrame;
    int frameSpeed;
    int textureWidth;
} Animation;

void InitAnimation(Animation *anim, int speed, int end, int width)
{
    anim->frame = 0;
    anim->frameCounter = 0;
    anim->frameSpeed = speed;
    anim->endFrame = end;
    anim->textureWidth = width;
}

void UpdateAnimation(Animation *anim, Rectangle* sourceRec)
{
    anim->frameCounter++;
    if (anim->frameCounter >= (60/anim->frameSpeed))
    {
        anim->frameCounter = 0;
        anim->frame++;

        if (anim->frame > anim->endFrame - 1) anim->frame = 0;

        sourceRec->x = (float)anim->frame*(float)anim->textureWidth/anim->endFrame;
    }
}

#endif