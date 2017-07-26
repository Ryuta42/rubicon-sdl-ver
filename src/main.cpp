/* CIS 330 Project
 * Winter 2016
 *
 * Miles Chew
 */
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <time.h>

#include "util.hpp"
#include "stateHandler.hpp"

using namespace std;

bool init()
{
    log("Initialization...");

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)   // Initialize Video
    {
        cout << "Video Initialization Error: " << SDL_GetError() << endl;
        return false;
    }
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
    if (window == NULL)
    {
        cout << "Window Creation Error: " << SDL_GetError() << endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        cout << "Renderer Initialization Error: " << SDL_GetError() << endl;
        return false;
    }
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)     // Initialize SDL_IMG
    {
        cout << "PNG load Error: " << IMG_GetError() << endl;
        return false;
    }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)   // initialize Mixer
    {
        cout << "MIX load Error: " << Mix_GetError() << endl;
        return false;
    }
    if (TTF_Init() < 0)                     // Initialize SDL_TTF
    {
        cout << "TTF Load Error: " << TTF_GetError() << endl;
        return false;
    }

    srand(time(NULL));                      // seed randomizer

    log("All initializations successful.");
    return true;                            // Everything properly initialized
}
void cleanup()                              // destroy objects and deallocate memory
{
    delete currentState;

    SDL_DestroyRenderer(renderer);
    renderer = nullptr;

    SDL_DestroyWindow(window);
    window = nullptr;
}
void shutdown()                             // shutdown APIs
{
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();

    log("Application exited");
    logger.close();                         // close debug log
}
int main(int argc, char* argv[])
{
    bool success = false;
    if (init())                             // initialize
    {
        success = true;
        StateHandler::initState();          // set currentState

        while (stateID != STATE_EXIT)       // game loop
        {
            timer.update();                 // update frame timer
            currentState->handleEvents();   // event handling
            currentState->logic();          // game logic
            StateHandler::changeState();    // change state if necessary
            currentState->render();         // state rendering
        }
        cleanup();                          // deallocations
    }
    shutdown();                             // close SDL etc
    if (!success) return 1;
    return 0;
}
