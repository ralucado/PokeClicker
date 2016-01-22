#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "utils.h"

class Background{

public:
    Background(std::string path);
    void update();
    void draw(sf::RenderTarget& window);

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
};

#endif // BACKGROUND_H
