#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL.h>
#include <math.h>
#include <iostream>

#include "util.hpp"

class Particle
{
public:
    Particle();
    Particle(int x, int y, float speed, SDL_Texture *txtr);
    ~Particle();

    void activate(int x, int y);
    void update();
    void draw();

private:
    bool isActive;
    float frameCounter;
    SDL_Rect position;
    SDL_Rect cropRect;
    SDL_Texture *txtr;
    float speed;
    int txtrSize;

friend class PlayerShip;
};

#endif // PARTICLE_H
