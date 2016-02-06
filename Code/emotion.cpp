#include "emotion.h"

Emotion::Emotion() {}

void Emotion::setParameters(string path, int posX, int posY){
    if(!_texture.loadFromFile(path)) cout << "failed to load emotion texture" << endl;
    setPosition(posX, posY);
     _timer = 0;
}

void Emotion::setPosition(int posX, int posY){
    _posX = posX;
    _posY = posY;
}

void Emotion::setEmotion(Emotions::myEmotion emotion){
    _frame = 0;
    _deltaTime = 0;
    _timer = 0;
    _active = true;
    _emotion = emotion;
    _xSize = _texture.getSize().x/2;
    _ySize = _texture.getSize().y/10;
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_xSize/2, _ySize);
    _sprite.setPosition(_posX,_posY);
    _sprite.setTextureRect(sf::IntRect(0,_ySize*_emotion,_xSize,_ySize));
}

void Emotion::update(float deltaTime){
    if(_active){
        _timer += deltaTime;
        //cout << "timer = " << _timer << " duration = " << _duration << endl;
        if(_timer >= _duration) turnOff();
        else{
            _deltaTime += deltaTime;
            if(_deltaTime >= _frameTime){
                _deltaTime = 0;
                _updateSprite();
            }
        }
    }
}

void Emotion::draw(sf::RenderTarget& window){
    window.draw(_sprite);
}

bool Emotion::isOn(){
    return _active;
}

void Emotion::turnOff(){
    //cout << "turning off emotion" << endl;
    _active = false;
     _timer = 0;
     _frame = 0;
     _deltaTime = 0;
    _sprite.setTextureRect(sf::IntRect(0,0,0,0));
}

void Emotion::_updateSprite(){
    _frame = (_frame+1)%2;
    _sprite.setTextureRect(sf::IntRect(_frame*_xSize,_ySize*_emotion,_xSize,_ySize));
}
