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

typedef sf::Vector2<int> Position;

class GameEngine
{
private:
    int wHeight; //Height of Window.
    int wWidth; //Width of Window.
    int fHeight; //Height of playing field.
    int fWidth; //Width of playing field.
    Position boardPos; //Upper left corner of playing field.
    std::vector<sf::Shape*> blockField; //Vector with pointers to all blocks that have been placed.
    Figure* currentFigure; //Current tetris figure falling down.
    Figure* nextFigure; //Next figure to be placed.
    int difficulty = 0; //Difficulty of game. Based on number of cleared rows.
    int moveTime = 0; //Time(ms) until block should be moved. Based on difficulty.
    int timeStill = 0; //How long time(ms) has gone since block was moved.
    int blockSize = 0; //Width/Height of one block. This will be stepsize when translating.
    long score = 0; //Current accumulated score.
    bool gameOver = false; //Has the game ended.
    bool gamePaused = false; //Has the game been paused.

    void updateMoveTime(); //Update moveTime.
    void translate(Figure* fig, int x, int y); //Translate figure one step. x,y=0 nothing. x=-1, left, x=1 right, y=-1 up, y=1 down.
    void translate(sf::Shape* block, int x, int y); //Translate one tetris block. As above
    sf::Shape* collides(Figure* fig); //Check if figure collides with blockfield/borders
    void placeFigure(Figure*& fig); //Place current figure onto blockfield.
    void generateNextFigure(); //Generate a next random figure.
    int clearFullRows(); //Removes full rows from board and returns number of rows removed.
    void increaseScore(long amount); //Increases score by specified amount of points.

public:
    GameEngine(int windowHeight, int windowWidth, int boardHeight, int boardWidth, int initialDifficulty=0); //Constructor.
    ~GameEngine() = default; //Currently leaks memory! Needs to be implemented.

    void leftClick(); //Actions corresponding to player pressing left arrow key.
    void rightClick(); //Actions corresponding to player pressing right arrow key.
    void upClick(); //Actions corresponding to player pressing up arrow key.
    void downClick(); //Actions corresponding to player pressing down arrow key.

    void update(long dt); //Logic loop. dt is time since last update was performed.
    bool isGameOver(); //Checks if game has ended /returns gameOver.
    bool isGamePaused(); //Checks if player has paused game /returns gamePaused.
    std::vector<sf::Shape*> getBlockField(); //Returns vector containing pointers to all blocks in blockfield.
    Figure* getCurrentFigure(); //Returns current figure that is falling down.
    Figure* getNextFigure(); //Returns next figure to be placed.
    long getScore(); //Returns current score.
    void operator=(GameEngine& )= delete; //Only one GameEngine can exist at one time.

};


#endif
