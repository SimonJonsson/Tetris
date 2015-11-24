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

using namespace std;

GameView::GameView(sf::RenderWindow* windowptr)
{
    window = windowptr;
    gameEngine = new GameEngine(700,800,640,580);
}

/*
 * Updatefunction for GameView. Handles all the graphics of game engine.
 */
void GameView::update()
{
    gameEngine->update(12);

    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
    {}
    sf::Sprite sprite(texture);
    window->draw(sprite);
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
