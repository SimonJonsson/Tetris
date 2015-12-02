/*
 * TDDC76 - MAT3 - Group 5
 *
 * IDENTIFIERING
 *
 * Filnamn:    GameView.cc
 * Enhetsnamn: GameView
 * Revision:   1
 * Skriven av: Simon Jönsson
 *
 *
 * BESKRIVNING
 *
 * See .h
 *
 * REVISIONSBERÄTTELSE
 *
 * Revision     Datum   Förändringar
 *
 * 1            940319  Ursprungsversion
 */
#include "../include/GameView.h"
#include <iostream>

using namespace std;


GameView::GameView(sf::RenderWindow* windowptr)
{
    window = windowptr;
    gameEngine = new GameEngine(700,800,500,640);

    background.setPosition(100, 60);
    background.setFillColor(sf::Color::Black);

    scoreText.setFont(coolFont);
    scoreText.setString("0");
    //scoreText.setColor(textcolor);
    scoreText.setCharacterSize(40);
    scoreText.setPosition(255, 240);
}

/*
 * Updatefunction for GameView. Handles all the graphics of game engine.
 */
void GameView::update()
{
    currentTime = clock.restart().asSeconds();
    fps = 1.f / currentTime;
    score = gameEngine->getScore();
    gameEngine->update(fps);

    //scoreText.setString(to_string(score));
    draw();
}
/*
 * Drawfunction for all the objects
 */
void GameView::draw()
{
    window->draw(scoreText);
    window->draw(background);
}

/*
 * All the keybindings for the GameView.
 */
void GameView::leftClick()
{
    gameEngine->leftClick();
}

void GameView::rightClick()
{
    gameEngine->rightClick();
}

void GameView::upClick()
{
    gameEngine->upClick();
}

void GameView::downClick()
{
    gameEngine->downClick();
}
