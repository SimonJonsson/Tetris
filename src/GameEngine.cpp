/* TDDC76 - MAT3 - Group 5
 *
 * INDENTIFICATION
 * Filename:    GameEngine.cpp
 * Unitname:    GameEngine
 * Type:        Module definition
 * Revision:    1.0
 * Author:      G. Webb
 *
 * DESCRIPTION
 * This module defines the functionality declared by GameEngine.h.
 *
 * USES
 * Module: GameEngine
 *
 * REVISIONLOG
 * Revision     Date    Changes
 * 1.0          151122  Original version.
 */

#include "../include/GameEngine.h"

using namespace std;
using namespace sf;

/*
* CONSTRUCTOR GameEngine::GameEngine(int windowHeight, int windowWidth, int boardHeight, int boardWidth, int initialDifficulty);
* Creates a new Tetris game engine with specified dimensions.
*/
GameEngine::GameEngine(int windowHeight, int windowWidth, int boardHeight, int boardWidth, int initialDifficulty)
{
    wHeight = windowHeight;
    wWidth = windowWidth;
    fHeight = boardHeight;
    fWidth = boardWidth;
    difficulty = initialDifficulty;

    boardPos = Position((wWidth - fWidth) / 2, (wHeight - fHeight) / 2);
}

/*
 * DESTRUCTOR ~GameEngine()
 * Releases memory of datamembers.
 */
GameEngine::~GameEngine()
{
    for(Shape* block : blockField)
    {
        delete block;
    }
}

/* FUNCTION void GameEngine::update(long dt)
 * Updates current state of the game.
 * dt is time in milliseconds since last update.
 */
void GameEngine::update(long dt)
{

}

/* FUNCTION void GameEngine::leftClick()
 * Attempts to translate figure to the left.
 */
void GameEngine::leftClick()
{

}

/* FUNCTION void GameEngine::rightClick()
 * Attempts to translate figure to the right.
 */
void GameEngine::rightClick()
{

}

/* FUNCTION void GameEngine::upClick()
 * Attempts to rotate the figure 90 degrees clockwise.
 */
void GameEngine::upClick()
{

}

/* FUNCTION void GameEngine::downClick()
 * Instantly places the figure on the blockfield directly under current location.
 */
void GameEngine::downClick()
{

}

/* FUNCTION bool GameEngine::isGameOver()
 * Returns true if end of game criteria has been reached. Else false.
 */
bool GameEngine::isGameOver()
{
    return gameOver;
}

/* FUNCTION bool GameEngine::isGamePaused()
 * Returns true if game is currently paused/not running. Else false.
 */
bool GameEngine::isGamePaused()
{
    return gamePaused;
}

/* FUNCTION vector<Shape*> GameEngine::getBlockField()
 * Returns vector with pointers to all blocks in field.
 */
vector<Shape*>& GameEngine::getBlockField()
{
    return blockField;
}

/* FUNCTION Figure* GameEngine::getCurrentFigure()
 * Returns pointer to current figure player is placing.
 */
Figure* GameEngine::getCurrentFigure()
{
    return currentFigure;
}

/* FUNCTION Figure* GameEngine::getNextFigure()
 * Returns pointer to next figure player will place.
 */
Figure* GameEngine::getNextFigure()
{
    return nextFigure;
}

/* FUNCTION long GameEngine::getScore()
 * Returns current score.
 */
long GameEngine::getScore()
{
    return score;
}

