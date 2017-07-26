#ifndef HUD_H
#define HUD_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "util.hpp"
#include "healthBar.hpp"
#include "powerBar.hpp"

class HUD
{
public:
    HUD();
    HUD(SDL_Renderer *renderer, std::string filePath);
    virtual ~HUD();

    void update();
    void draw();

private:
    SDL_Rect cropRect;
    SDL_Rect position;
    SDL_Texture *txtr;

    HealthBar *healthbar = nullptr;
    PowerBar *powerbar = nullptr;
    Score *score = nullptr;

friend class Stage;
friend class Background;
};

#endif // HUD_H
