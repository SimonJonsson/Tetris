#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "UpdateView.h"
//#include "GameEngine.h"

class GameView : public UpdateView
{
public:
    GameView(sf::Window&);
    ~GameView() = default;

    void update() override;
private:
};

#endif
