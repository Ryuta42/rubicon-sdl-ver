#ifndef DRONE_H
#define DRONE_H

#include "enemy.hpp"

class Drone : public Enemy
{
public:
    Drone();
    Drone(int x, int y);
    ~Drone();

private:
    Drone(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        std::string shipFilePath, int framesX, int framesY, float speed, int maxHealth, float dropRate, int value, int enemyID,
        float shotInterval, int shotSuccess, int bulletSpeed, std::string bulletFilePath, int bulletFrames,
        float bulletDamage, std::string soundFilePath);
};


#endif // DRONE_H
