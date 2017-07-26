#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
#include <iostream>

class Timer
{
public:
    Timer();

    double delta;           // time since last frame
// methods

private:
    long prevTime;
    long currentTime;

    void update();          // calculate new delta

friend int main(int argc, char* argv[]);
};

#endif // TIMER_H
