#include "bullet.hpp"

#include <SDL.h>
#include <math.h>
#include <string>
#include <iostream>

#include "util.hpp"
#include "hitbox.hpp"

Bullet::Bullet()
{
    isActive = false;
}
Bullet::Bullet(int x, int y, SDL_Texture *txtr, int frames, float speed, float damage)
{
    this->damage = damage;

    this->txtr = txtr;
    SDL_QueryTexture(txtr, NULL, NULL, &cropRect.w, &cropRect.h);
    textureWidth = cropRect.w;
    cropRect.w /= frames;
    cropRect.y = 0;

    position.w = cropRect.w;
    position.h = cropRect.h;

    position.w *= SCALE;            // scale up sprite
    position.h *= SCALE;

    this->frames = frames;
    frameCounter = 0.0f;

    activate(x, y, speed);

    hitbox = HitBox(position.x, position.y, 0, 0, position.w, position.h);
}
Bullet::~Bullet()
{
    SDL_DestroyTexture(txtr);
    txtr = nullptr;
}
void Bullet::activate(int x, int y, float speed)
{
    cropRect.x = 0;
    position.x = x;
    position.y = gri(y-15, y+15);

    this->speed = speed;
    isActive = true;

    hitbox.updatePosition(position.x, position.y);
}
void Bullet::deactivate()
{
    isActive = false;
}
int Bullet::hit()
{
    isActive = false;
    return damage;
}
void Bullet::update()
{
    if (isActive)
    {
        // update position
        position.x += round(speed * timer.delta);
        hitbox.updatePosition(position.x, position.y);

        // update animation
        frameCounter += timer.delta;
        if (frameCounter >= 0.125f)
        {
            frameCounter = 0;
            cropRect.x += cropRect.w;
            if (cropRect.x >= textureWidth)
                cropRect.x = 0;
        }
    }
}
void Bullet::draw()
{
    SDL_RenderCopy(renderer, txtr, &cropRect, &position);

    //SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
    //SDL_RenderDrawRect(renderer, &position);
}
