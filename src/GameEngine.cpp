/*
 * TDDC76 - MAT3 - Group 5
 *
 * INDENTIFICATION
 *
 * Filename:    GameEngine.cpp
 * Unitname:    GameEngine
 * Type:        Module definition
 * Revision:    1.0
 * Author:      G. Webb
 *
 *
 * DESCRIPTION
 *
 * This module defines the functionality declared by GameEngine.h.
 *
 * REVISIONLOG
 *
 * Revision     Date    Changes
 *
 * 1.0          151122  Original version.
 */
#include "../include/GameEngine.h"
using namespace std;

GameEngine::GameEngine(int windowHeight, int windowWidth, int boardHeight, int boardWidth, int initialDifficulty)
{
    wHeight = windowHeight;
    wWidth = windowWidth;
    fHeight = boardHeight;
    fWidth = boardWidth;
    difficulty = initialDifficulty;

    boardPos = Position((wWidth - fWidth) / 2, (wHeight - fHeight) / 2);


}

