#include "levelbar.h"

LevelBar::LevelBar(){}

LevelBar::LevelBar(string ePath, string fPath, int posX, int posY){
    setParameters(ePath, fPath, posX, posY);
}

void LevelBar::setParameters(string ePath, string fPath, int posX, int posY){
    _posX = posX;
    _posY = posY;
    if(!_textureEmpty.loadFromFile(ePath)) cout << "failed to load empty bar texture!!" << endl;
    if(!_textureFull.loadFromFile(fPath)) cout << "failed to load full bar texture!!" << endl;
    _spriteEmpty.setTexture(_textureEmpty);
    _spriteEmpty.setPosition(posX, posY);
    update(0);
}

void LevelBar::update(int percentage){
    if (percentage <= 100 && _percentage != percentage){
        _spriteFull.setTexture(_textureFull);
        _percentage = percentage;
        int height = (_percentage*_textureFull.getSize().y)/100;
        _spriteFull.setPosition(_posX, _posY+_textureFull.getSize().y-height);
        _spriteFull.setTextureRect(sf::IntRect(0,_textureFull.getSize().y-height,_textureFull.getSize().x,height));

    }
    else if(_percentage != percentage) update(100);
}

int LevelBar::getLevel(){
    return _percentage;
}

void LevelBar::draw(sf::RenderTarget& window){
    window.draw(_spriteFull);
    window.draw(_spriteEmpty);
}
