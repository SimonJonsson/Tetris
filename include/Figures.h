//Sofia & Patrik
#ifndef FIGURES_H
#define FIGURES_H
#include "Figure.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>


class I final : public Figure
{
    public:
        I()
        : Figure() {}
        virtual ~I();
        void rotate() override;
        std::array <std::array<int, 4>, 4> Figure_I
        {{
         std::array<int,4>{0, 0, 0, 0},
         std::array<int,4>{1, 1, 1, 1},
         std::array<int,4>{0, 0, 0, 0},
         std::array<int,4>{0, 0, 0, 0}
         }};
    protected:
    private:
    //purple
};

class J final : public Figure
{
    public:
        J()
        : Figure() {}
        virtual ~J();
        void rotate() override;
        std::array <std::array<int, 3>, 3> Figure_J
        {{
         std::array<int,3>{1, 0, 0},
         std::array<int,3>{1, 1, 1},
         std::array<int,3>{0, 0, 0}
         }};
    protected:
    private:
    //blue
};

class L final : public Figure
{
    public:
        L()
        : Figure() {}
        virtual ~L();
        void rotate() override;
        std::array <std::array<int, 3>, 3> Figure_L
         {{
         std::array<int,3>{0, 0, 1},
         std::array<int,3>{1, 1, 1},
         std::array<int,3>{0, 0, 0}
         }};
    protected:
    private:
    //green
};

class O final : public Figure
{
    public:
        O()
        : Figure() {}
        virtual ~O();
        void rotate() override;
        std::array <std::array<int, 2>, 2> Figure_O
         {{
         std::array<int,2>{1, 1},
         std::array<int,2>{1, 1}
         }};

    protected:
    private:
    //red
};

class S final : public Figure
{
    public:
        S()
        : Figure() {}
        virtual ~S();
        void rotate() override;
         std::array <std::array<int, 3>, 3> Figure_S
         {{
         std::array<int,3>{0, 1, 1},
         std::array<int,3>{1, 1, 0},
         std::array<int,3>{0, 0, 0}
         }};
    protected:
    private:
    //white
};

class T final : public Figure
{
    public:
        T()
        : Figure() {}
        virtual ~T();
        void rotate() override;
         std::array <std::array<int, 3>, 3> Figure_T
         {{
         std::array<int,3>{0, 1, 0},
         std::array<int,3>{1, 1, 1},
         std::array<int,3>{0, 0, 0}
         }};
    protected:
    private:
    //orange
};

class Z final : public Figure
{
    public:
        Z()
        : Figure() {}
        virtual ~Z();
        void rotate() override;
         std::array <std::array<int, 3>, 3> Figure_Z
         {{
         std::array<int,3>{1, 1, 0},
         std::array<int,3>{0, 1, 1},
         std::array<int,3>{0, 0, 0}
         }};
    protected:
    private:
    //yellow
};

#endif // FIGURES_H
