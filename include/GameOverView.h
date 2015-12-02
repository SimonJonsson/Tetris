//Axel & Mathilda
#ifndef GAMEOVERVIEW_H
#define GAMEOVERVIEW_H

#include "UpdateView.h"
#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

struct HighScoreInfo
{
    std::string name{""};
    int score{0};
};

class GameOverView : public UpdateView
{
private:
    std::string name{""};
    int score{0};
    std::vector<HighScoreInfo> highscores;
    bool highscore = false;

    sf::Text GameOver_text;

    sf::Font coolFont;
    sf::RenderWindow* window;
public:
    GameOverView(sf::RenderWindow*);
    //Kanske bara standardkonstruktor
    ~GameOverView() = default;

    void               update() override;
    void               readHighScores();
    int                compareScore();
    void               checkScore();
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
