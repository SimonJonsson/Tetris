#include "../include/Figure.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace sf;



Figure::Figure(Fig r)
{

    //För varje unik figur finns ett motsvarande r
    //r används för att skapa figuren i en switch sats => inga unika klasser behövs.
    //random r mellan (0 6)
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
            color = sf::Color::Red;
            break;
        case Fig::S:
            figmatrix = {
                {0, 1, 1},
                {1, 1, 0},
                {0, 0, 0}
                };
            color = sf::Color::White;
            break;
        case Fig::T:
            figmatrix = {
                {0, 1, 0},
                {1, 1, 1},
                {0, 0, 0}
                };
            color = sf::Color(250, 150, 100);
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

/*  figmatrix = {
         {1, 0, 0},
         {1, 1, 1},
         {0, 0, 0}
         };
*/

    pos.x = 0;
    pos.y = 0;
     cout << "OK" << endl;
     cout << figmatrix.size();
     cout << "ok" << endl;
    for(int j = 0; j <= figmatrix.size() - 1; ++j)
    {
        for(int i = 0; i <= figmatrix[j].size() - 1; ++i)
        {
            if(figmatrix[j][i] == 1)
            {
                cout << "1" << endl;
                RectangleShape* block = new RectangleShape(sf::Vector2f(blocksize,blocksize));
                block->setPosition(sf::Vector2f(blocksize*i,blocksize*j));
                block->setFillColor(Figure::color); //innan stod det sf::Color::color, men det fungerade inte
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
        vector<vector<int>> temp = {
         {0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}
         };

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

    cout << xpos << endl;
    cout << ypos << endl;

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp[c][2-r] =
            figmatrix[r][c];
        }
    }

    figmatrix = temp;

    //För att sätta in blocks i den roterade matrisen
    int index = 0;
    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
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

    for (int r = 0; r <= 3; ++r)
    {
        for (int c = 0; c <= 3 ; ++c)
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

    for (int r = 0; r <= 3; ++r)
    {
        for (int c = 0; c <= 3 ; ++c)
        {
            temp[c][3-r] =
            figmatrix[r][c];
        }
    }

    figmatrix = temp;

    //För att sätta in blocks i den roterade matrisen
    int index = 0;
    for (int r = 0; r <= 3; ++r)
    {
        for (int c = 0; c <= 3 ; ++c)
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

else
{
        vector<vector<int>> temp = {
         {0, 0},
         {0, 0},
         };

    int xpos{0};
    int ypos{0};

    bool found = false;

    for (int r = 0; r <= 1; ++r)
    {
        for (int c = 0; c <= 1 ; ++c)
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

    for (int r = 0; r <= 1; ++r)
    {
        for (int c = 0; c <= 1 ; ++c)
        {
            temp[c][1-r] =
            figmatrix[r][c];
        }
    }

    figmatrix = temp;

    //För att sätta in blocks i den roterade matrisen
    int index = 0;
    for (int r = 0; r <= 1; ++r)
    {
        for (int c = 0; c <= 1 ; ++c)
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

// x -1 , 20 pixlar vänster, x=1, 20 pix hög. y=-1 20 upp, y=1 20 ner.

void Figure::translate(int x, int y)
{
    //pos.x = pos.x + 20*x;
    //pos.y = pos.y + 20*y;

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

