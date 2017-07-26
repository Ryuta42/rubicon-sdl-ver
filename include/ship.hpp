#ifndef SHIP_H
#define SHIP_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "util.hpp"
#include "hasHitbox.hpp"
#include "gun.hpp"

class Ship : public HasHitBox
{
public:
    Ship();
    explicit Ship(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        std::string shipFilePath, int framesX, int framesY, float speed, int maxHealth,
        float shotInterval, int bulletSpeed, std::string bulletFilePath, int bulletFrames,
        float bulletDamage, std::string soundFilePath);
    virtual ~Ship();

    bool isActive = false;
    SDL_Rect position;
    Gun *gun;

    void activate(int x, int y);    // spawn ship
    virtual void deactivate() = 0;
    void shoot();
    void hit(int damage);           // if hit by something
    void update() {};
    void draw();

protected:
    int offsetX;                    // bullet spawn offset from ship
    int offsetY;
    int framesX;                    // columns of sprite sheet
    int framesY;                    // rows of sprite sheet
    SDL_Texture *txtr;
    int textureWidth;               // width of sprite sheet (for animation)
    SDL_Rect cropRect;              // rect of sprite sheet that is drawn
    int bulletFrames;               // frames in bullet animation

    float speed;                    // movement speed
    int health;                     // current health
    int maxHealth;                  // maximum health
};

#endif // SHIP_H
