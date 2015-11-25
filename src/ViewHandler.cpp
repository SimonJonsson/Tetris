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
    menuView        = new MenuView(&window);
    highScoreView   = new HighScoreView(&window);
    gameView        = new GameView(&window);
    gameOverView    = new GameOverView(&window);
    currentView     = menuView;
}


//Main function for updating the window
void ViewHandler::initiate()
{
    //Creates a window with height, width, title and disables resizing of window
    window.create(sf::VideoMode(windowWidth,windowHeight),"Tetris",sf::Style::Close);
    window.setPosition(sf::Vector2i(0,100));
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
        if (!pause && !leftBounce)
        {
            cout << "left\n";
            leftBounce = true;
            currentView->leftClick();
        }
    }
    else
    {
        leftBounce = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (!pause && !rightBounce)
        {
            cout << "right\n";
            rightBounce = true;
            currentView->rightClick();
        }
    }
    else
    {
        rightBounce = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (!pause && !upBounce)
        {
            cout << "up\n";
            upBounce = true;
            currentView->upClick();
        }
    }
    else
    {
        upBounce = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (!pause && !downBounce)
        {
            cout << "down\n";
            downBounce = true;
            currentView->downClick();
        }
    }
    else
    {
        downBounce = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        if (typeid(currentView) == typeid(GameView) && !pauseBounce)
        {
            pauseBounce = true;
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
    else
    {
        pauseBounce = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
    {
        window.close();
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
        // So we get the current window
//        currentView = menuView->getWindow();
        // Clear screen, screen background is white.
        window.clear(sf::Color(120,120,120));
        // Update for currentView.
        currentView->update();
        // Update the window
        window.display();
    }
}
