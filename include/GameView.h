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

    void update() override;
private:
};

#endif
