#ifndef POD_H
#define POD_H

#include "enemy.hpp"

class Pod : public Enemy
{
public:
    Pod();
    Pod(int x, int y);
    ~Pod();

private:
    Pod(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        std::string shipFilePath, int framesX, int framesY, float speed, int maxHealth, float dropRate, int value, int cenemyID,
        float shotInterval, int shotSuccess, int bulletSpeed, std::string bulletFilePath, int bulletFrames,
        float bulletDamage, std::string soundFilePath);
};

#endif // POD_H
