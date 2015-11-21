#include "../include/ViewHandler.h"

using namespace std;

ViewHandler::ViewHandler()
{
//  menuView        = new MenuView{};
//  highScoreView   = new HighScoreView{};
//    gameView        = new GameView{window};
//  gameOverView    = new GameOverView{};
}

//Main function for updating the window
void ViewHandler::initiate()
{
    sf::RenderWindow window;
    sf::View view;
    // Initialize the view to a rectangle located at (100, 100) and with a size of 400x200
    view.reset(sf::FloatRect(100, 100, 400, 200));
    // Rotate it by 45 degrees
    view.rotate(45);
    // Set its target viewport to be half of the window
    view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
    // Apply it
    window.setView(view);
    // Set the default view back
    window.setView(window.getDefaultView());
    // Render stuff not affected by the view

    window.display();

}
