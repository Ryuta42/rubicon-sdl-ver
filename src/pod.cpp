#include "pod.hpp"

Pod::Pod()
{}
Pod::Pod(int x, int y) :
        Pod(x, y, 0, 40, 40, 0, 120, 70, "assets/enemy_pod2.png", 1, 1, 1200.0f,
        100, 0.05, 10, ENEMY_POD, 1.3, 10, -500, "assets/eBullet1.png", 4, 10.0f, "assets/eShot.wav")
{}
Pod::Pod(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        std::string shipFilePath, int framesX, int framesY, float speed, int maxHealth, float dropRate, int value, int enemyID,
        float shotInterval, int shotSuccess, int bulletSpeed, std::string bulletFilePath, int bulletFrames,
        float bulletDamage, std::string soundFilePath) :
        Enemy(x, y, offsetX, offsetY, boxX, boxY, boxWidth, boxHeight, shipFilePath, framesX, framesY,
        speed, maxHealth, dropRate, value, enemyID, shotInterval, shotSuccess, bulletSpeed, bulletFilePath, bulletFrames,
        bulletDamage, soundFilePath)
{}
Pod::~Pod()
{
    SDL_DestroyTexture(txtr);
    txtr = nullptr;

    delete gun;
    gun = nullptr;
}
