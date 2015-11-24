//Axel & Mathilda
#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "UpdateView.h"

class MenuView : public UpdateView
{
private:
    sf::RectangleShape StartGame_button;
    sf::RectangleShape Highscore_button;
    sf::RectangleShape Exit_button;

    sf::RenderWindow* window;

public:
    MenuView(sf::RenderWindow*);
    ~MenuView();

    void update() override;
    void changeButton();

    void leftClick()  override;
    void rightClick() override;
    void upClick()    override;
    void downClick()  override;
};

#endif // MENUVIEW_H
