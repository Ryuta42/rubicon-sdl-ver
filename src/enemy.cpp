#include "enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        std::string shipFilePath, int framesX, int framesY, float speed, int maxHealth, float dropRate,
        int value, int enemyID, float shotInterval, int shotSuccess,
        int bulletSpeed, std::string bulletFilePath, int bulletFrames, float bulletDamage, std::string soundFilePath)
        : Ship(x, y, offsetX, offsetY, boxX, boxY, boxWidth, boxHeight, shipFilePath, framesX, framesY,
        speed, maxHealth, shotInterval, bulletSpeed, bulletFilePath, bulletFrames,
        bulletDamage, soundFilePath)
{
    haltX = gri(SCREEN_WIDTH / 3, (int) SCREEN_WIDTH*(7/9.0));
    this->dropRate = dropRate;
    this->value = value;
    this->enemyID = enemyID;
    this->shotSuccess = shotSuccess;

    moveState = MOVE_SPAWNING;
    cooldown = 2.0f;
}
Enemy::~Enemy()
{
    SDL_DestroyTexture(txtr);

    delete gun;
    gun = nullptr;
}
void Enemy::update()
{
    if (isActive)
    {
        if (position.x>haltX)
            position.x -= round(speed * timer.delta);       // move forward

        else if (gri(1,100) <= shotSuccess)
            shoot();

        cooldown -= timer.delta;
        if (cooldown <= 0.0f)                           // chance to change moveState
        {
            cooldown = 2.0;
            int i = gri(0,5);
            if (i==0)
                moveState = MOVE_UP;
            else if (i==1)
                moveState = MOVE_DOWN;
            else
                moveState = MOVE_NEUTRAL;
        }

        switch (moveState)
        {
            case MOVE_SPAWNING:
                moveState = MOVE_NEUTRAL;
                break;
            case MOVE_UP:
                if (position.y > 175)
                    position.y -= 2;                    // strafe up
                else
                    moveState = MOVE_DOWN;              // strafe down if top bound hit
                break;

            case MOVE_DOWN:
                if (position.y + position.h < SCREEN_HEIGHT-25)
                    position.y += 2;                    // strafe down
                else
                    moveState = MOVE_UP;                // strafe up if bottom bound hit
                break;
        }

        gun->update();
        hitbox.updatePosition(position.x, position.y);
    }
}
void Enemy::activate(int x, int y)
{
    position.x = x;
    position.y = y;
    health = maxHealth;
    isActive = true;
    moveState = MOVE_SPAWNING;
}
void Enemy::deactivate()
{
    Score::incScore(value);
    isActive = false;
    gun->deactivate();
}
