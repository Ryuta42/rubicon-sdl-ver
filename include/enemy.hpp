#ifndef ENEMY_H
#define ENEMY_H

#include <SDL.h>
#include <string>
#include <math.h>
#include <iostream>

#include "util.hpp"
#include "ship.hpp"
#include "score.hpp"

class Enemy : public Ship
{
public:
    Enemy();
    Enemy(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        std::string shipFilePath, int framesX, int framesY, float speed, int maxHealth, float dropRate,
        int value, int enemyID, float shotInterval, int shotSuccess,int bulletSpeed,
        std::string bulletFilePath, int bulletFrames, float bulletDamage, std::string soundFilePath);
    virtual ~Enemy();

    int enemyID;                            // identifies enemy

    void update();
    void activate(int x, int y);
    void deactivate();

protected:
    int shotSuccess;                        // chance to shoot
    int haltX;                              // x position enemy stops at
    float dropRate;
    int value;                              // score value upon defeat

    int moveState;                          // status of movement
    float cooldown;                         // time before moveState has chance to change
};

#endif // ENEMY_H
