//Simon

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "UpdateView.h"
#include "GameEngine.h"

class GameView : public UpdateView
{
public:
    GameView();
    ~GameView() = default;

    void update(sf::RenderWindow&) override;
private:
    sf::RenderWindow* window;
};

#endif
