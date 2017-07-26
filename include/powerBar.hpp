#ifndef POWERBAR_H
#define POWERBAR_H

#include <SDL.h>
#include <SDL_image.h>

#include "util.hpp"
#include "playerShip.hpp"
#include "score.hpp"

class PowerBar
{
public:
    PowerBar();
    virtual ~PowerBar();

    void update();
    void draw();

private:
    static int playerPower;
    SDL_Rect position;
    SDL_Rect cropRect;
    SDL_Texture *txtr;

    static void powerOn(PlayerShip *pShip);         // using rapid fire bar
    static void powerOff(PlayerShip *pShip);        // not using bar

friend class PlayerShip;
friend class Stage;
friend class Player;
};

#endif // POWERBAR_H
