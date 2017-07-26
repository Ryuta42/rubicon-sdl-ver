#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_ttf.h>

#include "util.hpp"

class Score
{
public:
    Score();
    virtual ~Score();

    void update();
    void draw();

    static void incScore(int amount);
    void resetScore();

private:
    static long scoreVal;
    std::stringstream scoreText;
    std::stringstream waveText;
    SDL_Texture *scoreTxtr = nullptr;
    SDL_Texture *waveTxtr = nullptr;
    SDL_Color color;
    SDL_Rect scorePos;
    SDL_Rect wavePos;
    TTF_Font *font;

friend class Enemy;
friend class GameOver;
};

#endif // SCORE_H
