#include "drone.hpp"

Drone::Drone()
{}
Drone::Drone(int x, int y) :
        Drone(x, y, 0, 120, 20, 40, 100, 140, "assets/enemy_drone2.png", 1, 1, 500.0f,
        400, 0.10, 100, ENEMY_DRONE, 0.9, 100, -1000, "assets/eBullet2.png", 4, 30.0f, "assets/eShot.wav")
{}
Drone::Drone(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        std::string shipFilePath, int framesX, int framesY, float speed, int maxHealth, float dropRate,
        int value, int enemyID, float shotInterval, int shotSuccess, int bulletSpeed,
        std::string bulletFilePath, int bulletFrames, float bulletDamage, std::string soundFilePath) :
        Enemy(x, y, offsetX, offsetY, boxX, boxY, boxWidth, boxHeight, shipFilePath, framesX, framesY,
        speed, maxHealth, dropRate, value, enemyID, shotInterval, shotSuccess, bulletSpeed, bulletFilePath,
        bulletFrames, bulletDamage, soundFilePath)
{
    haltX = SCREEN_WIDTH - position.w - gri(10,300);
}
Drone::~Drone()
{
    SDL_DestroyTexture(txtr);

    delete gun;
    gun = nullptr;
}
