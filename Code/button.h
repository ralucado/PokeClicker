#ifndef BUTTON_H
#define BUTTON_H

#include "utils.h"

class Button : public sf::Sprite{

public:
    Button(string path);
    void turnOn();
    void turnOff();
    bool isOn();
    int getClicks();
    void handleMouseEvent(sf::Event& event);
    void update(sf::Vector2i mousePosition);
private:

    int _xSize;
    int _ySize;
    int _clicks;
    int _state;
    sf::Texture _texture;

    bool inside(sf::Vector2i position);
};

#endif // BUTTON_H
