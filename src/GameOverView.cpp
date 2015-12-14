#include "../include/GameOverView.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;

GameOverView::GameOverView(sf::RenderWindow* windowptr)
{
    //Laddar in den font som ska användas för texten
   coolFont.loadFromFile("res/fonts/nextwave.ttf");

    //Finjusterar de olika datamedlemmarna med avseende på
    //position, storlek, färg, osv.
    GameOver_text.setFont(coolFont);
    GameOver_text.setString("Game over");
    GameOver_text.setColor(textcolor);
    GameOver_text.setCharacterSize(100);
    GameOver_text.setPosition(100, 10);
    GameOver_text.setStyle(sf::Text::Underlined);

    Input_text.setFont(coolFont);
    Input_text.setColor(sf::Color::Black);
    Input_text.setCharacterSize(20);
    Input_text.setPosition(100, 250);

    Input_field.setPosition(95, 245);
    Input_field.setFillColor(sf::Color::White);


    window = windowptr;
}

void GameOverView::update()
{
    window->draw(GameOver_text);
    if(highscore)
    {
        window->draw(Input_field);
        window->draw(Input_text);
        if(Input_text.getString() != "")
            entered_name = true;
        else
            entered_name = false;
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
    pos = 0;
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
    Input_text.setString(name);
}

void GameOverView::setScore(const int& newScore)
{
    score = newScore;
}

string GameOverView::getName()
{
    return name;
}

bool GameOverView::getHighScore()
{
    return highscore;
}

int GameOverView::getScore()
{
    return score;
}

void GameOverView::eventhandler(sf::Event& event)
{
    if(highscore && event.type == sf::Event::TextEntered && getName().size() < 12)
    {
        char input = static_cast<char>(event.text.unicode);
        if(isalnum(input))
            setName(getName()+ input);
    }
}

void GameOverView::leftClick()
{

}

void GameOverView::rightClick()
{
    if(getName().size() > 0)
    {
        HighScoreInfo input;
        input.name = getName();
        input.score = getScore();
        vector<HighScoreInfo>::iterator it = highscores.begin();
        ofstream outfile;
        outfile.open("res/highscore.txt", ostream::trunc);
        int n{0};
        const char* spacechar = " ";
        const char* newlinechar = "\n";

        while(n < highscores.size())
        {
            if(n == pos)
                highscores.insert(it, input);

            outfile.write(highscores[n].name.c_str(), highscores[n].name.size());
            outfile.write(spacechar, 1);
            outfile.write((to_string(highscores[n].score)).c_str(), to_string(highscores[n].score).size());
            outfile.write(newlinechar, 1);

            if(n != pos)
                ++it;
            ++n;
        }
        outfile.close();
    }
}

void GameOverView::upClick()
{

}

void GameOverView::downClick()
{

}
