#include "ship.hpp"

using namespace std;

Ship::Ship()
{
    isActive = false;
}
Ship::Ship(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        string shipFilePath, int framesX, int framesY, float speed, int maxHealth,
        float shotInterval, int bulletSpeed, string bulletFilePath, int bulletFrames,
        float bulletDamage, string soundFilePath)
{
    this->offsetX = offsetX;
    this->offsetY = offsetY;
    this->framesX = framesX;
    this->framesY = framesY;
    this->speed = speed;
    this->maxHealth = maxHealth;
    this->bulletFrames = bulletFrames;

    activate(x, y);

    cropRect = {0, 0, 0, 0};
    txtr = IMG_LoadTexture(renderer, shipFilePath.c_str());
    SDL_QueryTexture(txtr, NULL, NULL, &cropRect.w, &cropRect.h);

    this->textureWidth = cropRect.w;

    cropRect.w /= framesX;                  // crop sheet
    cropRect.h /= framesY;

    position.w = cropRect.w;
    position.h = cropRect.h;

    position.w *= SCALE;                    // scale sprite
    position.h *= SCALE;

    hitbox = HitBox(position.x, position.y, boxX, boxY, boxWidth, boxHeight);
    gun = new Gun(shotInterval, bulletSpeed, bulletFilePath, bulletFrames, bulletDamage, soundFilePath);
}
Ship::~Ship()
{
    SDL_DestroyTexture(txtr);
    txtr = nullptr;

    delete gun;
    gun = nullptr;
}
void Ship::draw()
{
    gun->draw();
    if (isActive)
        SDL_RenderCopy(renderer, txtr, &cropRect, &position);

    // draw position box
    //SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0x66);
    //SDL_RenderDrawRect(renderer, &position);

    // draw hitbox
    //SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0x66);
    //SDL_RenderDrawRect(renderer, &hitbox.box);
}
void Ship::hit(int damage)
{
    health -= damage;
    if (health <= 0)            // runs out of health
        deactivate();
}
void Ship::activate(int x, int y)
{
    position.x = x;
    position.y = y;
    health = maxHealth;
    isActive = true;
}
void Ship::deactivate()
{
    log("SHIP deactivate called");
    // death animation
    isActive = false;
    gun->deactivate();
}
void Ship::shoot()
{
    gun->shoot(position.x+offsetX, position.y+offsetY);
}
