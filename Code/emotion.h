#ifndef EMOTION_H
#define EMOTION_H

#include "utils.h"

class Emotion
{
public:
    Emotion();
    void setEmotion(Emotions::myEmotion emotion);
    void setParameters(string path, int posX, int posY);
    void setPosition(int posX, int posY);

    bool isOn();
    void turnOff();
    void update(float deltaTime);
    void draw(sf::RenderTarget& window);

private:
    bool _active;

    int _posX, _posY;
    int _xSize, _ySize;
    int _frame;

    float _timer;
    float _deltaTime;
    const float _duration = 2;
    const float _frameTime = 0.3;


    Emotions::myEmotion _emotion;
    sf::Texture _texture;
    sf::Sprite _sprite;

    void _updateSprite();
};

#endif // EMOTION_H
