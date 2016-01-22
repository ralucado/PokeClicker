#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "utils.h"
#include "pokedex.h"
#include "levelbar.h"

class GameEngine {
public:
    GameEngine(sf::RenderTarget& window, Pokedex& pokedex);

    void feed(int num);

    bool canBuy();

    bool canFeed(int num);

    void requestEgg();

    void update(int clicks);

    void draw();

private:
    int _numPokemons;
    bool _canBuy;
    int _totalClicks;
    vector<bool> _canFeed;
    sf::RenderTarget& _window;
    Pokedex& _pokedex;
};

#endif // GAMEENGINE_H
