#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <SDL.h>
#include <SDL_image.h>

#include "util.hpp"

class HealthBar
{
public:
    HealthBar();
    virtual ~HealthBar();

    void update();
    void draw();

private:
    static int playerHealth;
    SDL_Rect position;
    SDL_Rect cropRect;
    SDL_Texture *txtr;

    static void updateHealth(int health);
    static int getHealth();

friend class PlayerShip;
friend class Stage;
};

#endif // HEALTHBAR_H
