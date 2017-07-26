#include "player.hpp"

#include <iostream>

#include "playerShip.hpp"
#include "stateHandler.hpp"

Player::Player()
{}
Player::Player(std::string filePath, int x, int y, int framesX, int framesY)
{
    up = down = left = right = rapidFiring = false;       // init logic

    pShip = new PlayerShip(x, y, 210, 55, 145, 20, 30, 30, filePath, 2, 1,
            800.0f, 250, .0625, 2000, "assets/pBullet.png", 1, 10.0f, "assets/pShot.wav");
}
Player::~Player()
{
    delete pShip;
    pShip = nullptr;
}
void Player::input()
{
    while( SDL_PollEvent( &ev ) )
    {
        if (ev.type == SDL_KEYDOWN)         // Key press
        {
            switch (ev.key.keysym.sym)
            {
                case SDLK_ESCAPE: StateHandler::setNextState (STATE_EXIT); break;
                case SDLK_w: up=true; break;
                case SDLK_s: down=true; break;
                case SDLK_a: left=true; break;
                case SDLK_d: right=true; break;
                case SDLK_j: StateHandler::setNextState(STATE_GAMEOVER); break;
                case SDLK_SPACE: rapidFiring = true; break;
            }
        }
        else if (ev.type == SDL_KEYUP)     // key release
        {
            switch (ev.key.keysym.sym)
            {
                case SDLK_w: up=false; break;
                case SDLK_s: down=false; break;
                case SDLK_a: left=false; break;
                case SDLK_d: right=false; break;
                case SDLK_SPACE: rapidFiring = false; break;
            }
        }
        else if (ev.type == SDL_QUIT)       // user X'd out window
            StateHandler::setNextState(STATE_EXIT);
    }
}
void Player::update(SDL_Rect bound)
{
    pShip->update(bound, up, down, left, right);

    if (rapidFiring)                        // holding down spacebar
        PowerBar::powerOn(pShip);
    else
        PowerBar::powerOff(pShip);
}
void Player::draw()
{
    pShip->draw();
}
