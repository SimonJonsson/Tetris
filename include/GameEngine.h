/* TDDC76 - MAT3 - Group 5
 *
 * INDENTIFICATION
 * Filename:    GameEngine.h
 * Unitname:    GameEngine
 * Type:        Module declaration
 * Revision:    1.0
 * Author:      G. Webb
 *
 * DESCRIPTION
 * This module decalares the functionality that the Tetris game engine will have.
 *
 * USES
 * Module: SFML/Graphics
 * Module: vector
 * Module: Figure
 *
 * REVISIONLOG
 * Revision     Date    Changes
 * 1.0          151122  Óriginal version.
 */

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Figure.h"
//#include "Figures.h"

typedef sf::Vector2<int> Position;

class GameEngine
{
private:
    int wHeight; //Height of Window.
    int wWidth; //Width of Window.
    int fHeight; //Height of playing field.
    int fWidth; //Width of playing field.
    Position fieldPos; //Upper left corner of playing field.
    Position startPos; //Start posiion of new figures.
    Position nextPos;
    std::vector<sf::RectangleShape*> blockField; //Vector with pointers to all blocks that have been placed.
    Figure* currentFigure; //Current tetris figure falling down.
    Figure* nextFigure; //Next figure to be placed.
    int numFigures = 7; //Numbers of unique figure-types (LJTO...)

    int rowsCleared = 0; //Number of rows player has cleared.
    int diffCleared = 0; //Number of rows cleared on current difficulty
    int difficulty = 0; //Difficulty of game. Based on number of cleared rows.
    long initMoveTime = 800;//850 //Move time(ms) for difficulty 0.
    int moveTime = 0; //Time(ms) until block should be moved. Based on difficulty.
    int timeStill = 0; //How long time(ms) has gone since block was moved.
    int blockSize = 20; //Width/Height of one block. This will be stepsize when translating.
    long score = 0; //Current accumulated score.
    int scorePerRow = 100;
    bool gameOver = false; //Has the game ended.
    bool gamePaused = false; //Has the game been paused.

    void updateDifficulty(); //Update moveTime.

    bool translate(sf::RectangleShape* block, int x, int y); //Translate one tetris block. As above

    bool collides(sf::RectangleShape* block); //Check if RectangleShape collides with blockfield/borders
    void placeFigure(); //Place current figure onto blockfield.
    Figure* generateRandomFigure(); //Generate a random figure.
    int uniRand(); //Generate random number in range 1->number of figures.
    int clearFullRows(); //Removes full rows from board and returns number of rows removed.
    void increaseScore(long amount); //Increases score by specified amount of points.

public:
 bool translate(Figure* fig, int x, int y); //Translate figure one step. x,y=0 nothing. x=-1, left, x=1 right, y=-1 up, y=1 down.
    bool collides(Figure* fig); //Check if figure collides with blockfield/borders
    GameEngine(sf::Vector2<int> fieldPosition, int boardHeight, int boardWidth, sf::Vector2<int> nextPosition, int initialDifficulty=0); //Constructor.
    ~GameEngine(); //Destructor.

    void update(long dt); //Logic loop. dt is time since last update was performed.
    void leftClick(); //Actions corresponding to player pressing left arrow key.
    void rightClick(); //Actions corresponding to player pressing right arrow key.
    void upClick(); //Actions corresponding to player pressing up arrow key.
    void downClick(); //Actions corresponding to player pressing down arrow key.

    bool isGameOver(); //Checks if game has ended /returns gameOver.
    bool isGamePaused(); //Checks if player has paused game /returns gamePaused.
    std::vector<sf::RectangleShape*>& getBlockField(); //Returns vector containing pointers to all blocks in blockfield.
    Figure* getCurrentFigure(); //Returns current figure that is falling down.
    Figure* getNextFigure(); //Returns next figure to be placed.
    long getScore(); //Returns current score.
    sf::Vector2<int> getFieldPos(); //Gets x,y pos of board
    int getRowsCleared(); //Gets number of rows cleared.

    void operator=(GameEngine& )= delete; //Only one GameEngine can exis

};

#endif
