#include "button.h"

Button::Button(string path){
    cout << "init!" << endl;
    _clicks = 0;
    _state = State::released;
    if(!_texture.loadFromFile(path)) cerr << "failed to load button texture!!" << endl;
    setTexture(_texture);
    _xSize = _texture.getSize().x;
    _ySize = _texture.getSize().y/3;
    setTextureRect(sf::IntRect(0,_ySize*_state,_xSize,_ySize));
}

void Button::handleMouseEvent(sf::Event& event){
   //cout << "event state = " << _state << endl;
        switch (event.type){
            case (sf::Event::MouseButtonPressed):
                if(_state == State::active) _state = State::pressed;
            break;

            case (sf::Event::MouseButtonReleased):
                if(_state == State::pressed){
                    _state = State::active;
                    ++_clicks;
                    cout << "Click!" << _clicks << endl;
                }
            break;

        default:
            break;
        }
        //cout << "event state = " << _state << endl;

}

void Button::update(sf::Vector2i mousePosition){
    //cout << "state = " << _state << endl;
    if(!inside(mousePosition)) _state = 0;
    else if (_state == State::released) _state = 1;
    //cout << "state = " << _state << endl;
    setTextureRect(sf::IntRect(0,_ySize*_state,_xSize,_ySize));
}


bool Button::inside(sf::Vector2i position){
    sf::FloatRect boundingBox = getGlobalBounds();
    if (boundingBox.contains(sf::Vector2f(position.x, position.y))) return true;
    //cout << "outside!" << endl;
    return false;
}

int Button::getClicks(){

    int c = _clicks;
    //cout << "popping clicks " << c << endl;
    _clicks = 0;
    //cout << "popclicks = " << _clicks << endl;
    return c;
}
