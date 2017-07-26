#include "util.hpp"

using namespace std;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
Timer timer;
SDL_Event ev;

int stateID = STATE_NULL;
int nextState = STATE_NULL;
GameState *currentState = NULL;

ofstream logger("log.txt");

void log(string message)                    // write to log.txt to debug crashes
{
    logger << message << endl;
}
int gri(int low, int high)
{
    return low + (rand() % (int)(high - low + 1));
}
float grf (float low, float high)
{
    return low + (static_cast<float> (rand()) / static_cast<float> (RAND_MAX/(high-low)));
}
int digitsOf(int i)
{
    int digits = 0;
    while(i)
    {
        i /= 10;
        digits++;
    }
    return digits;
}
