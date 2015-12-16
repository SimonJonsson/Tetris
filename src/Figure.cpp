#include "../include/Figure.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace sf;



Figure::Figure(Fig r)
{
//Vi använder enum för att hantera alla figurer i
//konstruktorn för Figure istället för att göra en
//ny klass för varje enskild figur.
//För varje unik figur finns ett motsvarande r.
    figenum = r;
    switch (r)
    {
        case Fig::I:
            figmatrix =  {
                {0, 0, 0, 0},
                {1, 1, 1, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
                };
            color = sf::Color::Magenta;
            break;

        case Fig::J:
             figmatrix = {
                 {1, 0, 0},
                 {1, 1, 1},
                 {0, 0, 0}
                 };
            color = sf::Color::Blue;
            break;
        case Fig::L:
            figmatrix = {
                {0, 0, 1},
                {1, 1, 1},
                {0, 0, 0}
                };
            color = sf::Color::Green;
            break;
        case Fig::O:
            figmatrix = {
                {1, 1},
                {1, 1}
                };
            color = sf::Color(255, 51, 0);
            break;
        case Fig::S:
            figmatrix = {
                {0, 1, 1},
                {1, 1, 0},
                {0, 0, 0}
                };
            color = sf::Color(0,255,255);
            break;
        case Fig::T:
            figmatrix = {
                {0, 1, 0},
                {1, 1, 1},
                {0, 0, 0}
                };
            color = sf::Color(153, 102, 255);
            break;
        case Fig::Z:
            figmatrix = {
            {1, 1, 0},
            {0, 1, 1},
            {0, 0, 0}
            };
            color = sf::Color::Yellow;
            break;
    }

    pos.x = 0;
    pos.y = 0;

    //För att sätta in blocks i matrisen
    for(int j = 0; j <= figmatrix.size() - 1; ++j)
    {
        for(int i = 0; i <= figmatrix[j].size() - 1; ++i)
        {
            if(figmatrix[j][i] == 1)
            {
                RectangleShape* block = new RectangleShape(sf::Vector2f(blocksize,blocksize));
                block->setPosition(sf::Vector2f(blocksize*i,blocksize*j));
                block->setFillColor(Figure::color);
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
if(figenum == Fig::J || figenum == Fig::L || figenum == Fig::S || figenum == Fig::T || figenum == Fig::Z)
{
//Tar in en temporär tom matris som vi utför rotationen på
//för att slippa rotera den ursprungliga matrisen.

        vector<vector<int>> temp = {
         {0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}
         };

//Beräknar positionen på figurmatrisens övre vänstra hörn
    int xpos{0};
    int ypos{0};
    bool found = false;

    for (int r = 0; r < figmatrix.size(); ++r)
    {
        for (int c = 0; c < figmatrix.size(); ++c)
        {
            if(figmatrix[r][c] == 1 && !(found))
            {
                xpos = blocks[0]->getPosition().x - blocksize*c;
                ypos = blocks[0]->getPosition().y - blocksize*r;
                found = true;
            }
        }
    }

//Rotationsfunktionen
    for (int r = 0; r < figmatrix.size(); ++r)
    {
        for (int c = 0; c < figmatrix.size() ; ++c)
        {
            temp[c][figmatrix.size() - 1 -r] = figmatrix[r][c];
        }
    }

    figmatrix = temp;

    //För att sätta in blocks i den roterade matrisen
    int index = 0;
    for (int r = 0; r < figmatrix.size(); ++r)
    {
        for (int c = 0; c < figmatrix.size() ; ++c)
        {
            if(figmatrix[r][c] == 1)
            {
                RectangleShape* block = blocks[index];
                block->setPosition(Vector2f(xpos+ blocksize*c, ypos + blocksize*r));
                index++;
            }
        }
    }

}

else if(figenum == Fig::I)
{
        vector<vector<int>> temp = {
         {0, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}
         };

    int xpos{0};
    int ypos{0};

    bool found = false;

    for (int r = 0; r < figmatrix.size(); ++r)
    {
        for (int c = 0; c < figmatrix.size() ; ++c)
        {
            if(figmatrix[r][c] == 1 && !(found))
            {
                xpos = blocks[0]->getPosition().x - blocksize*c;
                ypos = blocks[0]->getPosition().y - blocksize*r;
                found = true;
            }
        }
    }

    cout << xpos << endl;
    cout << ypos << endl;

    for (int r = 0; r < figmatrix.size(); ++r)
    {
        for (int c = 0; c < figmatrix.size() ; ++c)
        {
            temp[c][figmatrix.size() - 1 -r] =
            figmatrix[r][c];
        }
    }

    figmatrix = temp;

    //För att sätta in blocks i den roterade matrisen
    int index = 0;
    for (int r = 0; r < figmatrix.size(); ++r)
    {
        for (int c = 0; c < figmatrix.size() ; ++c)
        {
            if(figmatrix[r][c] == 1)
            {
                RectangleShape* block = blocks[index];
                block->setPosition(Vector2f(xpos+ blocksize*c, ypos + blocksize*r));
                index++;
            }
        }
    }
}

}


void Figure::translate(int x, int y)
{
        for(int j = 0; j <= blocks.size() - 1; ++j)
        {
            RectangleShape* b = blocks[j];
            b->setPosition(Vector2f(blocksize*x + (b->getPosition()).x, blocksize*y + (b->getPosition()).y));
        }
}

void Figure::setPos(int x, int y)
{
     for(int j = 0; j <= blocks.size() - 1; ++j)
        {
            RectangleShape* b = blocks[j];
            b->setPosition(Vector2f(-pos.x + (b->getPosition()).x, -pos.y + (b->getPosition()).y));
        }

    pos.x = x;
    pos.y = y;
     for(int j = 0; j <= blocks.size() - 1; ++j)
        {
            RectangleShape* b = blocks[j];
            b->setPosition(Vector2f(x + (b->getPosition()).x, y + (b->getPosition()).y));
        }
}

