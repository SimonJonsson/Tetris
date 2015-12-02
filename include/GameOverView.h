//Axel & Mathilda
#ifndef GAMEOVERVIEW_H
#define GAMEOVERVIEW_H

#include "UpdateView.h"
#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class GameOverView : public UpdateView
{
private:
    std::string name{""};
    int score{0};

    sf::Text GameOver_text;

    sf::Font coolFont;
    sf::RenderWindow* window;
public:
    GameOverView(sf::RenderWindow*);
    //Kanske bara standardkonstruktor
    ~GameOverView() = default;

    //void open_view(); - Simon
    //void close_view(); - Simon

    void               update() override;
    void               updateHighScore();
    void               setName(const std::string&);
    void               setScore(const int&);
    std::string        getName();
    int                getScore();

    void leftClick()  override;
    void rightClick() override;
    void upClick()    override;
    void downClick()  override;
};

#endif // GAMEOVERVIEW_H
