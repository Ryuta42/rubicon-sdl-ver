#include "healthBar.hpp"

HealthBar::HealthBar()
{
    playerHealth = 250;                         // reset health
    txtr = IMG_LoadTexture(renderer, "assets/healthbar.png");
    SDL_QueryTexture(txtr, NULL, NULL, &cropRect.w, &cropRect.h);
    cropRect.x = cropRect.y = 0;
    position = {27, 23, cropRect.w, cropRect.h};
    position.w *= SCALE;                        // scale up sprite
    position.h *= SCALE;
}
HealthBar::~HealthBar()
{
    SDL_DestroyTexture(txtr);
    txtr = nullptr;
}
int HealthBar::playerHealth = 250;

void HealthBar::update()
{
    cropRect.w = (9 * (playerHealth/10));      // update clip area
    position.w = cropRect.w * SCALE;
}
void HealthBar::draw()
{
    SDL_RenderCopy(renderer, txtr, &cropRect, &position);
}
void HealthBar::updateHealth(int health)
{
    playerHealth = health;
}
int HealthBar::getHealth()
{
    return playerHealth;
}
