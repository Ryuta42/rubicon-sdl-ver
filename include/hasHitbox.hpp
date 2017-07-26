#ifndef HASHITBOX_H
#define HASHITBOX_H

#include <iostream>

#include "hitbox.hpp"

class HasHitBox
{
public:
    HasHitBox(){};
    ~HasHitBox(){};

    HitBox hitbox;
    void hit(){};
};

#endif // HASHITBOX_H
