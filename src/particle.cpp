#include "particle.hpp"

Particle::Particle()
{
    isActive = false;
}
Particle::Particle(int x, int y, float speed, SDL_Texture *txtr)
{
    this->speed = speed;
    this->txtr = txtr;

    frameCounter = 0.0f;

    activate(x, y);
}
Particle::~Particle()
{
    SDL_DestroyTexture(txtr);
    txtr = nullptr;
}
void Particle::activate(int x, int y)
{
    cropRect = {0, 0, 1, 1};                // reset clip area

    position.x = x;
    position.y = gri(y-10, y+10);           // randomness for additional juice
    position.w = position.h = gri(1,8) * 2;
    speed = gri(1400, 2000);

    isActive = true;
}
void Particle::update()
{
    if (isActive)
    {
        position.x -= round(speed * timer.delta);

        if (position.x < 0)                 // if bullet goes off screen
            isActive = false;

        frameCounter += timer.delta;
        if (frameCounter >= 0.015f)         // advance animation
        {
            frameCounter = 0;
            cropRect.y ++;
            if (cropRect.y >= 10)
                isActive = false;
        }
    }
}
void Particle::draw()
{
    if (isActive)
        SDL_RenderCopy(renderer, txtr, &cropRect, &position);
}
