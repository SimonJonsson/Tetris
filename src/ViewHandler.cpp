#include "../include/ViewHandler.h"

using namespace std;

ViewHandler::ViewHandler()
{
    sf::Window window(sf::VideoMode(800, 600), "SFML window");
//    menuView        = new MenuView{};
  //  highScoreView   = new HighScoreView{};
    //gameView        = new GameView{window};
    //gameOverView    = new GameOverView{};
}

//Main function for updating the window
void ViewHandler::initiate()
{
 //Hej!
    // Create the main window. test
    sf::Window window(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
    sf::Sprite sprite(texture);

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


        // Draw the sprite
//        app.draw(sprite);

        // Update the window
        window.display();
    }

}
