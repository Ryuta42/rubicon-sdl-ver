#include "timer.hpp"

Timer::Timer()
{
    prevTime = 0;
    currentTime = 0;
    delta = 0;
}
void Timer::update()
{
    prevTime = currentTime;
    currentTime = SDL_GetTicks();
    delta = (currentTime - prevTime) / 1000.0f;
    //std::cout << "FPS: " << (1/delta) << std::endl;   // uncomment to see game FPS
}
