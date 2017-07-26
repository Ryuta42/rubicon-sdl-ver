#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
    GameState(){}
    virtual ~GameState(){}

    virtual void handleEvents() = 0;
    virtual void logic() = 0;
    virtual void render() = 0;
};

#endif // GAMESTATE_H
