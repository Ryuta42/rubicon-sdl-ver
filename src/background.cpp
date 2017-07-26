#include "background.hpp"

using namespace std;

Background::Background(){}
Background::Background(string skyPath, string foregroundPath, HUD *hud)
{
    scrollSpeed = 60;

    skyCrop.x = skyCrop.y = groundCrop.x = groundCrop.y = 0;

    // init sky
    skyTxtr = IMG_LoadTexture(renderer, skyPath.c_str());
    SDL_QueryTexture(skyTxtr, NULL, NULL, &skyCrop.w, &skyCrop.h);
    skyPos.x = 0;
    skyPos.y = hud->position.h;
    skyPos.w = skyCrop.w * SCALE;
    skyPos.h = skyCrop.h * SCALE;

    // init ground
    groundTxtr = IMG_LoadTexture(renderer, foregroundPath.c_str());
    SDL_QueryTexture(groundTxtr, NULL, NULL, &groundCrop.w, &groundCrop.h);
    groundPos.w = groundPos2.w = groundCrop.w * SCALE;
    groundPos.h = groundPos2.h = groundCrop.h * SCALE;
    groundPos.x = 0;
    groundPos2.x = groundPos.w;
    groundPos.y = groundPos2.y = SCREEN_HEIGHT - groundPos.h;
}
Background::~Background()
{
    SDL_DestroyTexture(skyTxtr);
    skyTxtr = nullptr;

    SDL_DestroyTexture(groundTxtr);
    groundTxtr = nullptr;
}
void Background::update()
{
    groundPos.x -= scrollSpeed;
    groundPos2.x -= scrollSpeed;
    if (groundPos.x+groundPos.w < 0)                // if first rect goes off screen
        groundPos.x = groundPos2.x+groundPos2.w;
    else if (groundPos2.x+groundPos2.w < 0)              // if second goes off screen
        groundPos2.x = groundPos.x+groundPos.w;
}
void Background::draw()
{
    SDL_RenderCopy(renderer, skyTxtr, &skyCrop, &skyPos);
    SDL_RenderCopy(renderer, groundTxtr, &groundCrop, &groundPos);
    SDL_RenderCopy(renderer, groundTxtr, &groundCrop, &groundPos2);
}
