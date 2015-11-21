#ifndef HIGHSCOREVIEW_H
#define HIGHSCOREVIEW_H

#include "UpdateView.h"
#include <string>
#include <vector>

using namespace std;

struct HighScore
{
    string name;
    int score;
};
class HighScoreView : public UpdateView
{
    private:
        vector<HighScore> highscores;
    public:
        HighScoreView(): UpdateView() {}
        ~HighScoreView();

        void update() override;
        void readHighscore();
};

#endif // HIGHSCOREVIEW_H
