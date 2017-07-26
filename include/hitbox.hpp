#ifndef HITBOX_H
#define HITBOX_H

#include <SDL.h>

class HitBox
{
public:
    HitBox();
    HitBox(int parentX, int parentY, int offsetX, int offsetY, int width, int height);
    ~HitBox();

    int offsetX;                // position offset from parent
    int offsetY;
    SDL_Rect box;               // the box itself

    bool overlaps(HitBox otherBox);
    void updatePosition(int parentX, int parentY);
};

#endif // HITBOX_H
