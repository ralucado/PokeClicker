#ifndef POKEDEX_H
#define POKEDEX_H

#include "utils.h"
#include "button.h"

class Pokedex{
public:

    Pokedex(string path, int xPokemons, int yPokemons);
    void addPokemon(int num);
    void draw(sf::RenderTarget& window);

private:
    int _xPokemons, _yPokemons;
    sf::Texture _texture;
    vector<sf::Sprite> _sprites;
};

#endif // POKEDEX_H
