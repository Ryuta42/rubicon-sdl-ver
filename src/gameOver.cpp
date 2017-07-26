#include "gameOver.hpp"

GameOver::GameOver()
{
    txtr = IMG_LoadTexture(renderer, "assets/game_over.png");

    font = TTF_OpenFont("assets/Iceberg-Regular.ttf", 20);
    if (font == NULL)
        std::cout << "Error loading font: " << TTF_GetError() << std::endl;

    color = {0xFF, 0xFF, 0xFF, 0xFF};

    scorePos = {525, 547, 600, 174};
    wavePos = {525, 667, 600, 174};

    finalScore = Score::scoreVal;
    finalWave = EnemySpawner::wave;
}
GameOver::~GameOver()
{
    TTF_CloseFont(font);
    if (font == NULL)
        log("Font Closed");

    SDL_DestroyTexture(txtr);
    txtr = nullptr;

    SDL_DestroyTexture(scoreTxtr);
    scoreTxtr = nullptr;

    SDL_DestroyTexture(waveTxtr);
    waveTxtr = nullptr;
}
void GameOver::handleEvents()
{
    while( SDL_PollEvent( &ev ) )
    {
        if (ev.type == SDL_KEYDOWN)         // Key press
        {
            switch (ev.key.keysym.sym)
            {
                case SDLK_ESCAPE: StateHandler::setNextState(STATE_EXIT); break;
                case SDLK_RETURN: StateHandler::setNextState(STATE_GAME); break;
            }
        }
    }
}
void GameOver::logic()
{
    // update score text
    scoreText.str("");
    scoreText << finalScore;
    scorePos.w = 100 * digitsOf(finalScore);

    SDL_Surface *surface = TTF_RenderText_Solid(font, scoreText.str().c_str(), color);
    scoreTxtr = SDL_CreateTextureFromSurface(renderer, surface);

    // update wave text
    waveText.str("");
    waveText << finalWave;
    wavePos.w = 100 * digitsOf(finalWave);

    surface = TTF_RenderText_Solid(font, waveText.str().c_str(), color);
    waveTxtr = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);                           // free temporary surface
}
void GameOver::render()
{
    SDL_RenderClear(renderer);                          // clear renderer

    SDL_RenderCopy(renderer, txtr, NULL, NULL);
    SDL_RenderCopy(renderer, scoreTxtr, NULL, &scorePos);
    SDL_RenderCopy(renderer, waveTxtr, NULL, &wavePos);

    SDL_RenderPresent(renderer);                        // update frame
}
