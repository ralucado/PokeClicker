#include "slot.h"

Slot::Slot(sf::Texture& pokemonTexture, sf::Texture& eggTexture, int posX, int posY) : _eggTexture(eggTexture), _pokemonTexture(pokemonTexture){
    _free = true;
    _id = -1;
    _sprite.setPosition(posX,posY);
    _healthBar.setParameters("Resources/Images/lvlbarE.png","Resources/Images/lvlbarF.png", posX + 253, posY);
    _berryBar.setParameters("Resources/Images/berrybarE.png","Resources/Images/berrybarF.png", posX + 253, posY + 253);
    _berryClicks = 0;
    _targetClicks = 0;
    _pokemonClicks = 0;
    _newBerryClicks = 0;
}

bool Slot::isFree(){
    return _free;
}

bool Slot::canFeed(){
    return false;
}

void Slot::addPokemon(int id, int targetClicks){
    _targetClicks = targetClicks;
    _newBerryClicks = targetClicks;
    _free = false;
    _pokemon = Pokemon(id);
    _sprite.setTexture(_eggTexture);
    _sprite.setTextureRect(sf::IntRect(0,0,_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
}

void Slot::update(int clicks){
    if(!_free){
        _berryClicks += clicks;
        _pokemonClicks += clicks;
        _berryBar.update((_berryClicks*100)/_newBerryClicks);
        cout << "updating berry bar with perc " << (_berryClicks*100)/_newBerryClicks << endl;
        _healthBar.update((_pokemonClicks*100)/_targetClicks);
        cout << "updating poke bar with perc " << (_pokemonClicks*100)/_targetClicks;
    }
    //if(_pokemon.isEgg()) _sprite.setTextureRect(sf::IntRect(0,(perc/25)*_eggTexture.getSize().y/4,_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
}

void Slot::buyBerry(){

}

void Slot::draw(sf::RenderTarget &window){
    window.draw(_sprite);
    _healthBar.draw(window);
    _berryBar.draw(window);
    for (uint i = 0; i < _berries.size(); ++i){
        window.draw(_berries[i]);
    }
}
