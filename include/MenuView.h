//Axel & Mathilda
#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "UpdateView.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class MenuView : public UpdateView
{
private:
    sf::RectangleShape StartGame_button{sf::Vector2f(200, 50)};
    sf::RectangleShape Highscore_button{sf::Vector2f(200, 50)};
    sf::RectangleShape Exit_button{sf::Vector2f(200, 50)};

    sf::Text Game_text;
    sf::Text StartGame_text;
    sf::Text Highscore_text;
    sf::Text Exit_text;

    sf::Font coolFont;
    sf::RenderWindow* window;
    std::string focus;

public:
    MenuView(sf::RenderWindow*);
    ~MenuView();

    void update() override;
    void changeButton();

    void leftClick()  override;
    void rightClick() override;
    void upClick()    override;
    void downClick()  override;
    std::string getFocus();
};

#endif // MENUVIEW_H
