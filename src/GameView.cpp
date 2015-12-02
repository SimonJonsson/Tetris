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

using namespace std;


GameView::GameView(sf::RenderWindow* windowptr)
{

    coolFont.loadFromFile("res/fonts/nextwave.ttf");
    window = windowptr;
    gameEngine = new GameEngine(700,800,fieldWidth,fieldHeight);

    scoreWidth = scoreNumText.getGlobalBounds().width;

    background.setPosition(fieldPosX, fieldPosY);
    background.setFillColor(sf::Color::Black);

    scoreText.setFont(coolFont);
    scoreText.setString("SCORE");
    scoreText.setColor(textcolor);
    scoreText.setCharacterSize(60);
    scoreText.setPosition(fieldPosX,
                        fieldPosY - fieldOffset - 60);

    scoreNumText.setFont(coolFont);
    scoreNumText.setString("1337");
    scoreNumText.setColor(textcolor);
    scoreNumText.setCharacterSize(60);
    scoreNumText.setPosition(fieldPosX + fieldWidth - scoreWidth,
                            fieldPosY - fieldOffset - 60);

    nextFigureText.setFont(coolFont);
    nextFigureText.setString("NEXT FIGURE");
    nextFigureText.setColor(textcolor);
    nextFigureText.setCharacterSize(40);
    nextFigureText.setPosition(fieldPosX + fieldWidth + fieldOffset,
                                fieldPosY - nextFigureText.getGlobalBounds().height);

    //nextFigureBox.setPosition(fieldPosX + fieldWidth + fieldOffset,
      //                          fieldPosY + nextFigureText.getGlobalBounds().);
    nextFigureBox.setFillColor(sf::Color::Black);


    cout << fieldPosY - nextFigureText.getGlobalBounds().height << endl;
}

/*
 * Updatefunction for GameView. Handles all the graphics of game engine.
 */
void GameView::update()
{
    gameEngine->update(getFps());

    score = gameEngine->getScore();
    scoreNumText.setString(to_string(score));
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
                            fieldPosY - fieldOffset - 60);

    window->draw(scoreNumText);
    window->draw(nextFigureText);
    window->draw(nextFigureBox);

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
