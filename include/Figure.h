//Sofia & Patrik
#ifndef FIGURE_H
#define FIGURE_H
#include <array>
#include <SFML/Graphics.hpp>

class Figure
{
public:
    Figure();
    virtual ~Figure();

    std::array <std::array<int, 3>, 3> Figure_J;
    std::array <std::array<int, 3>, 3> Figure_L;
    std::array <std::array<int, 3>, 3> Figure_S;
    std::array <std::array<int, 3>, 3> Figure_T;
    std::array <std::array<int, 3>, 3> Figure_Z;
    std::array <std::array<int, 4>, 4> Figure_I;
    std::array <std::array<int, 2>, 2> Figure_O;

    //clone på figurerna?

    virtual void rotate() = 0;
    virtual void translate(int x, int y) = 0;

    sf::RectangleShape square; //våra byggstenar
    //square.setSize(sf::Vector2f(20,20)); //blockwidth lägg i konsturktorn

    // get_figure

    //std::vector<sf::RectangleShape*> blocks;

protected:
//std::array <std::array<int, int>, int> figmatrix;
// RectangleShape* figm[];
//i klasserna: figm = [[1,0,1],[1,0,1],[1,0,1]];

private:

int x{0};
int y{0};
int colour;

};

#endif // FIGURE_H
