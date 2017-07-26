#ifndef STAGE_H
#define STAGE_H

#include <SDL.h>
#include <iostream>

#include "hud.hpp"
#include "background.hpp"
#include "player.hpp"
#include "enemySpawner.hpp"
#include "collisionHandler.hpp"
#include "stateHandler.hpp"
#include "game_state.hpp"

class Stage : public GameState
{
public:
    Stage();
    virtual ~Stage();

    void handleEvents();
    void logic();
    void render();

private:
    Background *background = nullptr;
    Player *player = nullptr;
    HUD *hud = nullptr;
    EnemySpawner *enemySpawner = nullptr;
    SDL_Rect bound;

    void handleCollisions();
};

#endif // STAGE_H
