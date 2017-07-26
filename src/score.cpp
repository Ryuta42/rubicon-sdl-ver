#include "score.hpp"
#include "enemySpawner.hpp"

Score::Score()
{
    resetScore();

    font = TTF_OpenFont("assets/Iceberg-Regular.ttf", 20);
    if (font == NULL)
        std::cout << "Error loading font: " << TTF_GetError() << std::endl;

    color = {0xFF, 0xFF, 0xFF, 0xFF};

    scorePos = {1220, -3, 600, 88};
    wavePos = {1220, 57, 600, 88};
}
Score::~Score()
{
    TTF_CloseFont(font);
    if (font == NULL)
        log("Font Closed");

    SDL_DestroyTexture(scoreTxtr);
    scoreTxtr = nullptr;

    SDL_DestroyTexture(waveTxtr);
    waveTxtr = nullptr;
}
long Score::scoreVal;

void Score::update()
{
    // update score text
    scoreText.str("");
    scoreText << scoreVal;
    scorePos.w = 50 * digitsOf(scoreVal);

    SDL_Surface *surface = TTF_RenderText_Solid(font, scoreText.str().c_str(), color);
    scoreTxtr = SDL_CreateTextureFromSurface(renderer, surface);

    // update wave text
    waveText.str("");
    waveText << EnemySpawner::wave;
    wavePos.w = 50 * digitsOf(EnemySpawner::wave);

    surface = TTF_RenderText_Solid(font, waveText.str().c_str(), color);
    waveTxtr = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}
void Score::draw()
{
    SDL_RenderCopy(renderer, scoreTxtr, NULL, &scorePos);
    SDL_RenderCopy(renderer, waveTxtr, NULL, &wavePos);
}
void Score::incScore(int amount)
{
    scoreVal += amount;
}
void Score::resetScore()
{
    scoreVal = 0;
}

