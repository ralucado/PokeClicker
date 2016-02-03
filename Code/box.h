#ifndef BOX_H
#define BOX_H

#include "utils.h"
#include "berrybox.h"
#include "pokemon.h"
#include "levelbar.h"

class Box{

public:
    bool isFree();
    bool canFeed();
    void buyBerry();
    void update(int clicks, int numPokemons);
    void draw(sf::RenderTarget& window);
    void addPokemon(int id, int targetClicks);
    Box(sf::Texture &pokemonTexture, sf::Texture &eggTexture, int posX, int posY);
    stack<int>& getStack();
    
private:
    int _id;
    int _numPokemons;
    bool _free;
    int _posX, _posY;
    int _berryClicks;
    int _targetClicks;
    int _pokemonClicks;
    int _newBerryClicks;

    Pokemon _pokemon;
    stack<int> _finished;
    sf::Sprite _sprite;
    LevelBar _berryBar;
    LevelBar _healthBar;
    BerryBox _berryBox;
    sf::Texture& _eggTexture;
    sf::Texture& _pokemonTexture;

    void _freeSlot();
    void _setPokemon();
    void _evolve();
};

#endif // BOX_H
