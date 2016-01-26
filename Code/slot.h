#ifndef SLOT_H
#define SLOT_H

#include "utils.h"
#include "berry.h"
#include "pokemon.h"
#include "levelbar.h"

class Slot{

public:
    Slot(sf::Texture& pokemonTexture, sf::Texture& eggTexture, int posX, int posY);
    bool isFree();
    void addPokemon(int id, int targetClicks);
    void update(int clicks);
    void buyBerry();
    void draw(sf::RenderWindow& window);
    
private:
    bool _free;
    int _id;
    sf::Texture& _eggTexture;
    sf::Texture& _pokemonTexture;
    sf::Sprite _sprite;
    Pokemon _pokemon;
    vector<Berry> _berries;
    LevelBar _healthBar;
    LevelBar _berryBar;
};

#endif // SLOT_H
