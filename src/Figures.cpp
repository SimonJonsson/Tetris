#include "../include/Figures.h"
#include <iostream>
#include <array>

using namespace std;
using namespace sf;

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
}


void J::rotate()
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
}
