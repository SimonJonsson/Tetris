#include "../include/Figure.h"
#include <vector>
using namespace std;
using namespace sf;


Figure::Figure()
{
    pos.x = 0;
    pos.y = 0;

    for(int i = 0; i <= figmatrix.size() - 1; ++i)
    {
        for(int j = 0; j <= figmatrix[i].size() - 1; ++j)
        {
            if(figmatrix[i][j] = 1)
            {
                RectangleShape* block = new RectangleShape(sf::Vector2f(20,20));
                block->setPosition(sf::Vector2f(20*i,20*j));
                block->setFillColor(color);
                blocks.push_back(block);
            }
        }
    }
}

Figure::~Figure()
{
}

vector<RectangleShape*> Figure::getBlocks()
{
return blocks;
}


void Figure::rotate()
{
}

// x -1 , 20 pixlar vänster, x=1, 20 pix hög. y=-1 20 upp, y=1 20 ner.

void Figure::translate(int x, int y)
{
    pos.x = pos.x + 20*x;
    pos.y = pos.y + 20*y;

    for(int i = 0; i <= figmatrix.size() - 1; ++i)
    {
        for(int j = 0; j <= figmatrix[i].size() - 1; ++j)
        {
            RectangleShape* b = new RectangleShape(Vector2f(20,20));
            b->setPosition(Vector2f(pos.x + (b->getPosition()).x, pos.y + (b->getPosition()).y));
        }
    }

}
