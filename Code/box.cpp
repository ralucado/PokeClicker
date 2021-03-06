#include "box.h"

Box::Box(sf::Texture& pokemonTexture, sf::Texture& shinyTexture, sf::Texture& eggTexture, int posX, int posY)
    : _eggTexture(eggTexture), _pokemonTexture(pokemonTexture), _shinyTexture(shinyTexture){
    _posX = posX; _posY = posY;
    _free = true;
    _id = -1;
    _targetClicks = 0;
    _pokemonClicks = 0;
    _newBerryClicks = 0;
    _numPokemons = 0;
    _textTimePassed = 0;
    _sprite.setPosition(posX,posY);
    _healthBar.setParameters("Resources/Images/lvlbarE.png","Resources/Images/lvlbarF.png", posX + 251, posY);
    _berryBar.setParameters("Resources/Images/berrybarE.png","Resources/Images/berrybarF.png", posX + 251, posY + 251);
    _emotion.setParameters("Resources/Images/emotions.png",_posX+_sprite.getGlobalBounds().width/2, _posY+30);
    if(!_font.loadFromFile("Resources/Fonts/font.TTF")) cout << "could not load font" << endl;
    if(!_levelUpBuf.loadFromFile("Resources/Sounds/lvlUp.ogg")) cout << "failed to load lvl up sound " << endl;
    if(!_finishedBuf.loadFromFile("Resources/Sounds/finished.ogg")) cout << "failed to load finished sound " << endl;
}

bool Box::isFree(){
    return _free;
}

bool Box::canFeed(int berryClicks){
    //cout << berryClicks << " " << _newBerryClicks << endl;
    if(_free || _berryBox.isFull()) return false;
    return berryClicks >= _newBerryClicks;
}

stack<int>& Box::getStack(){
    return _finished;
}

void Box::update(int clicks, int berryClicks, int numPokemons, float deltaTime){
    if(!_free){
        _timeElapsed += deltaTime;

        _textTimePassed += deltaTime;
        _updateTexts();

        if(!_pokemon.isEgg()){
            _emotionTimePassed += deltaTime;
            _updateEmotion(deltaTime);
        }

        _numPokemons = numPokemons;

        if(_pokemonClicks < _targetClicks && clicks != 0){
            _newClicks = _berryBox.mulClicks(clicks);
            _pokemonClicks += _newClicks;
            _addText();
            int perc = (_pokemonClicks*100)/_targetClicks;
            _healthBar.update(perc);

            if(_pokemon.isEgg()){
                int spriteNum = (perc/20);
                if(spriteNum >= 5) _evolve();
                else _sprite.setTextureRect(sf::IntRect(0, spriteNum*(_eggTexture.getSize().y/5), _eggTexture.getSize().x/3, _eggTexture.getSize().y/5));

            }

            else{

                if(perc >= 100){
                    _finished.push(_pokemon.getID());
                    if(_pokemon.evolves()) _evolve();
                    else _freeSlot();
                }
            }
        }

        int perc;
        if(berryClicks <= _newBerryClicks){
            perc = (berryClicks*100)/_newBerryClicks;
        }
        else perc = 100;
        _berryBar.update(perc);
    }
    else _berryBar.update(0);
}

void Box::addPokemon(int id, int targetClicks){
    //cout << "adding egg with ID: " << id << endl;
    _id = id;
    _free = false;
    _newBerryClicks = 10;
    _pokemon = Pokemon(_id);
    _targetClicks = targetClicks;
    _sprite.setTexture(_eggTexture);
    _berryBox.setParameters("Resources/Images/berries.png", 4, 4, _posX , _posY + 251);
    _sprite.setTextureRect(sf::IntRect(0,0,_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
}

void Box::_evolve(){
    _sound.setBuffer(_levelUpBuf);
    _sound.setVolume(50);
    _sound.play();
    _pokemon.evolve();
    _setPokemon();
}

void Box::_setPokemon(){
    _timeElapsed = 0;
    _pokemonClicks = 0;
    _targetClicks = 150 + 100*0.2*_numPokemons;
    _healthBar.update(0);
    _id = _pokemon.getID();
    //cout << "evolving pokemon with ID: " << _id << endl;
    int xP = 28, yP = 6;

    int x = _id%xP;
    int y = (_id - x + xP)/xP;
    int height = _pokemonTexture.getSize().y/yP, width = _pokemonTexture.getSize().x/xP;
    --x; --y;
    if(x<0){
        x = x+xP;
        --y;
    }

    _targetEmotionTime = 1+rand()%2;
    _emotionTimePassed = 0;
    _emotion.setPosition(_posX+_sprite.getGlobalBounds().width/2, _posY+30);

    if (_pokemon.isShiny()) _sprite.setTexture(_shinyTexture);
    else _sprite.setTexture(_pokemonTexture);
    _sprite.setTextureRect(sf::IntRect(x*width,y*height,width,height));
}

int Box::buyBerry(){
    int price = _newBerryClicks;
    _newBerryClicks += _newBerryClicks/3*0.4;
    _berryBox.addBerry();
    if(!_pokemon.isEgg()) _setEmotion(Emotions::love);

    return price;
}


void Box::_addText(){
    sf::Text newText;
    newText.setFont(_font);
    newText.setString("+"+to_string(_newClicks));
    newText.setPosition(_posX+(_sprite.getGlobalBounds().width/2+(rand()%20)-rand()%35), _posY+42-rand()%6);
    _texts.push_back(newText);
}

void Box::_updateTexts(){
    //cout << _elapsedTime << endl;
    if(_textTimePassed >= FRAME_TIME){
        _textTimePassed = 0;
        for (std::list<sf::Text>::iterator it=_texts.begin(); it !=_texts.end();){
            if((*it).getPosition().y < 0){
                //cout << "updating texts" << endl;
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

void Box::_updateEmotion(float deltaTime){
    if(!_emotion.isOn()){
        //cout << "passed " << _emotionTimePassed << " to " << _targetEmotionTime << endl;
        if(_emotionTimePassed >= _targetEmotionTime){
            //cout << "setting an emotion" << endl;
            //cout << "berryBar is " << _berryBar.getLevel() << endl;
            //cout << "healthBar is " << _healthBar.getLevel() << endl;
            if (_berryBar.getLevel() >= 100) _setEmotion(Emotions::alert);
            else if (_timeElapsed >= 45 && _berryBox.size() <= 3) _setEmotion(Emotions::sick);
            else if (_timeElapsed >= 35 && _berryBox.size() <= 3) _setEmotion(Emotions::angry);
            else if (_timeElapsed >= 25 && _berryBox.size() <= 2) _setEmotion(Emotions::bugged);
            else if (_timeElapsed >= 15 && _berryBox.size() <= 2) _setEmotion(Emotions::sad);
            else if(_healthBar.getLevel() >= 50 && rand()%2 == 0) _setEmotion(Emotions::singing);
            else if(_healthBar.getLevel() >= 50) _setEmotion(Emotions::joyful);
            else if (_berryBox.size() >= 4)_setEmotion(Emotions::happy);
            else _setEmotion(Emotions::idle);
        }
    }
    else _emotion.update(deltaTime);
}

void Box::_setEmotion(Emotions::myEmotion emotion){
    _emotionTimePassed = 0;
    _targetEmotionTime = 6+rand()%7;
    _emotion.setEmotion(emotion);
}

void Box::draw(sf::RenderTarget &window){
     window.draw(_sprite);
    _healthBar.draw(window);
    _berryBar.draw(window);
    _berryBox.draw(window);
    _emotion.draw(window);
    for (std::list<sf::Text>::iterator it=_texts.begin(); it !=_texts.end(); ++it){
        window.draw(*it);
    }
}

void Box::_freeSlot(){
    //cout << "freeing slot " << endl;
    _sound.setBuffer(_finishedBuf);
    _sound.play();
    _healthBar.update(0);
    _berryBar.update(0);
    _id = -1;
    _free = true;
    _targetClicks = 0;
    _pokemonClicks = 0;
    _newBerryClicks = 0;
    _textTimePassed = 0;
    BerryBox aux;
    _berryBox = aux;
    _sprite.setTexture(_eggTexture);
    _sprite.setTextureRect(sf::IntRect(0,4*(_eggTexture.getSize().y/4),_eggTexture.getSize().x/3, _eggTexture.getSize().y/4));
    _emotion.turnOff();
    list<sf::Text> aux2;
    _texts = aux2;
}
