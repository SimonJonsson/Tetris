//Sofia & Patrik
#ifndef FIGURE_H
#define FIGURE_H
#include <array>
#include <vector>
#include <SFML/Graphics.hpp>




class Figure
{
public:
//static enum t;
    Figure();
    virtual ~Figure();

/*  std::array <std::array<int, 3>, 3> Figure_J;
    std::array <std::array<int, 3>, 3> Figure_L;
    std::array <std::array<int, 3>, 3> Figure_S;
    std::array <std::array<int, 3>, 3> Figure_T;
    std::array <std::array<int, 3>, 3> Figure_Z;
    std::array <std::array<int, 4>, 4> Figure_I;
    std::array <std::array<int, 2>, 2> Figure_O;
*/


    virtual void rotate() = 0;
    void translate(int x, int y);


std::vector<sf::RectangleShape*> getBlocks();



protected:
std::vector<std::vector<int>> temp;


sf::Vector2f pos;
//std::array <std::array<int,  int>,  int> figmatrix;
std::vector<std::vector<int>> figmatrix;
std::vector<sf::RectangleShape*> blocks;
//i klasserna: figm = [[1,0,1],[1,0,1],[1,0,1]];

sf::Color color;

private:

int x{0};
int y{0};

};

#endif // FIGURE_H
