#include "../include/HighScoreView.h"
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <fstream>

using namespace std;

HighScoreView::HighScoreView(sf::RenderWindow* windowptr)
{
    //Laddar in den font som ska användas för texten
    coolFont.loadFromFile("res/fonts/nextwave.ttf");

    //Finjusterar de olika datamedlemmarna med avseende på
    //position, storlek, färg, osv.
    HighScore_title.setFont(coolFont);
    HighScore_title.setString("higH Score");
    HighScore_title.setColor(sf::Color::Blue);
    HighScore_title.setCharacterSize(70);
    HighScore_title.setPosition(200, 10);
    HighScore_title.setStyle(sf::Text::Underlined);

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
    window->draw(HighScore_title);
}

void HighScoreView::readHighscore()
{
    HighScore highScoreEntry;
    sf::Text inputText;

    inputText.setFont(coolFont);
    inputText.setCharacterSize(30);
    inputText.setColor(sf::Color::Black);
    inputText.setPosition(50, 100);

    ifstream infile("res/highscore.txt");
    string inputString{""};
    sf::Vector2f positionCheck;

    while(infile >> inputString)
    {
        if(positionCheck.x == 50)
        {

        }
    }


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
