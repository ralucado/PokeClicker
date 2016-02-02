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
    //cout << _berryClicks << " " << _newBerryClicks << endl;
    if(_free) return false;
    else return _berryClicks >= _newBerryClicks;
}

stack<int>& Box::getStack(){
    return _finished;
}

void Box::addPokemon(int id, int targetClicks){
    cout << "adding egg with ID: " << id << endl;
    _targetClicks = targetClicks;
    _newBerryClicks = targetClicks-5;
    _free = false;
    _id = id;
    _pokemon = Pokemon(_id);
    _sprite.setTexture(_eggTexture);
    _sprite.setTextureRect(sf::IntRect(0,0,_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
}

void Box::update(int clicks){
    if(!_free){
        if(_pokemonClicks < _targetClicks){
            _pokemonClicks += clicks;
            int perc = (_pokemonClicks*100)/_targetClicks;
            _healthBar.update(perc);

            if(_pokemon.isEgg()){
                int spriteNum = (perc/25);
                if(spriteNum == 4){
                    _pokemon.evolve();
                    _setPokemon();
                }
                else _sprite.setTextureRect(sf::IntRect(0,spriteNum*(_eggTexture.getSize().y/4),_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
            }

            else{
                if(perc >= 100){
                    _finished.push(_pokemon.getID());
                    if(_pokemon.evolves()) _evolve();
                    else _freeSlot();
                }
            }
        }


        if(_berryClicks < _newBerryClicks){
            _berryClicks += clicks;
            _berryBar.update((_berryClicks*100)/_newBerryClicks);
        }
    }
}

void Box::buyBerry(){
    _berryClicks -= _newBerryClicks;
    _newBerryClicks += _newBerryClicks*(0.2*_berries.size());
}

void Box::_freeSlot(){
    _healthBar.update(0);
    _berryBar.update(0);
    _id = -1;
    _free = true;
    _berryClicks = 0;
    _targetClicks = 0;
    _pokemonClicks = 0;
    _newBerryClicks = 0;

    vector<Berry> aux;
    _berries = aux;
     _sprite.setTexture(_eggTexture);
    _sprite.setTextureRect(sf::IntRect(0,4*(_eggTexture.getSize().y/4),_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
}

void Box::_setPokemon(){
    _pokemonClicks = 0;
    _targetClicks = 4;
    _id = _pokemon.getID();
    cout << "evolving pokemon with ID: " << _id << endl;
    int xP = 28, yP = 6;
    int x = _id%xP;
    int y = (_id - x + xP)/xP;
    int height = _pokemonTexture.getSize().y/yP, width = _pokemonTexture.getSize().x/xP;
    --x; --y;
    if(x<0){
        x = x+14;
        --y;
    }
    _sprite.setTexture(_pokemonTexture);
    _sprite.setTextureRect(sf::IntRect(x*width,y*height,width,height));
}

void Box::_evolve(){
    _pokemon.evolve();
    _setPokemon();

}

void Box::draw(sf::RenderTarget &window){
    window.draw(_sprite);
    _healthBar.draw(window);
    _berryBar.draw(window);
    for (uint i = 0; i < _berries.size(); ++i){
        window.draw(_berries[i]);
    }
}
