//Simon
#ifndef UPDATEVIEW_H
#define UPDATEVIEW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class UpdateView
{
public:
    UpdateView();
    ~UpdateView() = default;

    virtual void update(sf::RenderWindow&) = 0;

private:

};

#endif
