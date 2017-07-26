#include "playerShip.hpp"

PlayerShip::PlayerShip(){}

PlayerShip::PlayerShip(int x, int y, int offsetX, int offsetY, int boxX, int boxY, int boxWidth, int boxHeight,
        std::string shipFilePath, int framesX, int framesY, float speed, int maxHealth,
        float shotInterval, int bulletSpeed, std::string bulletFilePath, int bulletFrames,
        float bulletDamage, std::string soundFilePath)
        : Ship(x, y, offsetX, offsetY, boxX, boxY, boxWidth, boxHeight, shipFilePath, framesX, framesY,
        speed, maxHealth, shotInterval, bulletSpeed, bulletFilePath, bulletFrames,
        bulletDamage, soundFilePath)
{
    partTxtr = IMG_LoadTexture(renderer, "assets/particle.png");
    damageSound = Mix_LoadWAV("assets/damage.wav");
    frameCounter = 0;
}
PlayerShip::~PlayerShip()
{
    log("PlayerShip destructed");
    SDL_DestroyTexture(txtr);
    txtr = nullptr;

    Mix_FreeChunk(damageSound);

    delete gun;
    gun = nullptr;

    for (std::vector<Particle*>::iterator p = particles.begin(); p != particles.end(); p++)
    {
        delete *p;
        *p = nullptr;
    }
    particles.clear();
}
void PlayerShip::update(SDL_Rect bound, bool up, bool down, bool left, bool right)
{
    hitbox.updatePosition(position.x, position.y);

    if (up && !down && (hitbox.box.y > bound.y))
        position.y -= speed * timer.delta;      // move up
    else if (down && !up && ( (hitbox.box.y+hitbox.box.h) < (bound.y+bound.h)))
        position.y += speed * timer.delta;      // move down
    if (left && !right && (hitbox.box.x > bound.x))
        position.x -= speed * timer.delta;      // move left
    else if (right && !left && ( (hitbox.box.x+hitbox.box.w) < (bound.x+bound.w)))
        position.x += speed * timer.delta;      // move right

    shoot();
    gun->update();

    // animation
    frameCounter += timer.delta;
    if (frameCounter >= 0.125f)
    {
        frameCounter = 0;
        cropRect.x += cropRect.w;
        if (cropRect.x >= textureWidth)
            cropRect.x = 0;
    }

    // update invincibility
    if (invinCooldown > 0)
    {
        invinCooldown -= timer.delta;
        isActive = false;
    }
    else
    {
        invinCooldown = 0.0f;
        isActive = true;
    }

    // update particles
    cooldownLeft -= timer.delta;            // update cooldown
    if (cooldownLeft <= 0)
    {
        cooldownLeft = 0.025;               // reset cooldown

        for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it)
        {
            if (!(*it)->isActive)
            {
                (*it)->activate(position.x+20, position.y+40);
                return;
            }
        }

        // create new particle
        Particle *newPart = new Particle(position.x+20, position.y+40, 2400, partTxtr);
        particles.push_back(newPart);
    }
    for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it)
        (*it)->update();
}
void PlayerShip::draw()
{
    gun->draw();
    if (isActive || frameCounter >= 0.05f)
        SDL_RenderCopy(renderer, txtr, &cropRect, &position);

    // draw particles
    for (std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it)
        (*it)->draw();

    // draw position box
    //SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0x66);
    //SDL_RenderDrawRect(renderer, &position);

    // draw hitbox
    //SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0x66);
    //SDL_RenderDrawRect(renderer, &hitbox.box);
}
void PlayerShip::hit(int damage)
{
    Mix_PlayChannel(-1, damageSound, 0);    // damage sound effect
    invinCooldown = 1.0;                    // become invincible

    health -= damage;
    HealthBar::updateHealth(health);
    if (health <= 0)                        // runs out of health
        deactivate();
}
void PlayerShip::deactivate()
{
    log("PLAYERSHIP deactivate called");
    isActive = false;
    hitbox.box.x = hitbox.box.y = hitbox.box.w = hitbox.box.h = 0;
}
