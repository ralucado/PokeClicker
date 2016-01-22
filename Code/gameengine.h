#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "utils.h"

class GameEngine {
public:
    GameEngine(sf::RenderTarget& window);

    void requestEgg();

    void update(int clicks);

    void draw();
private:
    int _totalClicks;
    sf::RenderTarget& _window;
};

#endif // GAMEENGINE_H
