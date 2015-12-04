/*
 * TDDC76 - MAT3 - Group 5
 *
 * IDENTIFIERING
 *
 * Filnamn:    GameView.cc
 * Enhetsnamn: GameView
 * Revision:   1
 * Skriven av: Simon Jönsson
 *
 *
 * BESKRIVNING
 *
 * See .h
 *
 * REVISIONSBERÄTTELSE
 *
 * Revision     Datum   Förändringar
 *
 * 1            940319  Ursprungsversion
 */
#include "../include/GameView.h"
#include <iostream>
using namespace std;
using namespace sf;

GameView::GameView(sf::RenderWindow* windowptr)
{
    gameEngine = new GameEngine(700,800,fieldWidth,fieldHeight);

    coolFont.loadFromFile("res/fonts/nextwave.ttf");
    window = windowptr;

    scoreWidth = scoreNumText.getGlobalBounds().width;

    background.setPosition(fieldPosX, fieldPosY);
    background.setFillColor(sf::Color::Black);

    scoreText.setFont(coolFont);
    scoreText.setString("SCORE");
    scoreText.setColor(textcolor);
    scoreText.setCharacterSize(40);
    scoreText.setPosition(fieldPosX,fieldPosY - fieldOffset - scoreText.getGlobalBounds().height - 27);

    scoreNumText.setFont(coolFont);
    scoreNumText.setString("1337");
    scoreNumText.setColor(textcolor);
    scoreNumText.setCharacterSize(40);
    scoreNumText.setPosition(fieldPosX + fieldWidth - scoreWidth,
                            fieldPosY - fieldOffset - scoreNumText.getGlobalBounds().height - 27);

    nextFigureText.setFont(coolFont);
    nextFigureText.setString("NEXT FIGURE");
    nextFigureText.setColor(textcolor);
    nextFigureText.setCharacterSize(40);
    nextFigureText.setPosition(fieldPosX + fieldWidth + fieldOffset,
                                scoreNumText.getPosition().y);

    nextFigureBox.setPosition(fieldPosX + fieldWidth + fieldOffset,
                                fieldPosY);
    nextFigureBox.setFillColor(sf::Color::Black);


}

/*
 * Updatefunction for GameView. Handles all the graphics of game engine.
 */
void GameView::update()
{
    gameEngine->update(getFps());
    cout << getFps() << endl;
    //blockField = gameEngine->getBlockField();
    currentFigure = gameEngine->getCurrentFigure();
    //nextFigure = gameEngine->getNextFigure();
    score = gameEngine->getScore();
    //scoreNumText.setString(to_string(score));
    draw();
}

/*
 * Drawfunction for all the objects
 */
void GameView::draw()
{
    window->draw(background);
    window->draw(scoreText);

    scoreWidth = scoreNumText.getGlobalBounds().width;
    scoreNumText.setPosition(fieldPosX + fieldWidth - scoreWidth,
                            fieldPosY - fieldOffset - scoreNumText.getGlobalBounds().height - 27);

    window->draw(scoreNumText);
    window->draw(nextFigureBox);
    window->draw(nextFigureText);
    drawFigures();

}

/*
 * All the keybindings for the GameView.
 */
void GameView::leftClick()
{
    gameEngine->leftClick();
}

void GameView::rightClick()
{
    gameEngine->rightClick();
}

void GameView::upClick()
{
    gameEngine->upClick();
}

void GameView::downClick()
{
    gameEngine->downClick();
}

float GameView::getFps()
{
    currentTime = clock.restart().asSeconds();
    fps = 1.f / currentTime;
    return fps;
}

int GameView::getScore()
{
    return score;
}

void GameView::drawFigures()
{
    if (currentFigure != nullptr)
    {
        for (sf::RectangleShape* i : currentFigure->getBlocks())
        {
            window->draw(*i);
           // cout << i->getPosition().x << "  " << i->getPosition().y;
        }
    }
/*
    if (nextFigure != nullptr)
    {
        for (auto i : nextFigure->getBlocks())
        {
            window->draw(*i);
        }
    }*/
    /*
    for (auto i : blockField)
    {
        window->draw(*i);
    }*/
}
