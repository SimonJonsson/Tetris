#include <../include/GameView.h>

using namespace std;

GameView::GameView()
{

}

void GameView::update(sf::RenderWindow& window)
{

    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
    {}
    sf::Sprite sprite(texture);

    window.draw(sprite);
}
