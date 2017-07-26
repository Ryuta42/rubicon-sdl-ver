#include "mainMenu.hpp"

MainMenu::MainMenu()
{
    txtr = IMG_LoadTexture(renderer, "assets/main_menu.png");
    log("Main Menu constructed");
}
MainMenu::~MainMenu()
{
    log("Main Menu destructed");
    SDL_DestroyTexture(txtr);
}
void MainMenu::handleEvents()
{
    while( SDL_PollEvent( &ev ) )
    {
        if (ev.type == SDL_KEYDOWN)         // Key press
        {
            switch (ev.key.keysym.sym)
            {
                case SDLK_ESCAPE: StateHandler::setNextState(STATE_EXIT); break;
                case SDLK_RETURN: StateHandler::setNextState(STATE_GAME); break;
            }
        }
    }
}
void MainMenu::logic()
{

}
void MainMenu::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, txtr, NULL, NULL);
    SDL_RenderPresent(renderer);
}
