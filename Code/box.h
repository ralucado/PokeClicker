#ifndef BOX_H
#define BOX_H

#include "utils.h"
#include "berrybox.h"
#include "pokemon.h"
#include "levelbar.h"
#include "emotion.h"

class Box{

public:
    bool isFree();
    bool canFeed(int berryClicks);
    int buyBerry();
    void update(int clicks, int berryClicks, int numPokemons, float deltaTime);
    void draw(sf::RenderTarget& window);
    void addPokemon(int id, int targetClicks);
    Box(sf::Texture &pokemonTexture, sf::Texture &shinyTexture, sf::Texture &eggTexture, int posX, int posY);
    stack<int>& getStack();
    
private:
    bool _free;

    int _id;
    int _newClicks;
    int _numPokemons;
    int _posX, _posY;
    int _targetClicks;
    int _pokemonClicks;
    int _newBerryClicks;

    float _timeElapsed;
    float _textTimePassed;
    float _emotionTimePassed;
    float _targetEmotionTime;

    Pokemon _pokemon;
    stack<int> _finished;
    sf::Sprite _sprite;
    LevelBar _berryBar;
    LevelBar _healthBar;
    BerryBox _berryBox;
    sf::Texture& _eggTexture;
    sf::Texture& _pokemonTexture;
    sf::Texture& _shinyTexture;
    sf::Font _font;
    list<sf::Text> _texts;
    Emotion _emotion;
    sf::SoundBuffer _levelUpBuf;
    sf::SoundBuffer _finishedBuf;
    sf::Sound _sound;
    void _freeSlot();
    void _setPokemon();
    void _evolve();
    void _addText();
    void _updateTexts();
    void _updateEmotion(float deltaTime);
    void _setEmotion(Emotions::myEmotion emotion);
};

#endif // BOX_H
