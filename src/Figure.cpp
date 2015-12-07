#include "../include/Figure.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace sf;

//enum class  Fig {I = 0, J, L, O, S, T,Z};

Figure::Figure()
{
    //För varje unik figur finns ett motsvarande r
    //r används för att skapa figuren i en switch sats => inga unika klasser behövs.
    //random r mellan (0 6)
    /*switch (r)
    {
        case 0:
             figmatrix = {
                 {1, 0, 0},
                 {1, 1, 1},
                 {0, 0, 0}
                 };
            break;
        case 1:
            figmatrix = {
                {1, 1},
                {1, 1}
                };
            break;
            osv...
    }*/

  figmatrix = {
         {1, 0, 0},
         {1, 1, 1},
         {0, 0, 0}
         };

    pos.x = 0;
    pos.y = 0;
     cout << "OK" << endl;
     cout << figmatrix.size();
     cout << "ok" << endl;
    for(int i = 0; i <= figmatrix.size() - 1; ++i)
    {
        for(int j = 0; j <= figmatrix[i].size() - 1; ++j)
        {
            if(figmatrix[i][j] == 1)
            {
                cout << "1" << endl;
                RectangleShape* block = new RectangleShape(sf::Vector2f(20,20));
                block->setPosition(sf::Vector2f(20*i+100,20*j+100));
                block->setFillColor(sf::Color::Blue);
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
    //Ungefär som denna
       /* for(int j = 0; j <= blocks.size() - 1; ++j)
        {
            RectangleShape* b = blocks[j];
            b->setPosition(Vector2f(20*x + (b->getPosition()).x, 20*y + (b->getPosition()).y));
        }*/
}

// x -1 , 20 pixlar vänster, x=1, 20 pix hög. y=-1 20 upp, y=1 20 ner.

void Figure::translate(int x, int y)
{
    //pos.x = pos.x + 20*x;
    //pos.y = pos.y + 20*y;

        for(int j = 0; j <= blocks.size() - 1; ++j)
        {
            RectangleShape* b = blocks[j];
            b->setPosition(Vector2f(20*x + (b->getPosition()).x, 20*y + (b->getPosition()).y));
        }

}

