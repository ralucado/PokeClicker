#include "berrybox.h"


BerryBox::BerryBox(){}

void BerryBox::setParameters(string path, int xBerries, int yBerries, int xPos, int yPos){
        if(!_texture.loadFromFile(path)) cout << "failed to load pokedex icons texture" << endl;
        _xBerries = xBerries;
        _yBerries = yBerries;
        _xPos = xPos;
        _yPos = yPos;
}

void BerryBox::addBerry(){
    int num = _sprites.size()+1;
    sf::Sprite newBerry;
    newBerry.setTexture(_texture);
    int x = num%_xBerries;
    int y = (num - x + _xBerries)/_xBerries;
    int width = _texture.getSize().x/_xBerries;
    int height = _texture.getSize().y/_yBerries;
    --x, --y;
    if(x<0){
        x = x+_xBerries;
        --y;
    }
    newBerry.setTextureRect(sf::IntRect(x*width,y*height,width,height));
    newBerry.setPosition(sf::Vector2f(x*width+_xPos,y*height+_yPos));
    _sprites.push_back(newBerry);
}

void BerryBox::draw(sf::RenderTarget& window){
    for(uint i = 0; i < _sprites.size(); ++i){
        window.draw(_sprites[i]);
    }
}

bool BerryBox::isFull(){
    return (_sprites.size() == _xBerries*_yBerries);
}

int BerryBox::size(){
    return _sprites.size();
}

