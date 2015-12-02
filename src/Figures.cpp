#include "../include/Figures.h"
#include <iostream>

using namespace std;
using namespace sf;

void I::rotate()
{
     std::array <std::array<int, 4>, 4> temp_I
        {{
         std::array<int,4>{0, 0, 0, 0},
         std::array<int,4>{0, 0, 0, 0},
         std::array<int,4>{0, 0, 0, 0},
         std::array<int,4>{0, 0, 0, 0}
         }};

    for (int r = 0; r <= 3; ++r)
    {
        for (int c = 0; c <= 3 ; ++c)
        {
            temp_I[c][3-r] =
            Figure_I[r][c];
        }
    }
    Figure_I = temp_I;
}


void J::rotate()
{
     std::array <std::array<int, 3>, 3> temp_J
        {{
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0}
         }};

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp_J[c][2-r] =
            Figure_J[r][c];
        }
    }
    Figure_J = temp_J;
}

void L::rotate()
{
     std::array <std::array<int, 3>, 3> temp_L
        {{
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0}
         }};

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp_L[c][2-r] =
            Figure_L[r][c];
        }
    }
    Figure_L = temp_L;
}

void O::rotate()
{
     std::array <std::array<int, 2>, 2> temp_O
        {{
         std::array<int,2>{0, 0},
         std::array<int,2>{0, 0}
         }};

    for (int r = 0; r <= 1; ++r)
    {
        for (int c = 0; c <= 1 ; ++c)
        {
            temp_O[c][1-r] =
            Figure_O[r][c];
        }
    }
    Figure_O = temp_O;
}

void S::rotate()
{
     std::array <std::array<int, 3>, 3> temp_S
        {{
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0}
         }};

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp_S[c][2-r] =
            Figure_S[r][c];
        }
    }
    Figure_S = temp_S;
}

void T::rotate()
{
     std::array <std::array<int, 3>, 3> temp_T
        {{
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0}
         }};

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp_T[c][2-r] =
            Figure_T[r][c];
        }
    }
    Figure_T = temp_T;
}

void Z::rotate()
{
     std::array <std::array<int, 3>, 3> temp_Z
        {{
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0},
         std::array<int,3>{0, 0, 0}
         }};

    for (int r = 0; r <= 2; ++r)
    {
        for (int c = 0; c <= 2 ; ++c)
        {
            temp_Z[c][2-r] =
            Figure_Z[r][c];
        }
    }
    Figure_Z = temp_Z;
}
