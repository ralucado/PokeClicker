#ifndef BERRYBOX_H
#define BERRYBOX_H

#include "utils.h"

class BerryBox : public sf::Sprite{

public:

    BerryBox();
    void setParameters(string path, int xBerries, int yBerries, int xPos, int yPos);
    void draw(sf::RenderTarget& window);
    int size();
    bool isFull();
    void addBerry();

private:
    int _xBerries, _yBerries, _xPos, _yPos;
    sf::Texture _texture;
    vector<sf::Sprite> _sprites;
};

#endif // BERRYBOX_H
