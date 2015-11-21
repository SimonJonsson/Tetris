//Grayson
#include "../include/GameEngine.h"
using namespace std;

GameEngine::GameEngine(int windowHeight, int windowWidth, int boardHeight, int boardWidth)
{
    wHeight = windowHeight;
    wWidth = windowWidth;
    bHeight = boardHeight;
    bWidth = boardWidth;

    boardPos = Position((wWidth - bWidth) / 2, (wHeight - bHeight) / 2);


}

