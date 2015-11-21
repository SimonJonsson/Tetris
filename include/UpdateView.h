//Simon
#ifndef UPDATEVIEW_H
#define UPDATEVIEW_H
#include <SFML/Window.hpp>

class UpdateView
{
public:
    UpdateView() = default;
    ~UpdateView() = default;

    virtual void update() = 0;

private:

};

#endif
