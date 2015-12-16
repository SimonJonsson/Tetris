//Sofia & Patrik
#ifndef FIGURE_H
#define FIGURE_H
#include <array>
#include <vector>
#include <SFML/Graphics.hpp>


enum Fig {I, J, L, O, S, T, Z};

class Figure
{
public:
    Figure(Fig r);
    virtual ~Figure();

    void rotate();
    void translate(int x, int y);
    void setPos(int x, int y);

    std::vector<sf::RectangleShape*> getBlocks();

protected:
    Fig figenum;
    std::vector<std::vector<int>> temp;

    sf::Vector2f pos;
    std::vector<std::vector<int>> figmatrix;
    std::vector<sf::RectangleShape*> blocks;

    sf::Color color;

private:
    int blocksize = 20;

};

#endif // FIGURE_H
