#include "../include/GameOverView.h"



GameOverView::GameOverView(sf::RenderWindow* windowptr)
{
    //Laddar in den font som ska användas för texten
   coolFont.loadFromFile("res/fonts/nextwave.ttf");

    //Finjusterar de olika datamedlemmarna med avseende på
    //position, storlek, färg, osv.
    GameOver_text.setFont(coolFont);
    GameOver_text.setString("Game over");
    GameOver_text.setColor(sf::Color::Blue);
    GameOver_text.setCharacterSize(100);
    GameOver_text.setPosition(100, 10);
    GameOver_text.setStyle(sf::Text::Underlined);

    window = windowptr;
}



/* //Ni har en default destruktor
GameOverView::~GameOverView()
{
    //dtor
}
*/

void GameOverView::update()
{
    window->draw(GameOver_text);
}

void GameOverView::leftClick()
{

}

void GameOverView::rightClick()
{

}

void GameOverView::upClick()
{

}

void GameOverView::downClick()
{

}
