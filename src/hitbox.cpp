#include "hitbox.hpp"

#include <SDL.h>
#include <iostream>

#include "collisionHandler.hpp"

HitBox::HitBox()
{}
HitBox::HitBox(int parentX, int parentY, int offsetX, int offsetY, int width, int height)
{
    this->offsetX = offsetX;
    this->offsetY = offsetY;

    box = {parentX + offsetX, parentY + offsetY, width, height};
}
HitBox::~HitBox()
{}
bool HitBox::overlaps(HitBox otherBox)
{
    return CollisionHandler::collision(box, otherBox.box);
}
void HitBox::updatePosition(int parentX, int parentY)
{
    box.x = parentX + offsetX;
    box.y = parentY + offsetY;
}
