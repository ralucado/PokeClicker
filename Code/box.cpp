#include "box.h"

Box::Box(sf::Texture& pokemonTexture, sf::Texture& eggTexture, int posX, int posY) : _eggTexture(eggTexture), _pokemonTexture(pokemonTexture){
    _free = true;
    _id = -1;
    _sprite.setPosition(posX,posY);
    _healthBar.setParameters("Resources/Images/lvlbarE.png","Resources/Images/lvlbarF.png", posX + 251, posY);
    _berryBar.setParameters("Resources/Images/berrybarE.png","Resources/Images/berrybarF.png", posX + 251, posY + 251);
    _berryClicks = 0;
    _targetClicks = 0;
    _pokemonClicks = 0;
    _newBerryClicks = 0;
}

bool Box::isFree(){
    return _free;
}

bool Box::canFeed(){
    return false;
}

stack<int>& Box::getStack(){
    return _finished;
}

void Box::addPokemon(int id, int targetClicks){
    _targetClicks = targetClicks;
    _newBerryClicks = targetClicks;
    _free = false;
    _pokemon = Pokemon(id);
    _sprite.setTexture(_eggTexture);
    _sprite.setTextureRect(sf::IntRect(0,0,_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
}

void Box::update(int clicks){
    if(!_free){
        if(_pokemonClicks < _targetClicks){
            _pokemonClicks += clicks;
            int perc = (_pokemonClicks*100)/_targetClicks;
            _healthBar.update(perc);
            cout << "updating poke bar with perc " << perc;
            if(_pokemon.isEgg()){
                int spriteNum = (perc/25);
                cout << spriteNum << endl;
                if(spriteNum == 4) _pokemon.evolve();
                _sprite.setTextureRect(sf::IntRect(0,spriteNum*(_eggTexture.getSize().y/4),_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
            }
            else{
                if(perc >= 100){
                    _finished.push(_pokemon.getID());
                    if(_pokemon.evolves()) _pokemon.evolve();
                    else freeSlot();
                }
            }
        }
        if(_berryClicks < _newBerryClicks){
            _berryClicks += clicks;
            _berryBar.update((_berryClicks*100)/_newBerryClicks);
        //cout << "updating berry bar with perc " << (_berryClicks*100)/_newBerryClicks << endl;
        }
    }
}

void Box::buyBerry(){

}

void Box::freeSlot(){

}

void Box::draw(sf::RenderTarget &window){
    window.draw(_sprite);
    _healthBar.draw(window);
    _berryBar.draw(window);
    for (uint i = 0; i < _berries.size(); ++i){
        window.draw(_berries[i]);
    }
}
