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

    GameOver_message.setFont(coolFont);
    GameOver_message.setColor(textcolor);
    GameOver_message.setCharacterSize(50);
    GameOver_message.setPosition(100, 150);

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
        GameOver_message.setString("You got a high score!");
        window->draw(Input_field);
        window->draw(Input_text);
        if(Input_text.getString() != "")
            entered_name = true;
        else
            entered_name = false;
    }
    else
        GameOver_message.setString("You did not get a high score!");
    window->draw(GameOver_message);
}

void GameOverView::readHighScores()
{
    highscores.clear();
    HighScoreInfo highScoreEntry;
    ifstream infile("res/highscore.txt");
    string inputString{""};

    //läser från highscorelistan till highscores
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

    for(int i = 0; i < highscores.size(); ++i)
        cout << highscores[i].name << " " << highscores[i].score << endl;
}

int GameOverView::compareScore()
{
    readHighScores();
    pos = 0;
    if(highscores.size() > 0)
        while(pos < highscores.size() && score < highscores[pos].score)
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
        ofstream outfile("res/highscore.txt", ios::out);

        if(highscores.size() == 0)
            outfile << getName() << " " << getScore() << endl;
        else
        {
            HighScoreInfo input;
            input.name = getName();
            input.score = getScore();
            vector<HighScoreInfo>::iterator it = highscores.begin();

            int n{0};

            while(n < highscores.size() && n < 10)
            {
                if(n == pos)
                    highscores.insert(it, input);

                outfile << highscores[n].name << " " << highscores[n].score << endl;

                if(n != pos)
                    ++it;
                ++n;
            }

            if(pos == highscores.size())
                outfile << input.name << " " << input.score << endl;
        }
        outfile.close();
    }
    Input_text.setString("");
    setName("");
}

void GameOverView::upClick()
{

}

void GameOverView::downClick()
{

}
