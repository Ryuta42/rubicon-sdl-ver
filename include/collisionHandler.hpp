#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <SDL.h>
#include <list>
#include <list>

#include "bullet.hpp"
#include "enemy.hpp"
#include "playerShip.hpp"

class CollisionHandler
{
public:
    static bool collision (SDL_Rect A, SDL_Rect B);
    static void handleBiCollision(Bullet *hb1, PlayerShip *hb2);
    static void handleBiCollision(Bullet *hb1, Enemy *hb2);
    static void handleEnemyCollisions(std::list<Bullet*> bulets, std::list<Enemy*> enemies);
    static void handlePlayerCollisions(std::list<Enemy*> enemies, PlayerShip* player);
};

#endif // COLLISIONHANDLER_H
