#include "collisionHandler.hpp"

using namespace std;

bool CollisionHandler::collision (SDL_Rect A, SDL_Rect B)
{
    return ( (A.x+A.w >= B.x)&&(A.x <= B.x+B.w) ) && ( (A.y+A.h >= B.y)&&(A.y <= B.y+B.h) );
}
void CollisionHandler::handleBiCollision(Bullet *hb1, PlayerShip *hb2)
{
    if (hb1->hitbox.overlaps(hb2->hitbox))        // if boxes collide, hit both objects
        hb2->hit(hb1->hit());
}
void CollisionHandler::handleBiCollision(Bullet *hb1, Enemy *hb2)
{
    if (hb1->hitbox.overlaps(hb2->hitbox))        // if boxes collide, hit both objects
        hb2->hit(hb1->hit());
}
void CollisionHandler::handleEnemyCollisions(list<Bullet*> bullets, list<Enemy*> enemies)
{
    for (list<Bullet*>::iterator b = bullets.begin(); b != bullets.end(); ++b)      // loop through player bullets
        for (list<Enemy*>::iterator e = enemies.begin(); e != enemies.end(); ++e)   // loop through active enemies
            handleBiCollision(*b, *e);
}
void CollisionHandler::handlePlayerCollisions(std::list<Enemy*> enemies, PlayerShip* player)
{
    for (list<Enemy*>::iterator e = enemies.begin(); e != enemies.end(); ++e)       // loop through active enemies
        for (list<Bullet*>::iterator eb = (*e)->gun->activeBullets.begin(); eb != (*e)->gun->activeBullets.end(); ++eb)   // loop through enemy's bullets
            handleBiCollision(*eb, player);
}
