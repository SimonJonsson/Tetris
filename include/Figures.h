//Sofia & Patrik
#ifndef FIGURES_H
#define FIGURES_H
#include "Figure.h"
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>


class I final : public Figure
{

    public:
        I();

        ~I() = default;
        void rotate() override;

    protected:

    private:

};

class J final : public Figure
{
    public:
        J();
/*        : Figure() {
        figmatrix = {
         {1, 0, 0},
         {1, 1, 1},
         {0, 0, 0}
         };

        color = sf::Color::Blue;
        }
*/
        ~J() = default;
        void rotate() override;

    protected:
    private:
/*            figmatrix
        {{
         std::array<int,3>{1, 0, 0},
         std::array<int,3>{1, 1, 1},
         std::array<int,3>{0, 0, 0}
         }};
*/

};

class L final : public Figure
{
    public:
        L();
/*
        : Figure() {
        figmatrix = {
         {0, 0, 1},
         {1, 1, 1},
         {0, 0, 0}
         };

        color = sf::Color::Green;
        }
*/
        ~L() = default;
        void rotate() override;

    protected:
    private:
/*    figmatrix
         {{
         std::array<int,3>{0, 0, 1},
         std::array<int,3>{1, 1, 1},
         std::array<int,3>{0, 0, 0}
         }};
         */

};

class O final : public Figure
{
    public:
        O();
/*
        : Figure() {
        figmatrix = {
         {1, 1},
         {1, 1}
         };

        color = sf::Color::Red;
        }
*/
        ~O() = default;
        void rotate() override;

    protected:
    private:
 /*   figmatrix
         {{
         std::array<int,2>{1, 1},
         std::array<int,2>{1, 1}
         }};
         */

};

class S final : public Figure
{
    public:
        S();
/*
        : Figure() {
        figmatrix = {
         {0, 1, 1},
         {1, 1, 0},
         {0, 0, 0}
         };

        color = sf::Color::White;
        }
*/
        ~S() = default;
        void rotate() override;

    protected:
    private:
/*    figmatrix
         {{
         std::array<int,3>{0, 1, 1},
         std::array<int,3>{1, 1, 0},
         std::array<int,3>{0, 0, 0}
         }};
         */

};

class T final : public Figure
{
    public:
        T();
/*
        : Figure() {
        figmatrix = {
         {0, 1, 0},
         {1, 1, 1},
         {0, 0, 0}
         };

        color = sf::Color(250, 150, 100);
        }
*/
        ~T() = default;
        void rotate() override;

    protected:
    private:
/*    figmatrix
         {{
         std::array<int,3>{0, 1, 0},
         std::array<int,3>{1, 1, 1},
         std::array<int,3>{0, 0, 0}
         }};
         */

};

class Z final : public Figure
{
    public:
        Z();
/*
        : Figure() {
        figmatrix = {
         {1, 1, 0},
         {0, 1, 1},
         {0, 0, 0}
         };

        color = sf::Color::Yellow;
        }
*/
        ~Z() = default;
        void rotate() override;

    protected:
    private:
/*    figmatrix
         {{
         std::array<int,3>{1, 1, 0},
         std::array<int,3>{0, 1, 1},
         std::array<int,3>{0, 0, 0}
         }};
         */

};

#endif // FIGURES_H
