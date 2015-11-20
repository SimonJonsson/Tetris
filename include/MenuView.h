#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "UpdateView.h"

class MenuView
{
private:
    sf::Shape StartGame_button
    sf::Shape Highscore_button
    sf::Shape Exit_button

public:
    MenuView() : UpdateView() {}
    ~MenuView();

    void update() override;
    void changeButton();
};

#endif // MENUVIEW_H
