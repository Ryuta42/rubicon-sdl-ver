#ifndef GUN_H
#define GUN_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "util.hpp"
#include "bullet.hpp"

class Gun
{
public:
    Gun();
    Gun(float interval, int bulletSpeed, std::string filePath, int bulletFrames, float bulletDamage, std::string soundPath);
    ~Gun();

    void shoot(int x, int y);
    void update();                          // update bullet positions
    void draw();                            // draw all active bullets
    void deactivate();

protected:
    int bulletSpeed;
    Mix_Chunk *bulletSound;
    float shotInterval;
    float cooldownLeft;
    std::vector<Bullet*> bullets;
    std::list<Bullet*> activeBullets;
    SDL_Texture *bulletTxtr;                // texture to be passed to bullets
    int bulletFrames;
    float bulletDamage;

friend class Stage;
friend class Player;
friend class CollisionHandler;
friend class PowerBar;
};

#endif // GUN_H
