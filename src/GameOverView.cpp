#include "../include/GameOverView.h"
#include <string>
#include <fstream>

using namespace std;

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

void GameOverView::update()
{
    window->draw(GameOver_text);
    if(highscore)
    {
        //Do stuff!
    }
    else
    {
        //Don't do stuff!
    }
}

void GameOverView::readHighScores()
{
    HighScoreInfo highScoreEntry;
    ifstream infile("res/highscore.txt");
    string inputString{""};

    while(infile >> inputString)
    {
        if(highScoreEntry.name == "")
            highScoreEntry.name = inputString;
        else
        {
            highScoreEntry.score = stoi(inputString);
            highscores.push_back(highScoreEntry);
            highScoreEntry.name = "";
        }
    }
    infile.close();
}

int GameOverView::compareScore()
{
    readHighScores();
    int pos{0};
    while(score < (highscores.at(pos)).score && pos < 10)
        ++pos;

    return pos;
}

void GameOverView::checkScore()
{
    highscore = (compareScore() < 10);
}

void GameOverView::updateHighScore()
{

}

void GameOverView::setName(const string& newName)
{
    name = newName;
}

void GameOverView::setScore(const int& newScore)
{
    score = newScore;
}

string GameOverView::getName()
{
    return name;
}

int GameOverView::getScore()
{
    return score;
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
