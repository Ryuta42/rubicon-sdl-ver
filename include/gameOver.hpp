#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SDL.h>
#include <SDL_image.h>
#include <sstream>

#include "util.hpp"
#include "stateHandler.hpp"
#include "game_state.hpp"

class GameOver : public GameState
{
public:
    GameOver();
    ~GameOver();

    void handleEvents();
    void logic();
    void render();

private:
    SDL_Texture *txtr = nullptr;
    SDL_Color color;
    TTF_Font *font;

    long finalScore;
    std::stringstream scoreText;
    SDL_Texture *scoreTxtr = nullptr;
    SDL_Rect scorePos;

    int finalWave;
    std::stringstream waveText;
    SDL_Texture *waveTxtr = nullptr;
    SDL_Rect wavePos;
};

#endif // GAMEOVER_H
