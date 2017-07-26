#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <string>

#include "playerShip.hpp"

class Player
{
public:
    Player();
    Player(std::string filePath, int x, int y, int framesX, int framesY);
    ~Player();

    PlayerShip *pShip;

    void input();
    void update(SDL_Rect bound);
    void draw();

private:
    bool up, down, left, right;
    bool rapidFiring;                   // using rapid fire meter

friend class PowerBar;
};

#endif // PLAYER_H
