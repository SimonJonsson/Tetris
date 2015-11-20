#ifndef GAMEOVERVIEW_H
#define GAMEOVERVIEW_H

#include "UpdateView.h"
#include <string>

class GameOverView : public UpdateView
{
    private:
        std::string name{""};
        int score{0};
    public:
        GameOverView() : UpdateView() {}
        //Kanske bara standardkonstruktor
        ~GameOverView() = default;

        //void open_view(); - Simon
        //void close_view(); - Simon

        void               update() override;
        void               updateHighScore();
        void               setName();
        void               setScore();
        const std::string& getName();
        const int&         getScore();
};

#endif // GAMEOVERVIEW_H
