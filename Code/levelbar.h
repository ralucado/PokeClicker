#ifndef LEVELBAR_H
#define LEVELBAR_H

#include "utils.h"

class LevelBar{
public:
    LevelBar();
    LevelBar(string ePath, string fPath,int posX,int posY);
    void setParameters(string ePath, string fPath,int posX,int posY);
    void update(int percentage);
    void draw(sf::RenderTarget& window);
    int getLevel();

private:
    int _percentage;
    int _posX;
    int _posY;
    sf::Texture _textureEmpty;
    sf::Texture _textureFull;
    sf::Sprite _spriteEmpty;
    sf::Sprite _spriteFull;
};

#endif // LEVELBAR_H
