#ifndef BULLET_H
#define BULLET_H

#include <SDL.h>
#include <string>

#include "hitbox.hpp"
#include "hasHitbox.hpp"

class Bullet : public HasHitBox
{
public:
    Bullet();
    Bullet(int x, int y, SDL_Texture *txtr, int frames, float speed, float damage);
    ~Bullet();

    int hit();                              // when bullet collides with object
    void activate(int x, int y, float speed);
    void deactivate();                      // despawn bullet
    void update();
    void draw();

private:
    bool isActive;
    SDL_Rect position;
    SDL_Rect cropRect;
    SDL_Texture *txtr = nullptr;
    int frames;                             // number of frames in animation
    int textureWidth;
    float frameCounter;
    float speed;
    int damage;

friend class Gun;
};

#endif // BULLET_H
