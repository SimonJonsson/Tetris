/*
 * TDDC76 - MAT3 - Group 5
 *
 * IDENTIFIERING
 *
 * Filnamn:    Figure.h
 * Skriven av: Sofia Svensson & Patrik Petters
 *
 *
 *
 *
 */

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

    sf::Vector2f pos;
    void rotate();
    void translate(int x, int y);
    void setPos(int x, int y);
    Fig figenum;
    std::vector<sf::RectangleShape*> getBlocks();

protected:
    std::vector<std::vector<int>> temp;
    std::vector<std::vector<int>> figmatrix;
    std::vector<sf::RectangleShape*> blocks;

    sf::Color color;

private:
    sf::Texture texture;
    int blocksize = 20;

};

#endif
