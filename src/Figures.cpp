#include "../include/Figures.h"
#include <iostream>
#include <array>

using namespace std;
using namespace sf;

/*void getReferencepoint
{
//xpos; Alt. en vector el struct m två medlemmar.
//ypos;
}
*/


/*
void I::rotate()
{
         vector<vector<int>> temp = {
         {0, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}
         };

    for (int r = 0; r <= 3; ++r)
    {
        for (int c = 0; c <= 3 ; ++c)
        {
            temp[c][3-r] =
            figmatrix[r][c];
        }
    }
    figmatrix = temp;

    //För att ändra blocks
    int index = 0;
    for (int r = 0; r <= 3; ++r)
    {
        for (int c = 0; c <= 3 ; ++c)
        {
            if(figmatrix[r][c] == 1)
            {
                RectangleShape* block = blocks[index];
                block->setPosition(Vector2f(20*r,20*c));
                index++;
            }
        }
    }
}


void J::rotate()
{
        vector<vector<int>> temp = {
         {0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}
         };

    int xpos{0};
    int ypos{0};

    bool found = false;

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            if(figmatrix[r][c] == 1 && !(found))
            {
                xpos = blocks[0]->getPosition().x - 20*c;
                ypos = blocks[0]->getPosition().y - 20*r;
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
                block->setPosition(Vector2f(xpos+ 20*c, ypos + 20*r));
                index++;
            }
        }
    }
}

void L::rotate()
{
        vector<vector<int>> temp = {
         {0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}
         };

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp[c][2-r] =
            figmatrix[r][c];
        }
    }
    figmatrix = temp;

        //För att ändra blocks
    int index = 0;
    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            if(figmatrix[r][c] == 1)
            {
                RectangleShape* block = blocks[index];
                block->setPosition(Vector2f(20*r,20*c));
                index++;
            }
        }
    }
}

void O::rotate()
{
        vector<vector<int>> temp = {
         {0, 0},
         {0, 0}
         };

    for (int r = 0; r <= 1; ++r)
    {
        for (int c = 0; c <= 1 ; ++c)
        {
            temp[c][1-r] =
            figmatrix[r][c];
        }
    }
    figmatrix = temp;

        //För att ändra blocks
    int index = 0;
    for (int r = 0; r <= 1; ++r)
    {
        for (int c = 0; c <= 1 ; ++c)
        {
            if(figmatrix[r][c] == 1)
            {
                RectangleShape* block = blocks[index];
                block->setPosition(Vector2f(20*r,20*c));
                index++;
            }
        }
    }
}

void S::rotate()
{
        vector<vector<int>> temp = {
         {0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}
         };

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp[c][2-r] =
            figmatrix[r][c];
        }
    }
    figmatrix = temp;

        //För att ändra blocks
    int index = 0;
    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            if(figmatrix[r][c] == 1)
            {
                RectangleShape* block = blocks[index];
                block->setPosition(Vector2f(20*r,20*c));
                index++;
            }
        }
    }
}

void T::rotate()
{
        vector<vector<int>> temp = {
         {0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}
         };

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp[c][2-r] =
            figmatrix[r][c];
        }
    }
    figmatrix = temp;

        //För att ändra blocks
    int index = 0;
    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            if(figmatrix[r][c] == 1)
            {
                RectangleShape* block = blocks[index];
                block->setPosition(Vector2f(20*r,20*c));
                index++;
            }
        }
    }
}

void Z::rotate()
{
        vector<vector<int>> temp = {
         {0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}
         };

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp[c][2-r] =
            figmatrix[r][c];
        }
    }
    figmatrix = temp;

        //För att ändra blocks
    int index = 0;
    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            if(figmatrix[r][c] == 1)
            {
                RectangleShape* block = blocks[index];
                block->setPosition(Vector2f(20*r,20*c));
                index++;
            }
        }
    }
}


*/
