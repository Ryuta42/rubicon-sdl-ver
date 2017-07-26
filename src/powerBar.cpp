#include "powerBar.hpp"

PowerBar::PowerBar()
{
    playerPower = 250;                          // reset power
    txtr = IMG_LoadTexture(renderer, "assets/powerbar.png");
    SDL_QueryTexture(txtr, NULL, NULL, &cropRect.w, &cropRect.h);
    cropRect.x = cropRect.y = 0;
    position = {27, 63, cropRect.w, cropRect.h};
    position.w *= SCALE;                        // scale up sprite
    position.h *= SCALE;
}
PowerBar::~PowerBar()
{
    SDL_DestroyTexture(txtr);
    txtr = nullptr;
}
int PowerBar::playerPower = 250;                      // initialize bar value

void PowerBar::update()
{
    cropRect.w = (int)(9 * (playerPower/10.0f));      // update clip area
    position.w = cropRect.w * SCALE;
}
void PowerBar::draw()
{
    SDL_RenderCopy(renderer, txtr, &cropRect, &position);
}
void PowerBar::powerOn(PlayerShip *pShip)
{
    if (playerPower > 0)
    {
        playerPower--;
        Score::incScore(-2);
        pShip->gun->shotInterval = 0.0;
    }
    else
        pShip->gun->shotInterval = 0.0625;
}
void PowerBar::powerOff(PlayerShip *pShip)
{
    pShip->gun->shotInterval = 0.0625;
}
