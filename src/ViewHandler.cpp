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
#include <typeinfo>

using namespace std;

//Instantiates all the views
ViewHandler::ViewHandler()
{
    menuView        = new MenuView(&window);
    highScoreView   = new HighScoreView(&window);
    gameView        = new GameView(&window);
    gameOverView    = new GameOverView(&window);

    //Preliminary test for gameOverView
    gameOverView->checkScore();
    changeView("MenuView");
}


/*
 * Main function for updating the window
 */
void ViewHandler::initiate()
{
    //Creates a window with height, width, title and disables resizing of window
    window.create(sf::VideoMode(windowWidth,windowHeight),"Tetris",sf::Style::Close);
    window.setPosition(sf::Vector2i(0,100));
    window.setFramerateLimit(60);

    // Start the game loop
    while (window.isOpen())
    {
        outputHandler();
        eventHandler();
        inputHandler();
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
        if (event.type == sf::Event::GainedFocus && typeid(*currentView) == typeid(GameView))
            pause = false;

        if (event.type == sf::Event::LostFocus && typeid(*currentView) == typeid(GameView))
            pause = true;

        if(currentView == gameOverView)
        {
            gameOverView->eventhandler(event);
        }
    }
}

/*
 * The keybindings for all views
 * This must also have a debounce function, to prevent spam
 */
void ViewHandler::inputHandler()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        leftTimer++;
        if (leftTimer > noBounces*2)
        {
            leftBounce = false;
            leftTimer = 0;
        }

        if (!pause && !leftBounce)
        {
            cout << "left\n";
            leftBounce = true;
            currentView->leftClick();

            if (typeid(*currentView) == typeid(HighScoreView)
                || typeid(*currentView) == typeid(GameOverView))
            {
                changeView("MenuView");
            }
        }
    }
    else
    {
        leftBounce = false;
        leftTimer = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rightTimer++;
        if (rightTimer > noBounces*2)
        {
            rightBounce = false;
            rightTimer = 0;
        }

        if (!pause && !rightBounce)
        {
            cout << "right\n";
            rightBounce = true;
            currentView->rightClick();

            // If we are in menuview we wanna be able to change view
            if (typeid(*currentView) == typeid(MenuView))
            {
                focus = menuView->getFocus();
                if (focus == "Exit")
                {
                    window.close();
                }
                else
                {
                    changeView(focus);
                }

            }
        }
    }
    else
    {
        rightBounce = false;
        rightTimer = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        upTimer++;
        if (upTimer > standardBounces)
        {
            upBounce = false;
            upTimer = 0;
        }

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
        upTimer = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        downTimer++;
        if (downTimer > noBounces)
        {
            downBounce = false;
            downTimer = 0;
        }

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
        downTimer = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        if (typeid(*currentView) == typeid(GameView) && !pauseBounce)
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
            gameView->pause(pause);
        }
    }
    else
    {
        pauseBounce = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
    {
        changeView("MenuView");
    }
}

/*
 * Handles the outputs for ViewHandler
 * including all update functions
 */
void ViewHandler::outputHandler()
{
    // Clear screen, screen background is white.
    window.clear(sf::Color(60,60,60));
    // Update for currentView.
    currentView->update();
    // Update the window
    window.display();
}

/*
 * Changes the currentView to desired new view.
 */
void ViewHandler::changeView(string newView)
{
    noBounces = standardBounces;
    if(newView == "MenuView")
    {
        currentView = menuView;
    }
    else if (newView == "HighScoreView")
    {
        currentView = highScoreView;
        highScoreView->readHighscore();
    }
    else if (newView == "GameView")
    {
        noBounces = gNoBounces;
        currentView = gameView;
    }
    else if (newView == "GameOverView")
    {
        currentView = gameOverView;
        gameOverView->setScore(gameView->getScore());
    }
    else
    {
        cerr << "There exists no window: \"" << newView << "\"\n";
    }

}
