#include <SDL.h>
#include <string>

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "hud.hpp"
#include "util.hpp"

using namespace std;

class Background
{
public:
    Background();
    Background(string skyPath, string foregroundPath, HUD *hud);
    virtual ~Background();

    void update();
    void draw();

private:
    SDL_Rect skyPos;
    SDL_Rect skyCrop;
    SDL_Texture *skyTxtr = nullptr;

    SDL_Rect groundPos;
    SDL_Rect groundPos2;                // second rect for looping effect
    SDL_Rect groundCrop;
    SDL_Texture *groundTxtr = nullptr;

    float scrollSpeed;                  // speed that ground scrolls left
    float frameCounter;
};

#endif // BACKGROUND_H
