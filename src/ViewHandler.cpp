#include "../include/ViewHandler.h"

using namespace std;

ViewHandler::ViewHandler()
{
//  menuView        = new MenuView{};
//  highScoreView   = new HighScoreView{};
    gameView        = new GameView{};
//  gameOverView    = new GameOverView{};
    currentView = gameView;
}

//Main function for updating the window
void ViewHandler::initiate()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");
    sf::View view;

    // Initialize the view to a rectangle located at (100, 100) and with a size of 400x200
    view.reset(sf::FloatRect(100, 100, 100, 100));
    // Set its target viewport to be half of the window
    view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
    // Apply it
    window.setView(view);
    // Set the default view back
    window.setView(window.getDefaultView());
    // Render stuff not affecte
    sf::Font font;
    sf::Text text("Hello SFML", font, 50);

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
        // Clear screen
        window.clear();
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
}
