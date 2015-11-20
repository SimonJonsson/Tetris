#ifndef VIEWHANDLER_H
#define VIEWHANDLER_H

#include <Keyboard.hpp>

#include "UpdateView.h"
#include "MenuView.h"
#include "GameView.h"
#include "GameOverView.h"
#include "HighScoreView.h"



class ViewHandler
{
public:
    ViewHandler();
    ~ViewHandler() = default;

    //Problem uppstår när vi skall stänga av spelet.
    void    controls(); //Läser från keyboard, har kontrollschema


private:
    UpdateView*     currentView;

    MenuView*       menuView;
    HighScoreView*  highScoreView;
    GameView*       gameView;
    GameOverView*   gameOverView;


}

#endif
