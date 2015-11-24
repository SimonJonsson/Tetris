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

        void update() override;
        void readHighscore();

        void leftClick()  override;
        void rightClick() override;
        void upClick()    override;
        void downClick()  override;
};

#endif // HIGHSCOREVIEW_H
