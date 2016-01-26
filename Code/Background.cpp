#include "Background.h"

Background::Background(std::string path){
    if(!_texture.loadFromFile(path)) cout << "failed to load background texture!! 2 faggots" << endl;
    _sprite.setTexture(_texture);
    _sprite.setPosition(0,0);
}//2

void Background::update(){}

void Background::draw(sf::RenderTarget& window){
    window.draw(_sprite);
}
