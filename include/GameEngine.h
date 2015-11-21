//Grayson
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include "Figure.h"
#include <vector>

typedef sf::Vector2<int> Position;

class GameEngine
{
private:
    int wHeight;
    int wWidth;
    int bHeight;
    int bWidth;
    Position boardPos;
    std::vector<sf::Shape*> field(500); //Init room for about half of board
  //  (RectangleShape*) borders[4];
    Figure* currentFigure;
    Figure* nextFigure;
    int difficulty = 0;
    int velocity = 0;
    long score = 0;

    void update(long dt);
    void updateVelocity();
    void translate(Figure* fig, int x, int y);
    void translate(sf::Shape* block, int x, int y);
    sf::Shape* collides(Figure* fig); //Check if figure collides with field/borders
    void placeFigure(Figure* fig);
    int clearFullRows(); //Returns # rows removed
    void updateScore(long amount);

public:
    GameEngine(int windowHeight, int windowWidth, int boardHeight, int boardWidth);
    ~GameEngine() = default;

    void leftClick();
    void rightClick();
    void upClick();
    void downClick();

    bool isGameOver();
    std::vector<sf::Shape> getPlayingField();
    std::vector<sf::Shape> getBorders();
    Figure* getCurrentFigure();
    Figure* getNextFigure();
    long getScore();
    void operator=(GameEngine& ) = delete;

};


#endif
