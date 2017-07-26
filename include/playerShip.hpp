#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>

#include "util.hpp"
#include "healthBar.hpp"
#include "ship.hpp"
#include "particle.hpp"

class PlayerShip : public Ship
{
public:
    PlayerShip();
    PlayerShip(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        std::string shipFilePath, int framesX, int framesY, float speed, int maxHealth,
        float shotInterval, int bulletSpeed, std::string bulletFilePath, int bulletFrames,
        float bulletDamage, std::string soundFilePath);
    ~PlayerShip();

    void update(SDL_Rect bound, bool up, bool down, bool left, bool right);
    void draw();
    void hit(int damage);
    void deactivate();

private:
    Mix_Chunk *damageSound;
    float frameCounter;
    std::vector<Particle*> particles;           // trailing particles
    float invinCooldown = 1.0f;                 // time of invincibility after damage taken
    float cooldownLeft = 0.0f;                  // particle cooldown
    SDL_Texture *partTxtr;

friend class HUD;
};

#endif // PLAYERSHIP_H
