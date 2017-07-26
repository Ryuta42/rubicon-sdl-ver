#ifndef MAINMENU_H
#define MAINMENU_H

#include <SDL.h>
#include <SDL_image.h>

#include "util.hpp"
#include "stateHandler.hpp"
#include "game_state.hpp"

class MainMenu : public GameState
{
public:
    MainMenu();
    ~MainMenu();

    void handleEvents();
    void logic();
    void render();

private:
    SDL_Texture *txtr;
};

#endif // MAINMENU_H
