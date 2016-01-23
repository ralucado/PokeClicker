#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "utils.h"
#include "pokemon.h"
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
    bool _canBuy;//
    LevelBar _eggBar;//
    int _eggPrice;//
    int _totalClicks;//
    int _totalPokemons;//
    vector<bool> _free;//
    vector<Pokemon> _pokemons;//
    vector<sf::Sprite> _sprites;
    priority_queue< pair<int,int>, vector< pair<int,int>, Compare> _eggs;//

    vector<bool> _canFeed;//

    sf::Texture _pokemonTexture;
    sf::Texture _eggTexture;
    sf::RenderTarget& _window;//
    Pokedex& _pokedex;//

    void _emptySlot(int i);
};

#endif // GAMEENGINE_H
