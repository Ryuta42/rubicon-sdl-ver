#include "gun.hpp"

using namespace std;

Gun::Gun()
{}
Gun::Gun(float shotInterval, int bulletSpeed, std::string filePath, int bulletFrames, float bulletDamage, std::string soundPath)
{
    this->shotInterval = shotInterval;
    this->bulletSpeed = bulletSpeed;
    this->bulletFrames = bulletFrames;
    this->bulletDamage = bulletDamage;

    bulletTxtr = IMG_LoadTexture(renderer, filePath.c_str());
    bulletSound = Mix_LoadWAV(soundPath.c_str());   // load bullet sound effect

    cooldownLeft = 0;
}
Gun::~Gun()
{
    Mix_FreeChunk(bulletSound);

    // bullets cleanup
    for (vector<Bullet*>::iterator p = bullets.begin(); p != bullets.end(); ++p)
    {
        delete *p;                              // destroys all bullets
        *p = nullptr;
    }
    bullets.clear();

    // activeBullets cleanup
    for (list<Bullet*>::iterator p = activeBullets.begin(); p != activeBullets.end(); ++p)
        *p = nullptr;
    activeBullets.clear();
}
void Gun::shoot(int x, int y)
{
    if (cooldownLeft <= 0)
    {
        Mix_PlayChannel(-1, bulletSound, 0);    // play bullet shot sound
        cooldownLeft = shotInterval;            // reset cooldown

        for (vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++)
        {
            if (!(*it)->isActive)
            {
                (*it)->activate(x, y, bulletSpeed);
                activeBullets.push_back(*it);
                return;
            }
        }

        // create new bullet
        Bullet *newBullet = new Bullet(x, y, bulletTxtr, bulletFrames, bulletSpeed, bulletDamage);
        bullets.push_back(newBullet);
        activeBullets.push_back(newBullet);
    }
}
void Gun::update()
{
    cooldownLeft -= timer.delta;                    // update cooldown
    if (cooldownLeft < 0) cooldownLeft = 0;

    // update active bullets
    for (list<Bullet*>::iterator it = activeBullets.begin(); it != activeBullets.end(); ++it)
    {
        if ((*it)->isActive)
        {
            (*it)->update();
            if ((*it)->position.x > SCREEN_WIDTH)   // if bullet goes off screen
            {
                (*it)->isActive = false;
                activeBullets.erase(it);            // remove inactive bullets from activeBullets
            }
        }
        else
            activeBullets.erase(it);                // same here
    }
}
void Gun::draw()
{
    for (list<Bullet*>::iterator it = activeBullets.begin(); it != activeBullets.end(); ++it)
        (*it)->draw();
}
void Gun::deactivate()
{
    for (list<Bullet*>::iterator it = activeBullets.begin(); it != activeBullets.end(); ++it)
        (*it)->deactivate();
}
