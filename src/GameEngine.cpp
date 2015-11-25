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
 * Module: iostream
 * Module: math
 *
 * REVISIONLOG
 * Revision     Date    Changes
 * 1.0          151122  Original version.
 */

#include "../include/GameEngine.h"
#include <iostream>
#include <math.h>
using namespace std;
using namespace sf;

/////////////////////////-----(START) PUBLIC FUNCTIONS-----//////////////////////////////////////

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
    moveTime = initMoveTime;

    fieldPos = Position((wWidth - fWidth) / 2, (wHeight - fHeight) / 2);
    startPos = Position(fieldPos.x + fWidth / 2, fieldPos.y);

    currentFigure = generateRandomFigure();
    nextFigure = generateRandomFigure();

}

/*
 * DESTRUCTOR ~GameEngine()
 * Releases memory of datamembers.
 */
GameEngine::~GameEngine()
{
    for(RectangleShape* block : blockField)
    {
        delete block;
    }
    delete currentFigure;
    delete nextFigure;
}

/* FUNCTION void GameEngine::update(long dt)
 * Updates current state of the game.
 * dt is time in milliseconds since last update.
 */
void GameEngine::update(long dt)
{
    if(!gameOver && !gamePaused )
    {
        timeStill += dt;
        if(timeStill > moveTime)
        {
            bool shouldPlace = translate(currentFigure,0,1);

            if (shouldPlace)
            {
                placeFigure();
                //nextFigure->translate(defaultPos);
                currentFigure = nextFigure;
                nextFigure = generateRandomFigure();
                timeStill = 0;
                if(collides(currentFigure)) //in default pos. -> can only collide with blockfield.
                {
                    gameOver = true;
                }
            }
        }
        int cleared = clearFullRows();
        increaseScore(scorePerRow*cleared*(difficulty+1)); //+1 due to initial diff=0
        updateDifficulty();

    }
}

/* FUNCTION void GameEngine::leftClick()
 * Attempts to translate figure to the left.
 */
void GameEngine::leftClick()
{
    translate(currentFigure,-1,0);
}

/* FUNCTION void GameEngine::rightClick()
 * Attempts to translate figure to the right.
 */
void GameEngine::rightClick()
{
    translate(currentFigure,1,0);
}

/* FUNCTION void GameEngine::upClick()
 * Attempts to rotate the figure 90 degrees clockwise.
 */
void GameEngine::upClick()
{
    // Figure* temp = currentFigure->clone();
    // temp->rotate();
    // bool coll = collides(temp);
    // if (!coll)
    //{
    //currentFigure->rotate
    //}
    //
}

/* FUNCTION void GameEngine::downClick()
 * Instantly places the figure on the blockfield directly under current location.
 */
void GameEngine::downClick()
{
    if(translate(currentFigure,0,1))
    {
        timeStill = 0;
    }
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

/* FUNCTION vector<RectangleShape*> GameEngine::getBlockField()
 * Returns vector with pointers to all blocks in field.
 */
vector<RectangleShape*>& GameEngine::getBlockField()
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

//////////////////////-----(END) PUBLIC FUNCTIONS-----//////////////////////////////////////

//////////////////////-----(START) PRIVATE FUNCTIONS-----///////////////////////////////////

/* FUNCTION void GameEngine::updateMoveTime()
 * Update moveTime.
 */
void GameEngine::updateDifficulty()
{
    if(diffCleared > 2 + difficulty) //Needs to be tested until good feel.
    {
        ++difficulty;
        moveTime = initMoveTime / log(exp(1) + difficulty); //Also needs testing for feel.
        diffCleared = 0;
    }
}

/* FUNCTION void GameEngine::translate(Figure* fig, int x, int y)
 * Translate figure one step. x,y=0 nothing. x=-1, left, x=1 right, y=-1 up, y=1 down.
 * Returns false if figure lower bound is touching blockfield->needs to be placed.
 * Else true.
 */
bool GameEngine::translate(Figure* fig, int x, int y)
{
 //need translate from figure
}

/* FUNCTION void GameEngine::translate(sf::RectangleShape* block, int x, int y)
 * Translate one tetris block. x,y=0 nothing. x=-1, left, x=1 right, y=-1 up, y=1 down.
 * Returns false if translation is not possible.
 */
bool GameEngine::translate(sf::RectangleShape* block, int x, int y)
{
    //block->setPosition(block->getPosition.x + x*blockSize, block->getPosition.y + y*blockSize);
}

/* FUNCTION bool GameEngine::collides(Figure* fig)
 * Check if figure collides with blockfield/borders
 */
bool GameEngine::collides(Figure* fig)
{
    //need intersects from figure.
}

/* FUNCTION void GameEngine::placeFigure()
 * Place current figure onto blockfield.
 */
void GameEngine::placeFigure()
{
    //need getBlocks from figure
}

/* FUNCTION Figure* GameEngine::generateRandomFigure()
 * Generate a random figure.
 */
Figure* GameEngine::generateRandomFigure()
{
    int id = uniRand(); //[1,numFigure]

}

/* FUNCTION int GameEngine::uniRand()
 * Generate a uniformly distributed random number in the range 1 to numFigures(7 default).
 */
int GameEngine::uniRand()
{
     mt19937 rng;
     rng.seed(random_device()());
     uniform_int_distribution<mt19937::result_type> numGen(1,numFigures); //U(1,numFigures) distributed
     return numGen(rng); //Generate random number 1->#figures.
}

/* FUNCTION int GameEngine::clearFullRows()
 * Removes full rows from board and returns number of rows removed.
 */
int GameEngine::clearFullRows()
{

}

/* FUNCTION void GameEngine::increaseScore(long amount)
 * Increases score by specified amount of points.
 */
void GameEngine::increaseScore(long amount)
{
    if(amount > 0)
    {
        score += amount;
    }
}

//////////////////////-----(END) PRIVATE FUNCTIONS-----///////////////////////////////////

