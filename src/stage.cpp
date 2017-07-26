#include "stage.hpp"

Stage::Stage()
{
    // Create level
    hud = new HUD();
    background = new Background("assets/background.png", "assets/ground.png", hud);
    bound = {0, hud->position.h, SCREEN_WIDTH, SCREEN_HEIGHT - hud->position.h};

    // Create Player ship
    player = new Player("assets/pShip.png", 200, 400, 1, 1);

    // Start Enemy Spawning
    enemySpawner = new EnemySpawner(bound.y, SCREEN_HEIGHT-200);
}
Stage::~Stage()
{
    delete player;
    player = nullptr;
    delete hud;
    hud = nullptr;
    delete background;
    background = nullptr;
    delete enemySpawner;
    enemySpawner = nullptr;

}
void Stage::handleEvents()
{
    player->input();
}
void Stage::logic()
{
    background->update();
    player->update(bound);
    enemySpawner->update();
    handleCollisions();
    hud->update();

    if (HealthBar::getHealth() <= 0)            // if player loses
        StateHandler::setNextState(STATE_GAMEOVER);
}
void Stage::render()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);          // prepare renderer for next frame

    background->draw();
    player->draw();
    enemySpawner->draw();
    hud->draw();

    SDL_RenderPresent(renderer);        // Update screen
}
void Stage::handleCollisions()
{
    // player bullets against enemies
    CollisionHandler::handleEnemyCollisions(player->pShip->gun->activeBullets, enemySpawner->activeEnemies);

    // enemy bullets against player
    if (player->pShip->isActive)
        CollisionHandler::handlePlayerCollisions(enemySpawner->activeEnemies, player->pShip);
}
