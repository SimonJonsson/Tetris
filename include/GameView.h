/*
 * TDDC76 - MAT3 - Group 5
 *
 * IDENTIFIERING
 *
 * Filnamn:    GameView.h
 * Enhetsnamn: GameView
 * Typ:        Moduldeklaration
 * Revision:   1
 * Skriven av: Simon Jönsson
 *
 *
 * BESKRIVNING
 *
 * The view that handles the graphics for GameEngine
 *
 * REVISIONSBERÄTTELSE
 *
 * Revision     Datum   Förändringar
 *
 * 1            940319  Ursprungsversion
 */
#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "UpdateView.h"
#include "GameEngine.h"

#include <string>
#include <iostream>
#include <vector>

class GameView : public UpdateView
{
public:
    GameView(sf::RenderWindow*);
    ~GameView() = default;

    void update() override;
    void pauseSplash();
    void draw();
    void pause(bool state);

    void leftClick()  override;
    void rightClick() override;
    void upClick()    override;
    void downClick()  override;

    int getScore();
    bool isGameOver();

private:
    int cleared = 0;
    sf::RenderWindow*   window;
    GameEngine*         gameEngine;
    Figure*             currentFigure;
    Figure*             nextFigure;

    int fieldPosX = 50;
    int fieldPosY = 40;
    int fieldWidth = 360;
    int fieldHeight = 2*fieldWidth;
    int fieldOffset = 10;
    int blocksize = fieldWidth/10;
    int nextShift = 110;
    int nextShifty = 250;
    int scoreWidth;

    long int score = 0;

    float fps = 0;
    float lastTime = 0;
    float currentTime;

    bool paused     = false;
    bool gameOver   = false;

    std::vector<sf::RectangleShape*> blockField;
    sf::RectangleShape background{sf::Vector2f(fieldWidth, fieldHeight)};
    sf::RectangleShape nextFigureBox{sf::Vector2f(120, 110)};
    sf::Text scoreText;
    sf::Text scoreNumText;
    sf::Text nextFigureText;
    sf::Text pauseText;
    sf::Font coolFont;
    sf::Clock clock;

    int rfac = (rand() % 35)+220;
    int rfac2 = (rand() % 65)+190;
    int c1 = std::rand() % rfac2;
    int c2 = rand() % rfac2;
    int c3 = rand() % rfac;

    int c4 = rand() % rfac;
    int c5 = rand() % rfac2;
    int c6 = rand() % rfac2;

    void drawGrid();
    float getFps();
    void drawFigures();
    void drawGhost();
    void initGraphics();
};

#endif
