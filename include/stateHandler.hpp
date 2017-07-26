#ifndef STATEHANDLER_H
#define STATEHANDLER_H

#include "util.hpp"
#include "mainMenu.hpp"
#include "stage.hpp"
#include "gameOver.hpp"

class StateHandler
{
private:
    static void initState();
    static void setNextState(int nextState);
    static void changeState();

friend class Player;
friend class MainMenu;
friend class Stage;
friend class GameOver;
friend int main(int argc, char* argv[]);
};

#endif // STATEHANDLER_H
