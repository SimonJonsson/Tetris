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

/*
 * Constructor
 */
GameView::GameView(RenderWindow* windowptr)
{

    Vector2<int> fieldPosition = Vector2<int>(fieldPosX,fieldPosY);
    Vector2<int> nextPos = Vector2<int>(440,60);
    gameEngine = new GameEngine(fieldPosition,fieldHeight,fieldWidth,nextPos);

    coolFont.loadFromFile("res/fonts/nextwave.ttf");
    window = windowptr;

    initGraphics();
}

/*
 * Updatefunction for GameView. Handles all the graphics of game engine.
 */
void GameView::update()
{
    if (!paused)
        gameEngine->update(getFps());

    blockField = gameEngine->getBlockField();
    currentFigure = gameEngine->getCurrentFigure();
    nextFigure = gameEngine->getNextFigure();
    score = gameEngine->getScore();
    scoreNumText.setString(to_string(score));
    draw();

    if (gameEngine->isGameOver())
    {
        gameOver = true;
    }
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

    drawGrid();
    // If we are paused, we do not wish to see the figures, nor the figure box (prevents cheating)
    if (!paused)
    {
        window->draw(nextFigureBox);
        window->draw(nextFigureText);
        drawFigures();
    }
    else
    {
        pauseSplash();
    }
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

// Gets the FPS
float GameView::getFps()
{
    currentTime = clock.restart().asSeconds();
    fps = 1.f / currentTime;
    return fps;
}

// Returns the score
int GameView::getScore()
{
    return score;
}

void GameView::drawFigures()
{
    // Draws the 'active' figure
    if (currentFigure != nullptr)
    {
        for (auto i : currentFigure->getBlocks())
        {
            window->draw(*i);
           // cout << i->getPosition().x << "  " << i->getPosition().y;
        }
    }

    // Draws the next figure
    if (nextFigure != nullptr)
    {
        for (auto i : nextFigure->getBlocks())
        {
            window->draw(*i);
        }
    }

    // Draws all the blocks in the block field (placed figures)
    for (auto i : blockField)
    {
        window->draw(*i);
    }
}

/*
 * Splashes the gamescreen, so we cannot pause cheat
 */
void GameView::pauseSplash()
{
    window->draw(pauseText);
}

/*
 * Initializes the graphics
 */
void GameView::initGraphics()
{
    scoreWidth = scoreNumText.getGlobalBounds().width;

    background.setPosition(fieldPosX, fieldPosY);
    background.setFillColor(sf::Color::Black);

    // The score text "SCORE"
    scoreText.setFont(coolFont);
    scoreText.setString("SCORE");
    scoreText.setColor(textcolor);
    scoreText.setCharacterSize(40);
    scoreText.setPosition(fieldPosX,fieldPosY - fieldOffset - scoreText.getGlobalBounds().height - 27);

    // The score number
    scoreNumText.setFont(coolFont);
    scoreNumText.setString("1337");
    scoreNumText.setColor(textcolor);
    scoreNumText.setCharacterSize(40);
    scoreNumText.setPosition(fieldPosX + fieldWidth - scoreWidth,
                            fieldPosY - fieldOffset - scoreNumText.getGlobalBounds().height - 27);

    // The text that says "NEXT FIGURE"
    nextFigureText.setFont(coolFont);
    nextFigureText.setString("NEXT FIGURE");
    nextFigureText.setColor(textcolor);
    nextFigureText.setCharacterSize(40);
    nextFigureText.setPosition(fieldPosX + fieldWidth + fieldOffset,
                                scoreNumText.getPosition().y);

    // The box where the next figure is placed in
    nextFigureBox.setPosition(fieldPosX + fieldWidth + fieldOffset,
                                fieldPosY);
    nextFigureBox.setFillColor(sf::Color::Black);

    // The huge "PAUSE" text
    pauseText.setFont(coolFont);
    pauseText.setRotation(90);
    pauseText.setString("PAUSE");
    pauseText.setColor(textcolor);
    pauseText.setCharacterSize(200);
    pauseText.setPosition(400,100);
}

void GameView::pause(bool state)
{
    paused = state;
}

bool GameView::isGameOver()
{
    return gameOver;
}

void GameView::drawGrid()
{
int first = rand() % 255;
int last;
for(int row = fieldPosY; row <= fieldPosY+fieldHeight; row += 20)
{
    Vertex line[] =
    {
    Vertex(Vector2f(fieldPosX, row), Color(c1, c2, c3)),
    Vertex(Vector2f(fieldPosX+fieldWidth, row),Color(c4,c5,c6))
    };

    window->draw(line, 2,Lines);
}

for(int col = fieldPosX; col <= fieldPosX+fieldWidth; col += 20)
{
    Vertex line[] =
    {
    Vertex(Vector2f(col, fieldPosY), Color(c1, c2, c3)),
    Vertex(Vector2f(col, fieldPosY+fieldHeight),Color(c4,c5,c6))
    };

    window->draw(line, 2,Lines);
}

}
