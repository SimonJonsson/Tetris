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
    int pos{0};
    std::vector<HighScoreInfo> highscores;
    bool highscore = false;
    bool entered_name = false;

    std::string input{""};

    sf::Text GameOver_text;
    sf::Text GameOver_message;
    sf::RectangleShape Input_field{sf::Vector2f(300, 50)};
    sf::Text Input_text;

    sf::Font coolFont;
    sf::RenderWindow* window;
public:
    GameOverView(sf::RenderWindow*);
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
    bool               getHighScore();
    void               eventhandler(sf::Event&);
    void               eraseLetter();

    void leftClick()  override;
    void rightClick() override;
    void upClick()    override;
    void downClick()  override;
};

#endif // GAMEOVERVIEW_H
