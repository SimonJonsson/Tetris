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
    HighScore_title.setColor(textcolor);
    HighScore_title.setCharacterSize(70);
    HighScore_title.setPosition(200, 10);
    HighScore_title.setStyle(sf::Text::Underlined);

    window = windowptr;

    //Läser in highscores. Måste läsas in varje gång denna klass blir current view
    readHighscore();
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
    for(int i{0}; i < highscores.size(); ++i)
    {
        window->draw((highscores.at(i)).name);
        window->draw((highscores.at(i)).score);
    }
}

void HighScoreView::readHighscore()
{
    //Temporära objekt som används för att lägga in värden i
    //highscore-listan.
    highscores.clear();
    HighScore highScoreEntry;
    sf::Text inputText;

    inputText.setFont(coolFont);
    inputText.setCharacterSize(30);
    inputText.setColor(textcolor); //färgschemat ska vara entydigt
    inputText.setPosition(200, 100);

    ifstream infile("res/highscore.txt");
    string inputString{""};

    //positionen är till för att utföra kontroller när vi läser från filen,
    //samt ange var i fönstret textobjekten ska ligga.
    sf::Vector2f positionCheck{200,100};

    int place{1};

    while(infile >> inputString)
    {
        //I första fallet så är det ett namn som ska läsas in.
        if(positionCheck.x == 200)
        {
            inputText.setString(to_string(place) + ". " + inputString);
            highScoreEntry.name = inputText;
            positionCheck.x += 250;
            ++place;
        }
        //Annars ska poängen läsas in
        else
        {
            inputText.setString(inputString);
            highScoreEntry.score = inputText;
            highscores.push_back(highScoreEntry);
            positionCheck.x = 200;
            positionCheck.y += 50;
        }

        //Uppdatering av var nästa textobjekt ska
        //vara i fönstret
        inputText.setPosition(positionCheck);
    }
    infile.close();
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
