#include "box.h"

Box::Box(sf::Texture& pokemonTexture, sf::Texture& eggTexture, int posX, int posY) : _eggTexture(eggTexture), _pokemonTexture(pokemonTexture){
    _posX = posX; _posY = posY;
    _free = true;
    _id = -1;
    _berryClicks = 0;
    _targetClicks = 0;
    _pokemonClicks = 0;
    _newBerryClicks = 0;
    _numPokemons = 0;
    _elapsedTime = 0;
    _sprite.setPosition(posX,posY);
    _healthBar.setParameters("Resources/Images/lvlbarE.png","Resources/Images/lvlbarF.png", posX + 251, posY);
    _berryBar.setParameters("Resources/Images/berrybarE.png","Resources/Images/berrybarF.png", posX + 251, posY + 251);
    if(!_font.loadFromFile("Resources/Fonts/font.TTF")) cout << "could not load font" << endl;
}

bool Box::isFree(){
    return _free;
}

bool Box::canFeed(){
    //cout << _berryClicks << " " << _newBerryClicks << endl;
    if(_free || _berryBox.isFull()) return false;
    else return _berryClicks >= _newBerryClicks;
}

stack<int>& Box::getStack(){
    return _finished;
}

void Box::addPokemon(int id, int targetClicks){
    cout << "adding egg with ID: " << id << endl;
    _targetClicks = targetClicks;
    _newBerryClicks = 10;
    _free = false;
    _id = id;
    _pokemon = Pokemon(_id);
    _sprite.setTexture(_eggTexture);
    _sprite.setTextureRect(sf::IntRect(0,0,_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
    _berryBox.setParameters("Resources/Images/berries.png", 4, 4, _posX , _posY + 251);
}

void Box::update(int clicks, int numPokemons, float deltaTime){

    if(!_free){
        _elapsedTime += deltaTime;
        _updateTexts();

        if(_pokemonClicks < _targetClicks && clicks != 0){
            _newClicks = _berryBox.mulClicks(clicks);
            _pokemonClicks += _newClicks;
            _addText();
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
    _newBerryClicks += _newBerryClicks*0.2;
    _berryBox.addBerry();
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
    _elapsedTime = 0;
    BerryBox aux;
    _berryBox = aux;
    _sprite.setTexture(_eggTexture);
    _sprite.setTextureRect(sf::IntRect(0,4*(_eggTexture.getSize().y/4),_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));

    list<sf::Text> aux2;
    _texts = aux2;
}

void Box::_evolve(){
    _pokemon.evolve();
    _setPokemon();

}

void Box::_setPokemon(){
    _pokemonClicks = 0;
    _targetClicks = 50 + (50*0.2)*_numPokemons;
    _id = _pokemon.getID();
    cout << "evolving pokemon with ID: " << _id << endl;
    int xP = 28, yP = 6;
    int x = _id%xP;
    int y = (_id - x + xP)/xP;
    int height = _pokemonTexture.getSize().y/yP, width = _pokemonTexture.getSize().x/xP;
    --x; --y;
    if(x<0){
        x = x+xP;
        --y;
    }
    _sprite.setTexture(_pokemonTexture);
    _sprite.setTextureRect(sf::IntRect(x*width,y*height,width,height));
}

void Box::_addText(){
    sf::Text newText;
    newText.setFont(_font);
    newText.setString("+"+to_string(_newClicks));
    newText.setPosition(_posX+(_sprite.getGlobalBounds().width/2+(rand()%20)-rand()%35), _posY+42);
    _texts.push_back(newText);
}

void Box::_updateTexts(){
    //cout << _elapsedTime << endl;
    if(_elapsedTime >= FRAME_TIME){
        _elapsedTime = 0;
        for (std::list<sf::Text>::iterator it=_texts.begin(); it !=_texts.end();){
            if((*it).getPosition().y < 0){
                cout << "updating texts" << endl;
                it = _texts.erase(it);
            }
            else{
                sf::Color aux = it->getColor();
                aux.a -= 10;
                it->setColor(aux);
                it->setPosition(it->getPosition().x, it->getPosition().y-10);
                ++it;
            }
        }
    }
}

void Box::draw(sf::RenderTarget &window){
     window.draw(_sprite);
    _healthBar.draw(window);
    _berryBar.draw(window);
    _berryBox.draw(window);
    for (std::list<sf::Text>::iterator it=_texts.begin(); it !=_texts.end(); ++it){
        window.draw(*it);
    }
}
