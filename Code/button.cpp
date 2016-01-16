#include "button.h"

Button::Button(string path){
    if(!_texture.loadFromFile(path)) cerr << "failed to load button texture!!" << endl;
    setTexture(_texture);
    setTextureRect(sf::IntRect(0,0,151,151));
}

void Button::Button(sf::Event event){
    switch (event.type){
        case (sf::Event::MouseButtonPressed):

    }
}
