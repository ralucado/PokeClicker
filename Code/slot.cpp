#include "slot.h"

Slot::Slot(sf::Texture& pokemonTexture, sf::Texture& eggTexture, int posX, int posY) : _eggTexture(eggTexture), _pokemonTexture(pokemonTexture){
    _free = true;
    _id = -1;
    _sprite.setPosition(posX,posY);
    _healthBar = LevelBar("Resources/Images/lvlbarE.png","Resources/Images/lvlbarF.png",posX+253,posY);
    _berryBar = LevelBar("Resources/Images/berrybarE.png","Resources/Images/berrybarF.png",posX+253,posY + 253);
}

bool Slot::isFree(){
    return _free;
}
