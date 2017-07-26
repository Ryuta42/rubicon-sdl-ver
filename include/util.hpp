#ifndef UTIL_H
#define UTIL_H

#include <SDL.h>
#include <string>
#include <fstream>
#include <list>

#include "timer.hpp"
#include "game_state.hpp"

using namespace std;

// global constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const int SCALE = 4;                    // scale that all sprites are multiplied by

// enums
enum GameStates
{
    STATE_NULL,
    STATE_INTRO,
    STATE_MAINMENU,
    STATE_GAME,
    STATE_GAMEOVER,
    STATE_EXIT
};
enum MoveStates                         // move states for enemy movement
{
    MOVE_SPAWNING,
    MOVE_NEUTRAL,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_TOTAL
};
enum EnemyID                            // enemy identities
{
    ENEMY_POD,
    ENEMY_DRONE
};

// external variables
extern SDL_Window *window;              // the game window
extern SDL_Renderer *renderer;          // texture renderer
extern Timer timer;                     // game timer
extern SDL_Event ev;                    // user events
extern int stateID;
extern int nextState;
extern GameState *currentState;
extern ofstream logger;                 // error logger

// utility methods
void log(string message);               // log message to log.txt
int gri(int low, int high);             // generate random int between low and high
float grf(float low, float high);       // generate random float between low and high
int digitsOf(int i);                    // determine number of digits in i

#endif // UTIL_H
