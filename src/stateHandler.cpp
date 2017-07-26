#include "stateHandler.hpp"

void StateHandler::initState()
{
    stateID = STATE_MAINMENU;
    currentState = new MainMenu();
}
void StateHandler::setNextState(int newState)
{
    // if user wants to exit, don't override with different state.
    if (nextState != STATE_EXIT)
        nextState = newState;       // set new state
}
void StateHandler::changeState()
{
    if (nextState != STATE_NULL)    // if state has to be changed
    {
        if (nextState != STATE_EXIT)    // free old assets
            delete currentState;

        switch (nextState)
        {
            case STATE_MAINMENU:
                currentState = new MainMenu();
                break;
            case STATE_GAME:
                currentState = new Stage();
                break;
            case STATE_GAMEOVER:
                currentState = new GameOver();
                break;
        }
        stateID = nextState;            // assign new stateID
        nextState = STATE_NULL;
    }
}
