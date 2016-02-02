#include "pokedex.h"

Pokedex::Pokedex(string path, int xPokemons, int yPokemons){
    _texture.loadFromFile(path);
    _xPokemons = xPokemons;
    _yPokemons = yPokemons;
}

void Pokedex::addPokemon(int num){
    sf::Sprite newPokemon;
    newPokemon.setTexture(_texture);
    int x = num%_xPokemons;
    int y = (num - x + _xPokemons)/_xPokemons;
    int height = _texture.getSize().y/_yPokemons;
    int width = _texture.getSize().x/_xPokemons;
    --x, --y;
    if(x<0){
        x = x+_xPokemons;
        --y;
    }
    newPokemon.setTextureRect(sf::IntRect(x*width,y*height,width,height));
    newPokemon.setPosition(sf::Vector2f(x*width+43,y*height+42));
    _sprites.push_back(newPokemon);
}

void Pokedex::draw(sf::RenderTarget& window){
    for(uint i = 0; i < _sprites.size(); ++i){
        window.draw(_sprites[i]);
    }
}
