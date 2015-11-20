#ifndef FIGURE_H
#define FIGURE_H
#include


class Figure
{
public:
    Figure();
    virtual ~Figure();

    std::array <std::array<int, 3>, 3> Tetromino_JLSTZ;
    std::array <std::array<int, 4>, 4> Tetromino_IO;

    //clone på figurerna?

    virtual rotate() const = 0;

protected:

private:
int x{0};
int y{0};
int colour;

};

#endif // FIGURE_H
