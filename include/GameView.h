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

class GameView : public UpdateView
{
public:
    GameView(sf::RenderWindow*);
    ~GameView() = default;

    void update() override;
    void draw();

    void leftClick()  override;
    void rightClick() override;
    void upClick()    override;
    void downClick()  override;

    int getScore();

private:
    sf::RenderWindow*   window;
    GameEngine*         gameEngine;

    int fieldPosX = 50;
    int fieldPosY = 60;
    int fieldWidth = 500;
    int fieldHeight = 640;
    int fieldOffset = 10;

    long int score = 0;
    int scoreWidth;

    float fps = 0;
    float lastTime = 0;
    float currentTime;

    float getFps();

    sf::RectangleShape background{sf::Vector2f(fieldWidth, fieldHeight)};
    sf::RectangleShape nextFigureBox{sf::Vector2f(100, 100)};

    sf::Text scoreText;
    sf::Text scoreNumText;
    sf::Text nextFigureText;
    sf::Font coolFont;
    sf::Clock clock;
};

#endif
