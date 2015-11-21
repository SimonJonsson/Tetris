#include "../include/ViewHandler.h"
#include <iostream>

using namespace std;

ViewHandler::ViewHandler()
{

    menuView        = new MenuView{};
    highScoreView   = new HighScoreView{};
    gameView        = new GameView{};
    gameOverView    = new GameOverView{};
    currentView = gameView;
}

//Main function for updating the window
void ViewHandler::initiate()
{
    //window.setFramerateLimit(60);

    sf::RenderWindow window(sf::VideoMode(700, 800), "Tetris");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen, screen background is white.
        window.clear(sf::Color::White);

        currentView->update(window);

        // Update the window
        window.display();
    }
}
