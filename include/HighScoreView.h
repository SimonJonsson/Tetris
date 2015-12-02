//Axel & Mathilda
#ifndef HIGHSCOREVIEW_H
#define HIGHSCOREVIEW_H

#include "UpdateView.h"
#include <string>
#include <vector>

struct HighScore
{
    sf::Text name;
    sf::Text score;
};

class HighScoreView : public UpdateView
{
    private:
        std::vector<HighScore> highscores;
        sf::Text HighScore_title;

        sf::Font coolFont;
        sf::RenderWindow* window;

    public:
        HighScoreView(sf::RenderWindow*);
        ~HighScoreView();

        void update() override;
        void readHighscore();

        void leftClick()  override;
        void rightClick() override;
        void upClick()    override;
        void downClick()  override;
};

#endif // HIGHSCOREVIEW_H
