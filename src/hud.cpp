#include "hud.hpp"

HUD::HUD()
{
    txtr = IMG_LoadTexture(renderer, "assets/hud.png");
    SDL_QueryTexture(txtr, NULL, NULL, &cropRect.w, &cropRect.h);

    position.x = cropRect.x = 0;
    position.y = cropRect.y = 0;

    position.w = cropRect.w * SCALE;
    position.h = cropRect.h * SCALE;

    healthbar = new HealthBar();
    powerbar = new PowerBar();
    score = new Score();
}
HUD::~HUD()
{
    SDL_DestroyTexture(txtr);

    delete healthbar;
    healthbar = nullptr;

    delete score;
    score = nullptr;
}
void HUD::update()
{
    healthbar->update();
    powerbar->update();
    score->update();
}
void HUD::draw()
{
    SDL_RenderCopy(renderer, txtr, NULL, &position);

    healthbar->draw();
    powerbar->draw();
    score->draw();
}
