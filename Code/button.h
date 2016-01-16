#ifndef BUTTON_H
#define BUTTON_H

#include "utils.h"

class Button : sf::Sprite{

public:
    Button(string path);

    void handleEvent(sf::Event event);


private:
    sf::Texture _texture;

};

#endif // BUTTON_H
