/*
 * TDDC76 - MAT3 - Group 5
 *
 * IDENTIFIERING
 *
 * Filnamn:    ViewHandler.cc
 * Enhetsnamn: ViewHandler
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
#include "../include/ViewHandler.h"
#include <iostream>

using namespace std;

//Instantiates all the views
ViewHandler::ViewHandler()
{
//    menuView        = new MenuView{};
//    highScoreView   = new HighScoreView{};
    gameView        = new GameView(&window);
//    gameOverView    = new GameOverView{};
    currentView     = gameView;
}

//Main function for updating the window
void ViewHandler::initiate()
{
    //Creates a window with height, width, title and disables resizing of window
    window.create(sf::VideoMode(windowWidth,windowHeight),"Tetris",sf::Style::Close);

    // Start the game loop
    while (window.isOpen())
    {
        eventHandler();
        inputHandler();
        outputHandler();
    }
}

/*
 * Handles all events for the window
 */
void ViewHandler::eventHandler()
{

    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window : exit
        if (event.type == sf::Event::Closed)
            window.close();

        /*
         *  If we lose focus of the screen we pause, if we gain focus again we unpause.
         */
        if (event.type == sf::Event::GainedFocus)
            pause = false;

        if (event.type == sf::Event::LostFocus)
            pause = true;
    }
}
/*
 * The keybindings for all views
 * This happens before the update so we can draw
 * instantaneously what happens.
 * This must also have a debounce function
 */
void ViewHandler::inputHandler()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        cout << "left\n";
        if (!pause)
            currentView->leftClick();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        cout << "right\n";
        if (!pause)
            currentView->rightClick();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        cout << "up\n";
        if (!pause)
            currentView->upClick();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        cout << "down\n";
        if (!pause)
            currentView->downClick();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        if (typeid(currentView) == typeid(GameView))
        {
            if (pause)
            {
                pause = false;
            }
            else
            {
                pause = true;
            }
        }
    }
}
/*
 * Handles the outputs for ViewHandler
 * including all update functions
 */
void ViewHandler::outputHandler()
{
    // We want to render only if we are not paused.
    if (!pause)
    {
        // Clear screen, screen background is white.
        window.clear(sf::Color::White);
        // Update for currentView.
        currentView->update(window);
        // Update the window
        window.display();
    }
}
