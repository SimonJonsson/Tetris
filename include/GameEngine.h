#include <SFML/Graphics.hpp>
#include "Figure.h"

class GameEngine
{
private:


     void update(long dt);
     void updateVelocity();
     void translate(Figure* fig, int x, int y);
     void translate(Shape* block, int x, int y);
     Shape* collides(Figure* fig); //Check if figure collides with field/borders

public:
    GameEngine() = default;
    ~GameEngine() = default;

    void leftClick();
    void rightClick();
    void upClick();
    void downClick();

};
