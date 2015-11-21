#include <SFML/Graphics.hpp>
#include "Figure.h"
#include <vector>

class GameEngine
{
private:
    std::vector<sf::Shape> field;
    std::vector<sf::Shape> borders;
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
    GameEngine() = default;
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

};
