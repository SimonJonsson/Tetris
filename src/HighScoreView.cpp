#include "../include/HighScoreView.h"
#include <iostream>
#include <SFML/Graphics/Color.hpp>





HighScoreView::HighScoreView(sf::RenderWindow* windowptr)
{
    //Laddar in den font som ska användas för texten
    coolFont.loadFromFile("res/fonts/nextwave.ttf");

    //Finjusterar de olika datamedlemmarna med avseende på
    //position, storlek, färg, osv.
    HighScore_text.setFont(coolFont);
    HighScore_text.setString("higH Score");
    HighScore_text.setColor(sf::Color::Blue);
    HighScore_text.setCharacterSize(70);
    HighScore_text.setPosition(200, 10);
    HighScore_text.setStyle(sf::Text::Underlined);

    window = windowptr;
}

/*
HighScoreView::~HighScoreView()
{
    //dtor
}
*/

void HighScoreView::update()
{
    window->draw(HighScore_text);
}

void HighScoreView::leftClick()
{
    //currentView = MenuView
}

void HighScoreView::rightClick()
{

}

void HighScoreView::upClick()
{

}

void HighScoreView::downClick()
{

}
