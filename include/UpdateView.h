#ifndef UPDATEVIEW_H
#define UPDATEVIEW_H
#include <SFML/Graphics.hpp>

class UpdateView
{
public:
    UpdateView();
    ~UpdateView() = default;

    virtual void update() = 0;

private:

}

#endif
