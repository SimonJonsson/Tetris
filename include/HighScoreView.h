//Axel & Mathilda
#ifndef HIGHSCOREVIEW_H
#define HIGHSCOREVIEW_H

#include "UpdateView.h"
#include <string>
#include <vector>

struct HighScore
{
    std::string name;
    int score;
};
class HighScoreView : public UpdateView
{
    private:
        std::vector<HighScore> highscores;
    public:
        HighScoreView(): UpdateView() {}
        ~HighScoreView();

        void update(sf::RenderWindow&) override;
        void readHighscore();
};

#endif // HIGHSCOREVIEW_H
