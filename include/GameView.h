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

private:
    sf::RenderWindow*   window;
    GameEngine*         gameEngine;

    sf::RectangleShape background{sf::Vector2f(500, 640)};

    sf::Text scoreText;
    sf::Font coolFont;
    sf::Clock clock;

    long int score = 0;

    float fps = 0;
    float lastTime = 0;
    float currentTime;
};

#endif
