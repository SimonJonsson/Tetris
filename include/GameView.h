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
    GameView();
    ~GameView() = default;

    void update(sf::RenderWindow&) override;

    void leftClick()  override;
    void rightClick() override;
    void upClick()    override;
    void downClick()  override;

private:
    GameEngine* gameEngine;

};

#endif
