//Axel & Mathilda
#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "UpdateView.h"

class MenuView : public UpdateView
{
private:
//Ni har inte includat något. Kompilerar inte
   // sf::Shape StartGame_button;
   // sf::Shape Highscore_button;
   // sf::Shape Exit_button;

public:
    MenuView() : UpdateView() {}
    ~MenuView();

    void update(sf::RenderWindow&) override;
    void changeButton();
};

#endif // MENUVIEW_H
