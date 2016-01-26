#ifndef SLOT_H
#define SLOT_H

#include "utils.h"
#include "berry.h"
#include "pokemon.h"
#include "levelbar.h"

class Slot{

public:
    bool isFree();
    bool canFeed();
    void buyBerry();
    void update(int clicks);
    void draw(sf::RenderTarget& window);
    void addPokemon(int id, int targetClicks);
    Slot(sf::Texture &pokemonTexture, sf::Texture &eggTexture, int posX, int posY);
    
private:
    int _id;
    bool _free;
    int _berryClicks;
    int _targetClicks;
    int _pokemonClicks;
    int _newBerryClicks;

    Pokemon _pokemon;
    sf::Sprite _sprite;
    LevelBar _berryBar;
    LevelBar _healthBar;
    vector<Berry> _berries;
    sf::Texture& _eggTexture;
    sf::Texture& _pokemonTexture;
};

#endif // SLOT_H
