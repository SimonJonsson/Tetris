/*
 * TDDC76 - MAT3 - Group 5
 *
 * IDENTIFIERING
 *
 * Filnamn:    ViewHandler.h
 * Enhetsnamn: ViewHandler
 * Typ:        Moduldeklaration
 * Revision:   1
 * Skriven av: Simon Jönsson
 *
 *
 * BESKRIVNING
 *
 * Handler for all the views.
 * Manages keybindings, drawing, window
 *
 * REVISIONSBERÄTTELSE
 *
 * Revision     Datum   Förändringar
 *
 * 1            940319  Ursprungsversion
 */
#ifndef VIEWHANDLER_H
#define VIEWHANDLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>

#include "UpdateView.h"
#include "MenuView.h"
#include "GameView.h"
#include "GameOverView.h"
#include "HighScoreView.h"


class ViewHandler
{
public:
    ViewHandler();
    ~ViewHandler() = default;

    void    initiate();


private:
    sf::RenderWindow    window;

    UpdateView*         currentView;
    MenuView*           menuView;
    HighScoreView*      highScoreView;
    GameView*           gameView;
    GameOverView*       gameOverView;

    int windowWidth     = 800;
    int windowHeight    = 800;
    int rightTimer      = 0;
    int leftTimer       = 0;
    int upTimer         = 0;
    int downTimer       = 0;
    int backspaceTimer  = 0;
    int standardBounces    = 20; // The standard number of bounces, also prevents spamming 'up'(see Up keybinding)
    int noBounces       = 20; //Number of bounces before we debounce
    int gNoBounces      = 3; //Number of bounces before we debounce in GameView
    std::string input{""};
    sf::Texture texture;
    sf::RectangleShape background;

    bool pause          = false;
    bool upBounce       = false;
    bool downBounce     = false;
    bool rightBounce    = false;
    bool leftBounce     = false;
    bool pauseBounce    = false;
    bool backspaceBounce= false;

    void eventHandler();
    void inputHandler();
    void outputHandler();
    void changeView(std::string);

    std::string focus = "";

};

#endif
