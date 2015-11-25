// Axel och Mathilda
#include "../include/MenuView.h"
#include <iostream>
#include <SFML/Graphics/Color.hpp>

using namespace std;

sf::Color background(120,120,120);
sf::Color highlight(200,80,160);
sf::Color textcolor(255,0,0);

MenuView::MenuView(sf::RenderWindow* windowptr)
{
    //Laddar in den font som ska användas för texten
    coolFont.loadFromFile("res/fonts/nextwave.ttf");

    //Finjusterar de olika datamedlemmarna med avseende på
    //position, storlek, färg, osv.
    StartGame_button.setPosition(150, 150);
    StartGame_button.setFillColor(sf::Color::Black);
    StartGame_button.setOutlineThickness(5);
    StartGame_button.setOutlineColor(highlight);

    StartGame_text.setFont(coolFont);
    StartGame_text.setString("Play Game");
    StartGame_text.setColor(textcolor);
    StartGame_text.setCharacterSize(40);
    StartGame_text.setPosition(160, 140);

    Highscore_button.setPosition(150, 230);
    Highscore_button.setFillColor(sf::Color::Black);
    Highscore_button.setOutlineThickness(5);
    Highscore_button.setOutlineColor(background);

    Highscore_text.setFont(coolFont);
    Highscore_text.setString("higH Score");
    Highscore_text.setColor(textcolor);
    Highscore_text.setCharacterSize(40);
    Highscore_text.setPosition(155, 220);

    Exit_button.setPosition(150, 310);
    Exit_button.setFillColor(sf::Color::Black);
    Exit_button.setOutlineThickness(5);
    Exit_button.setOutlineColor(background);

    Exit_text.setFont(coolFont);
    Exit_text.setString("Exit");
    Exit_text.setColor(textcolor);
    Exit_text.setCharacterSize(40);
    Exit_text.setPosition(210, 300);

    window = windowptr;
}
/*
MenuView::~MenuView()
{
    //dtor
}

*/
void MenuView::update()
{
    window->draw(StartGame_button);
    window->draw(StartGame_text);
    window->draw(Highscore_button);
    window->draw(Highscore_text);
    window->draw(Exit_button);
    window->draw(Exit_text);
}

void MenuView::leftClick()
{

}

void MenuView::rightClick()
{

}

void MenuView::upClick()
{
    //Ändrar vilket av alternativen som ska highlightas
    if(StartGame_button.getOutlineColor() == highlight)
    {
        Exit_button.setOutlineColor(highlight);
        StartGame_button.setOutlineColor(background);
    }
    else if(Highscore_button.getOutlineColor() == highlight)
    {
        StartGame_button.setOutlineColor(highlight);
        Highscore_button.setOutlineColor(background);
    }
    else
    {
        Highscore_button.setOutlineColor(highlight);
        Exit_button.setOutlineColor(background);
    }
}

void MenuView::downClick()
{
    //Ändrar vilket av alternativen som ska highlightas
    if(StartGame_button.getOutlineColor() == highlight)
    {
        Highscore_button.setOutlineColor(highlight);
        StartGame_button.setOutlineColor(background);
    }
    else if(Highscore_button.getOutlineColor() == highlight)
    {
        Exit_button.setOutlineColor(highlight);
        Highscore_button.setOutlineColor(background);
    }
    else
    {
        StartGame_button.setOutlineColor(highlight);
        Exit_button.setOutlineColor(background);
    }

}
